attribute vec4 vPosition;
attribute vec4 inColor;

uniform mat4 MVP_matrix;

varying vec4 fragColor;

void main()
{
    fragColor = inColor;

	gl_Position = MVP_matrix * vPosition;

}
