#version 150

uniform mat4 modelViewProjectionMatrix;

in vec4 position;
in vec2 texcoord;
in vec4 color;

out vec2 texCoord;

void main() {
    texCoord = texcoord;
    gl_Position = modelViewProjectionMatrix * position;
}

