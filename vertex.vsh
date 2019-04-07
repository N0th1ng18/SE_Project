#version 100
attribute highp vec3 position;

uniform highp mat4 projectionMatrix;
uniform highp mat4 viewMatrix;
uniform highp mat4 transformationMatrix;

void main(void)
{
    gl_Position = projectionMatrix * viewMatrix * transformationMatrix * vec4(position, 1.0);
}
