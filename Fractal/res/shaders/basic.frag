#version 330 core

layout(location = 0) out vec4 color;
layout(location = 1) out vec4 position;


in DATA
{
	vec4 position;
	vec4 color;
} fs_in;

uniform vec4 u_Color;
uniform vec4 u_LightPos;

void main()
{
	float intensity = 1.0f / length(fs_in.position - u_LightPos) * 1.2f;
	//color = u_Color * intensity;
	color = fs_in.color * intensity;
};
