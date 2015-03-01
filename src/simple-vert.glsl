#version 410

uniform mat4 projMat;
uniform mat4 viewMat;
uniform mat4 modelMat;
uniform mat4 normalMat;
uniform vec4 lightPos;

layout (location = 0) in vec4 in_vertex;
layout (location = 1) in vec4 in_normal;
layout (location = 2) in vec4 in_color;

layout (location = 0) out vec4 out_color;
layout (location = 1) out vec4 out_normal;
layout (location = 2) out vec4 out_lightDir;


void main(void)
{
    vec3 lightPos = vec3(10.0,10.0,10.0);

    out_color = in_color;
    out_normal = normalMat*in_normal;

    vec4 mvPos = viewMat*modelMat*in_vertex;
    gl_Position = projMat*mvPos;

    out_lightDir = vec4(normalize(lightPos.xyz - mvPos.xyz),0.0);
}

