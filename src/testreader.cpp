#include "testreader.h"

TestReader::TestReader()
{

}

TestReader::~TestReader()
{

}

void TestReader::ReadObject(QVector<GLfloat> &vertices,
                            QVector<GLfloat> &normals,
                            QVector<GLfloat> &colors,
                            QVector<GLuint> &indices)
{
    vertices.push_back(-0.5f);
    vertices.push_back(-0.5f);
    vertices.push_back(-0.5f);
    vertices.push_back(1.0f);

    vertices.push_back( 0.5f);
    vertices.push_back(-0.5f);
    vertices.push_back(-0.5f);
    vertices.push_back(1.0f);

    vertices.push_back(-0.5f);
    vertices.push_back( 0.5f);
    vertices.push_back(-0.5f);
    vertices.push_back(1.0f);

    vertices.push_back(-0.5f);
    vertices.push_back(-0.5f);
    vertices.push_back( 0.5f);
    vertices.push_back(1.0f);

    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);

    indices.push_back(0);
    indices.push_back(2);
    indices.push_back(3);

    indices.push_back(0);
    indices.push_back(3);
    indices.push_back(1);

    indices.push_back(3);
    indices.push_back(2);
    indices.push_back(1);

    normals.push_back(0.0f);
    normals.push_back(0.0f);
    normals.push_back(0.0f);
    normals.push_back(0.0f);

    normals.push_back(1.0f);
    normals.push_back(0.0f);
    normals.push_back(0.0f);
    normals.push_back(0.0f);

    normals.push_back(0.0f);
    normals.push_back(1.0f);
    normals.push_back(0.0f);
    normals.push_back(0.0f);

    normals.push_back(0.0f);
    normals.push_back(0.0f);
    normals.push_back(1.0f);
    normals.push_back(0.0f);


    colors.push_back(0.0f);
    colors.push_back(0.0f);
    colors.push_back(0.0f);
    colors.push_back(1.0f);

    colors.push_back(1.0f);
    colors.push_back(0.0f);
    colors.push_back(0.0f);
    colors.push_back(1.0f);

    colors.push_back(0.0f);
    colors.push_back(1.0f);
    colors.push_back(0.0f);
    colors.push_back(1.0f);

    colors.push_back(0.0f);
    colors.push_back(0.0f);
    colors.push_back(1.0f);
    colors.push_back(1.0f);
}
