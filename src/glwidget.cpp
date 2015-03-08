#include "glwidget.h"
#include "helper_glsl.h"
#include "lightcontrol.h"
#include <iostream>
#include <string>
#include <fstream>
#include <QString>
#include <QMouseEvent>


GLWidget::GLWidget(QWidget *parent) :
    QOpenGLWidget(parent),
    m_vertexArray(this),
    m_vertexBuffer(QOpenGLBuffer::VertexBuffer),
    m_normalBuffer(QOpenGLBuffer::VertexBuffer),
    m_colorBuffer(QOpenGLBuffer::VertexBuffer),
    m_indexBuffer(QOpenGLBuffer::IndexBuffer)
{
    m_mesh = new Mesh;
    m_lightControl = new LightControl;

    m_zTrans = -3.0f;
    m_angle = 0.0;
}

GLWidget::~GLWidget()
{
    delete m_mesh;
    delete m_lightControl;
}

void GLWidget::initializeVertexArray()
{
    m_vertexArray.create();
    m_vertexBuffer.create();
    m_normalBuffer.create();
    m_colorBuffer.create();
    m_indexBuffer.create();

    m_vertexArray.bind();

    m_vertexBuffer.bind();
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, 0);

    m_normalBuffer.bind();
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 0, 0);

    m_colorBuffer.bind();
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, 0, 0);

    m_indexBuffer.bind();

    m_vertexArray.release();
}

const QString LoadShaderText(const std::string filename)
{
  QString shaderText;
  std::ifstream file(filename.c_str());
  std::string line;

  if (file.good()) {
    // read the shader file line by line
    while (getline(file, line)) {
      shaderText += line.c_str();
      shaderText += '\n';
    }
  }
  return shaderText;
}

void GLWidget::loadBuffer(QOpenGLBuffer &buffer,
                          const void *data,
                          const int size)
{
    buffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    buffer.bind();
    buffer.allocate(data, size);
    buffer.release();
}


void GLWidget::loadBuffers(const QVector<GLfloat> &vertex_data,
                           const QVector<GLfloat> &normal_data,
                           const QVector<GLfloat> &color_data,
                           const QVector<GLuint> &index_data)
{
    loadBuffer(m_vertexBuffer, vertex_data.constData(), vertex_data.size()*sizeof(GLfloat));
    loadBuffer(m_normalBuffer, normal_data.constData(), normal_data.size()*sizeof(GLfloat));
    loadBuffer(m_colorBuffer, color_data.constData(), color_data.size()*sizeof(GLfloat));
    loadBuffer(m_indexBuffer, index_data.constData(), index_data.size()*sizeof(GLuint));
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0, 0, 0, 0);

    std::string baseDir = "../src/";
    m_program.addShaderFromSourceCode(QOpenGLShader::Vertex,
                                      LoadShaderText(baseDir+"simple-vert.glsl"));
    m_program.addShaderFromSourceCode(QOpenGLShader::Fragment,
                                      LoadShaderText(baseDir+"simple-frag.glsl"));
    m_program.link();

    initializeVertexArray();
    loadBuffers(m_mesh->getVertexData(),
                m_mesh->getNormalData(),
                m_mesh->getColorData(),
                m_mesh->getIndexData());
}

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    m_mouseLastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        QVector2D diff = QVector2D(event->pos() - m_mouseLastPos);
        QVector3D n = QVector3D(diff.y(), diff.x(), 0.0).normalized();
        rotationAxis = n.normalized();
        m_angle = diff.length() / 10.0;
    } else if (event->buttons() & Qt::RightButton) {
        int dy = event->y() - m_mouseLastPos.y();
        m_zTrans += dy*0.025f;
    }

    m_mouseLastPos = event->pos();
    update();
}

void GLWidget::resizeGL(int width, int height)
{
    m_projMatrix.setToIdentity();
    m_projMatrix.perspective(45.0f, GLfloat(width)/height, 0.01f, 100.0f);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    rotation = QQuaternion::fromAxisAndAngle(rotationAxis, m_angle);
    m_worldMatrix.rotate(rotation);
    m_viewMatrix.setToIdentity();
    m_viewMatrix.translate(0.0f,0.0f,m_zTrans);
    QMatrix4x4 normalMatrix = (m_viewMatrix*m_worldMatrix).inverted().transposed();

    m_program.bind();
    m_program.setUniformValue(m_program.uniformLocation("projMat"), m_projMatrix);
    m_program.setUniformValue(m_program.uniformLocation("viewMat"), m_viewMatrix);
    m_program.setUniformValue(m_program.uniformLocation("modelMat"), m_worldMatrix);
    m_program.setUniformValue(m_program.uniformLocation("normalMat"), normalMatrix);

    m_lightControl->SetUniformValues(m_program);

    m_vertexArray.bind();
    glDrawElements(GL_TRIANGLES, m_mesh->getIndexData().size(),
                   GL_UNSIGNED_INT, 0);
    m_vertexArray.release();
    m_program.release();
}
