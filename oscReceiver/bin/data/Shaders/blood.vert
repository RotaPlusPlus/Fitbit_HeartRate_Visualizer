//#version 150
#version 120

uniform mat4 modelViewProjectionMatrix;
varying vec4 position;
//in vec4 position;

void main() {
    gl_Position = ftransform();
}

