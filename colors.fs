#version 330 core

out vec4 f_color;

in vec3 f_normal;
in vec3 f_position;

uniform vec3 light_position;
uniform vec3 view_position;
uniform vec3 object_color;
uniform vec3 light_color;

void main() {

    float ambient_strength = 0.1;
    vec3 ambient = ambient_strength * light_color;
    vec3 unitNormal = normalize(f_normal);

    vec3 normal = normalize(f_normal);
    vec3 light_direction = normalize(light_position - f_position);
    float difference = max(dot(unitNormal, light_direction), 0.0);
    vec3 diffuse = difference * light_color;

    vec3 result = (ambient + diffuse) * object_color;
    f_color = vec4(result, 1.0);

}