#version 100

uniform sampler2D texture;

varying vec2 texCoords_FS;

void main(void)
{
    vec4 color = texture2D(texture, texCoords_FS);
    if(color.w < 0.1){
        discard;
    }
    gl_FragColor = color;
}
