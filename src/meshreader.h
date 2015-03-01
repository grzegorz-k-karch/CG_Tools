#ifndef MESHREADER_H
#define MESHREADER_H

#include <string>
#include <QVector>
#include <qopengl.h>

class MeshReader
{
public:
    MeshReader();   
    virtual ~MeshReader();
    void SetFilename(std::string name) { m_filename = name; }
    virtual void ReadObject(QVector<GLfloat> &vertices,
                            QVector<GLfloat> &normals,
                            QVector<GLfloat> &colors,
                            QVector<GLuint> &indices) = 0;
protected:
    std::string m_filename;
};

#endif // MESHREADER_H
