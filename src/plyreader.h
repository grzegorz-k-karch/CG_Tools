#ifndef PLYREADER_H
#define PLYREADER_H

#include "ply.h"
#include "meshreader.h"
#include <string>
#include <QVector>
#include <qopengl.h>

class PlyReader : public MeshReader
{
public:
    PlyReader();
    ~PlyReader();
    void ReadObject(QVector<GLfloat> &vertices,
                    QVector<GLfloat> &normals,
                    QVector<GLfloat> &colors,
                    QVector<GLuint> &indices);
private:
    typedef struct {
        unsigned char nindices;
        int *indices;
    } polygon_t;
};

#endif // PLYREADER_H
