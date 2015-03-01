#ifndef HELPER_GLSL_H
#define HELPER_GLSL_H

#include <string>
#include <QOpenGLFunctions>

GLuint CreateShaderProgram(const std::string vertShaderFileName,
                           const std::string fragShaderFileName);

#endif // HELPER_GLSL_H

