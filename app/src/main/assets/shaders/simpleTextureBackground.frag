precision mediump float;

uniform sampler2D texture1;

varying vec2 textureCoord;

void main()
{

	gl_FragColor = texture2D(texture1, textureCoord);
}
