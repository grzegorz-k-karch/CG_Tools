#version 410

uniform mat4 projMat;
uniform mat4 viewMat;
uniform mat4 modelMat;
uniform mat4 normalMat;

layout (location = 0) in vec4 in_vertex;
layout (location = 1) in vec4 in_normal;
layout (location = 2) in vec4 in_color;

layout (location = 0) out vec4 out_color;
layout (location = 1) out vec4 out_normal;
layout (location = 2) out vec4 out_lightDir;


void main(void)
{
    out_color = in_color;

    vec4 mvPos = viewMat*modelMat*in_vertex;
    out_normal = normalMat*in_normal;

    vec4 lightPos = vec4(10.0,10.0,10.0,1.0);
    out_lightDir = vec4(normalize(lightPos.xyz - mvPos.xyz),0.0);

    gl_Position = projMat*mvPos;
}

