#version 460 core

layout(location = 0) in vec3 vPos;
layout(location = 1) in vec3 vNorm;
layout(location = 2) in vec2 vUv;
layout(location = 3) in vec4 vCol;

out vec4 fCol;

void main() {
  gl_Position = vec4(vPos, 1.0);
  fCol = vCol;
}