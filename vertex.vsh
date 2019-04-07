in vec3 position;

uniform highp mat4 orthoMatrix;
uniform highp mat4 viewMatrix;
uniform highp mat4 transformationMatrix;

void main(void)
{
    gl_Position = orthoMatrix * viewMatrix * transformationMatrix * vec4(position, 1.0);
}
