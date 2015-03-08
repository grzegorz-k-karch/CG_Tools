#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>
#include <QVector4D>
#include <QMatrix4x4>
#include <QQuaternion>
#include <string>

#include "mesh.h"
#include "lightcontrol.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    GLWidget(QWidget *parent = 0);
    ~GLWidget();

    void loadBuffers(const QVector<GLfloat> &vertex_data,
                     const QVector<GLfloat> &normal_data,
                     const QVector<GLfloat> &color_data,
                     const QVector<GLuint> &index_data);
    void setLightControl(LightControl *lightControl) { m_lightControl = lightControl; }
protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int width, int height) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    GLuint CreateShaderProgram(const std::string vertShaderFileName,
                               const std::string fragShaderFileName);

private:
    void initializeVertexArray();
    void loadBuffer(QOpenGLBuffer &buffer,
                    const void *data,
                    const int size);
    void initBuffers();

    QOpenGLShaderProgram m_program;
    QOpenGLVertexArrayObject m_vertexArray;
    QOpenGLBuffer m_vertexBuffer;
    QOpenGLBuffer m_normalBuffer;
    QOpenGLBuffer m_colorBuffer;
    QOpenGLBuffer m_indexBuffer;

    QMatrix4x4 m_projMatrix;
    QMatrix4x4 m_viewMatrix;
    QMatrix4x4 m_worldMatrix;

    QPoint m_mouseLastPos;

    GLfloat m_zTrans;
    GLfloat m_xRot;
    GLfloat m_yRot;

    QVector3D rotationAxis;
    qreal m_angle;
    QQuaternion rotation;

    Mesh *m_mesh;
    LightControl *m_lightControl;
};

#endif // GLWIDGET_H
