#version 400

uniform mat4 u_mvpMatrix;

vec4 supVect;

layout(location=0) in vec4 in_Position;
layout(location=1) in vec4 in_Color;
out vec4 ex_Color;

void main(void)
{
	gl_Position = u_mvpMatrix * in_Position;
	ex_Color = in_Color;
}