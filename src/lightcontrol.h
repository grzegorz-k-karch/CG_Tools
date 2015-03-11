#ifndef LIGHTCONTROL_H
#define LIGHTCONTROL_H

#include <QOpenGLFunctions>
#include <QVector4D>
#include <QOpenGLShaderProgram>
#include <QColor>
#include <QWidget>

class LightControl : public QWidget
{
    Q_OBJECT
public:
    LightControl(QWidget *parent = 0);
    ~LightControl();
    void SetUniformValues(QOpenGLShaderProgram &m_program) const;
    QVector4D m_lightColor;
public slots:
    void setLightColor(const QColor &color);
private:
    GLfloat m_k_ambient;
    GLfloat m_k_diffuse;
    GLfloat m_k_specular;
    GLfloat m_speculat_exp;

    QVector4D m_lightPos;
};

#endif // LIGHTCONTROL_H
