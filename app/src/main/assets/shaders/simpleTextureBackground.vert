precision mediump float;

attribute vec4 inPosition;
attribute vec2 inTextureCoord;

uniform mat4 P_matrix;

varying vec2 textureCoord;

void main()
{
    textureCoord = vec2(inTextureCoord.x, 1.0 - inTextureCoord.y);

	gl_Position = P_matrix * inPosition;
}
