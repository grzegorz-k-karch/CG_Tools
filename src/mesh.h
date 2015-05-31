#ifndef MESH_H
#define MESH_H

#include <qopengl.h>
#include <QVector>
#include <QVector3D>
#include <QString>
#include "meshreader.h"

class Mesh
{
public:
    Mesh(QVector<GLfloat> &vertices,
         QVector<GLfloat> &normals,
         QVector<GLfloat> &colors,
         QVector<GLuint> &indices);
    Mesh();
    ~Mesh();

    void Init(QVector<GLfloat> &vertices,
              QVector<GLfloat> &normals,
              QVector<GLfloat> &colors,
              QVector<GLuint> &indices);

    const QVector<GLfloat> &getVertexData() const { return m_vertices; }
    const QVector<GLfloat> &getNormalData() const { return m_normals; }
    const QVector<GLfloat> &getColorData() const { return m_colors; }
    const QVector<GLuint> &getIndexData() const { return m_indices; }

    const QVector<GLfloat> &GetBBox() const { return m_bbox; }

    void clearMesh();
    void computeBBox();

private:

    QVector<GLfloat> m_vertices;
    QVector<GLfloat> m_normals;
    QVector<GLfloat> m_colors;
    QVector<GLuint> m_indices;

    QVector<GLfloat> m_bbox;
};

#endif // MESH_H
