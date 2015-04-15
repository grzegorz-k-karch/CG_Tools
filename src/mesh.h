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
    Mesh();
    ~Mesh();

    const QVector<GLfloat> &getVertexData() const { return m_vertices; }
    const QVector<GLfloat> &getNormalData() const { return m_normals; }
    const QVector<GLfloat> &getColorData() const { return m_colors; }
    const QVector<GLuint> &getIndexData() const { return m_indices; }

    void clearMesh();

public slots:
    void LoadMesh(QString fileName);

private:

    QVector<GLfloat> m_vertices;
    QVector<GLfloat> m_normals;
    QVector<GLfloat> m_colors;
    QVector<GLuint> m_indices;

    MeshReader *m_reader;
};

#endif // MESH_H
