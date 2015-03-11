#include "mesh.h"
#include "plyreader.h"
#include "testreader.h"
#include <QVector4D>
#include <QVector>
#include <string>

Mesh::Mesh()
{
    m_reader = new PlyReader();
    m_reader->SetFilename("/home/karchgz/dev/meshes/torus.ply");
//    m_reader->SetFilename("/home/gkk/dev/meshes/torus.ply");
    m_reader->ReadObject(m_vertices, m_normals,
                         m_colors, m_indices);
}

Mesh::~Mesh()
{
    delete m_reader;
}

void Mesh::LoadMesh()
{
    m_reader->ReadObject(m_vertices, m_normals,
                         m_colors, m_indices);
}
