precision mediump float;

attribute vec4 inPosition;

uniform mat4 MVP_matrix;

void main()
{


	gl_Position = MVP_matrix * inPosition;// vec4(vec3(0.0), 1.0);
}
