#include "mesh.h"
#include "plyreader.h"
#include "testreader.h"
#include <QVector4D>
#include <QVector>
#include <string>

Mesh::Mesh(QVector<GLfloat> &vertices,
           QVector<GLfloat> &normals,
           QVector<GLfloat> &colors,
           QVector<GLuint> &indices)
{
    Init(vertices, normals, colors, indices);
}

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}

void Mesh::Init(QVector<GLfloat> &vertices,
                QVector<GLfloat> &normals,
                QVector<GLfloat> &colors,
                QVector<GLuint> &indices)
{
    m_vertices = vertices;
    m_normals = normals;
    m_colors = colors;
    m_indices = indices;
    computeBBox();
}

void Mesh::clearMesh()
{
    m_vertices.clear();
    m_normals.clear();
    m_colors.clear();
    m_indices.clear();
}

void Mesh::computeBBox()
{
    // get mesh bounding box
    GLfloat maxval = std::numeric_limits<GLfloat>::max();
    GLfloat minval = -maxval;
    m_bbox = {maxval, minval, maxval, minval, maxval, minval};

    unsigned int comp = 0;
    for (const GLfloat &vertex_comp : m_vertices) {

        if (comp < 3) {
            if (m_bbox[comp*2+0] > vertex_comp)  m_bbox[comp*2+0] = vertex_comp;
            if (m_bbox[comp*2+1] < vertex_comp)  m_bbox[comp*2+1] = vertex_comp;
        }
        ++comp;
        comp = comp & 3;
    }
}
