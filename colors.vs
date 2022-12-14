#version 330 core
layout (location = 0) in vec3 a_position;
layout (location = 1) in vec3 a_normal;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_projection;

out vec3 f_position;
out vec3 f_normal;

void main()
{
    f_position = vec3(u_model * vec4(a_position, 1.0));
    f_normal = a_normal;

	gl_Position = u_projection * u_view * vec4(a_position, 1.0);
}