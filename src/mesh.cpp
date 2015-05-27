#include "mesh.h"
#include "plyreader.h"
#include "testreader.h"
#include <QVector4D>
#include <QVector>
#include <string>

Mesh::Mesh()
{
    m_reader = new PlyReader();
//    m_reader->SetFilename("/home/karchgz/dev/meshes/torus.ply");
//    m_reader->SetFilename("/home/gkk/dev/meshes/torus.ply");
//    m_reader->ReadObject(m_vertices, m_normals, m_colors, m_indices);
}

Mesh::~Mesh()
{
    delete m_reader;
}

void Mesh::LoadMesh(QString fileName)
{    
    m_reader->SetFilename(fileName.toStdString());
    m_reader->ReadObject(m_vertices, m_normals,
                         m_colors, m_indices);

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

void Mesh::clearMesh()
{
    m_vertices.clear();
    m_normals.clear();
    m_colors.clear();
    m_indices.clear();
}
