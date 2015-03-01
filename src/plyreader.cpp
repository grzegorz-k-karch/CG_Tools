#include "plyreader.h"
#include "ply.h"
#include <QVector3D>
#include <QVector>
#include <iostream>
#include <cstddef>
#include <map>
#include "process_mesh.h"

PlyReader::PlyReader()
{

}

PlyReader::~PlyReader()
{

}

void PlyReader::ReadObject(QVector<GLfloat> &vertices,
                           QVector<GLfloat> &normals,
                           QVector<GLfloat> &colors,
                           QVector<GLuint> &indices)
{
    PlyProperty vert_props[] = { /* list of property information for a vertex */
                                 {"x", PLY_FLOAT, PLY_FLOAT, 0, 0, 0, 0, 0},
                                 {"y", PLY_FLOAT, PLY_FLOAT, 4, 0, 0, 0, 0},
                                 {"z", PLY_FLOAT, PLY_FLOAT, 8, 0, 0, 0, 0},
                               };
    /* list of property information for a vertex */
    PlyProperty face_props[] = {{"vertex_indices", PLY_INT, PLY_INT, offsetof(polygon_t,indices),
                                 1, PLY_UCHAR, PLY_UCHAR, offsetof(polygon_t,nindices)}};

    PlyFile *ply;
    int nelems;
    char **elist;
    int file_type;
    float version;
    int nprops;
    int num_elems;
    PlyProperty **plist;
    char *elem_name;
    bool vertices_aval = false;
    bool normals_aval = false;
    bool colors_aval = false;
    bool indices_aval = false;

    /* open a PLY file for reading */
    ply = ply_open_for_reading(m_filename.c_str(), &nelems, &elist, &file_type, &version);



    /* go through each kind of element that we learned is in the file */
    /* and read them */
    for (int i = 0; i < nelems; i++) {

        /* get the description of the first element */
        elem_name = elist[i];
        plist = ply_get_element_description (ply, elem_name, &num_elems, &nprops);

        /* if we're on vertex elements, read them in */
        if (equal_strings ("vertex", elem_name)) {

            vertices_aval = true;

            ply_get_property (ply, elem_name, &vert_props[0]);
            ply_get_property (ply, elem_name, &vert_props[1]);
            ply_get_property (ply, elem_name, &vert_props[2]);

            for (int j = 0; j < num_elems; j++) {

                /* grab and element from the file */
                float vertex[3];
                ply_get_element (ply, (void *) vertex);
                vertices.push_back(vertex[0]);
                vertices.push_back(vertex[1]);
                vertices.push_back(vertex[2]);
                vertices.push_back(1.0f);
            }
        }
        /* if we're on face elements, read them in */
        if (equal_strings ("face", elem_name)) {

            indices_aval = true;
            ply_get_property (ply, elem_name, &face_props[0]);

            for (int j = 0; j < num_elems; j++) {

                polygon_t polygon;
                ply_get_element (ply, (void*)&polygon);

                for (int k = 0; k < polygon.nindices; k++) {
                    indices.push_back(polygon.indices[k]);
                }
            }
        }
    }
    ply_close (ply);

    if (vertices_aval == false || indices_aval == false) {
        std::cerr << "Ply file is corrupt?" << std::endl;
        return;
    }

    std::vector<float> vertices_tmp;
    std::vector<unsigned> indices_tmp;
    std::map<unsigned,unsigned> merge_map;
    mergeVertices(vertices.toStdVector(),indices.toStdVector(),4,
                  vertices_tmp,indices_tmp,merge_map);

    vertices = QVector<float>::fromStdVector(vertices_tmp);
    indices = QVector<unsigned>::fromStdVector(indices_tmp);

    if (!colors_aval) {
        for (int i = 0; i < vertices.size(); ++i) {
            colors.push_back(1.0f);
        }
    }
    if (!normals_aval) {
        for (int i = 0; i < vertices.size()/4; ++i) {
            normals.push_back(1.0f);
            normals.push_back(0.0f);
            normals.push_back(0.0f);
            normals.push_back(0.0f);
        }
        // todo : compute normals
        std::vector<float> normals_tmp;
        computeNormals(vertices.toStdVector(), indices.toStdVector(), normals_tmp);
        normals = QVector<float>::fromStdVector(normals_tmp);
    }
}
