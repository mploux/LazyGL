#version 330

layout (location = 0) in vec3 in_position;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 viewProjectionMatrix;

void main()
{
	gl_Position = vec4(in_position, 1.0);
}
