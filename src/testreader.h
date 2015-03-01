#ifndef TESTREADER_H
#define TESTREADER_H

#include "meshreader.h"
#include <string>
#include <QVector>
#include <qopengl.h>

class TestReader : public MeshReader
{
public:
    TestReader();
    ~TestReader();
    void ReadObject(QVector<GLfloat> &vertices,
                    QVector<GLfloat> &normals,
                    QVector<GLfloat> &colors,
                    QVector<GLuint> &indices);
};

#endif // TESTREADER_H
