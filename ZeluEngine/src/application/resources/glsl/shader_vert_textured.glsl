#version 400

uniform mat4 u_mvpMatrix;
uniform mat4 u_transformationMatrix;

vec4 supVect;

layout(location=0) in vec4 in_Position;
layout(location = 1) in vec2 a_texCoord;
out vec2 v_texCoord;

void main(void)
{
	supVect = u_transformationMatrix * in_Position;
	gl_Position = u_mvpMatrix * supVect;
	v_texCoord = a_texCoord;
}