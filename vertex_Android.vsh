#version 100
#ifdef GL_ES
precision mediump float;
#endif

attribute vec3 position;
attribute vec2 texCoords;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform mat4 transformationMatrix;

varying vec2 texCoords_FS;

void main(void)
{
    gl_Position = projectionMatrix * viewMatrix * transformationMatrix * vec4(position, 1.0);

    texCoords_FS = texCoords;
}
