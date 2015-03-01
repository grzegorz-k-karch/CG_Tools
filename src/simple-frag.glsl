#version 410

out vec4 out_color;

layout (location = 0) in vec4 in_color;
layout (location = 1) in vec4 in_normal;
layout (location = 2) in vec4 in_lightDir;

void main(void)
{
    vec4 lightColor = vec4(1.0);
    float k_a = 0.25;
    vec4 color = k_a*lightColor*in_color;

    float k_d = max(0.0, dot(normalize(in_normal.xyz), normalize(in_lightDir.xyz)));
    color += k_d*lightColor*in_color;

    vec3 R = normalize(reflect(-normalize(in_lightDir.xyz), normalize(in_normal.xyz)));
    float spec = max(0.0, dot(normalize(in_normal.xyz), R));

    if(k_d != 0) {
        float k_s = pow(spec, 128.0);
        color += k_s*lightColor;
    }
    out_color = color;
}

