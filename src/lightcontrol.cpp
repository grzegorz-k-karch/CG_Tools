#include "lightcontrol.h"

LightControl::LightControl()
{
    m_k_ambient = 0.25f;
    m_k_diffuse = 0.5f;
    m_k_specular = 0.25f;
    m_speculat_exp = 32.0f;
    m_lightColor = QVector4D(1.0f,1.0f,1.0f,1.0f);
    m_lightPos = QVector4D(10.0f,10.0f,10.0f,1.0f);
}

LightControl::~LightControl()
{

}

void LightControl::SetUniformValues(QOpenGLShaderProgram &m_program) const
{
    m_program.setUniformValue(m_program.uniformLocation("lightPos"), m_lightPos);
    m_program.setUniformValue(m_program.uniformLocation("lightColor"), m_lightColor);
    m_program.setUniformValue(m_program.uniformLocation("k_a"), m_k_ambient);
    m_program.setUniformValue(m_program.uniformLocation("k_d"), m_k_diffuse);
    m_program.setUniformValue(m_program.uniformLocation("k_s"), m_k_specular);
    m_program.setUniformValue(m_program.uniformLocation("spec_exp"), m_speculat_exp);
}
