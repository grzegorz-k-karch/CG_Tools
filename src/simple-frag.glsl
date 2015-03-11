#version 410

uniform float k_a;
uniform float k_d;
uniform float k_s;
uniform float spec_exp;
uniform vec4 lightColor;

layout (location = 0) in vec4 in_color;
layout (location = 1) in vec4 in_normal;
layout (location = 2) in vec4 in_lightDir;

out vec4 out_color;

void main(void)
{
    vec3 N = normalize(in_normal.xyz);
    vec3 L = in_lightDir.xyz;

    vec4 color = k_a*lightColor*in_color;

    float diffuse = max(0.0, dot(N, L));
    color += k_d*diffuse*lightColor*in_color;

    vec3 R = -L + 2.0*dot(L,N)*N;
    float spec = max(0.0, dot(N, R));

    if(diffuse != 0) {
        float specular = pow(spec, 32.0);
        color += k_s*specular*lightColor;
    }
    out_color = color;
}

