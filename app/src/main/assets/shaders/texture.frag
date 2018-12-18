#version 200 core

in vec2 text_coord;

uniform sampler2D sampler_texture1;

void main()
{
	vec4 color = texture(sampler_texture1, text_coord);
	if(color.w < 0.1) discard; // transparent pisel. not come to Z buffer

	gl_FragColor = color;
}

