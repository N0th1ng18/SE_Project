#version 120

uniform sampler2D texture;

varying vec2 texCoords_FS;

void main(void)
{
    gl_FragColor = texture2D(texture, texCoords_FS);
}
