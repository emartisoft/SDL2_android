precision mediump float;

attribute vec4 inPosition;
attribute vec4 inColor;

uniform mat4 MVP_matrix;

varying vec4 color;

void main()
{
    color = inColor;

	gl_Position = MVP_matrix * inPosition;

}
