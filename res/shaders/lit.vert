#version 460 core

layout(location = 0) in vec3 vPos;
layout(location = 1) in vec3 vNorm;
layout(location = 2) in vec2 vUv;
layout(location = 3) in vec4 vCol;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

out vec3 fNorm;
out vec2 fUv;
out vec4 fCol;

void main() {
  gl_Position = proj * view * model * vec4(vPos, 1.0);
  fNorm = vNorm;
  fUv = vUv;
  fCol = vCol;
}