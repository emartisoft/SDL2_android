#version 200 core

layout(location = 0) in vec3 in_position;
layout(location = 1) in vec2 in_texture_coord;

out vec2 text_coord;

uniform mat4 P_matrix;

void main()
{
	text_coord = vec2(in_texture_coord.x, 1 - in_texture_coord.y) ;

	gl_Position = P_matrix * vec4(in_position, 1.0);

}