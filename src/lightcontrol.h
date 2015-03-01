#ifndef LIGHTCONTROL_H
#define LIGHTCONTROL_H

#include <QOpenGLFunctions>
#include <QVector4D>
#include <QOpenGLShaderProgram>

class LightControl
{
public:
    LightControl();
    ~LightControl();
    void SetUniformValues(QOpenGLShaderProgram &m_program) const;
private:
    GLfloat m_k_ambient;
    GLfloat m_k_diffuse;
    GLfloat m_k_specular;
    GLfloat m_speculat_exp;
    QVector4D m_lightColor;
    QVector4D m_lightPos;
};

#endif // LIGHTCONTROL_H
