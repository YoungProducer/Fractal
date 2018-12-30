#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;

out DATA
{
	vec4 position;
	vec4 color;
} vs_out;

uniform mat4 pr_matrix;
uniform mat4 vm_matrix = mat4(1.0f);
uniform mat4 ml_matrix = mat4(1.0f);

void main()
{
	gl_Position = pr_matrix * vm_matrix * ml_matrix * position;
	vs_out.position = ml_matrix * position;
	vs_out.color = color;
};