attribute vec3 vPosition;

uniform mat4 MVP_matrix;

void main()
{


	gl_Position = MVP_matrix * vec4(vPosition, 1.0);// vec4(vec3(0.0), 1.0);
}
