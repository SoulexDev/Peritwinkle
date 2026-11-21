#version 460 core

out vec4 FragColor;

in vec3 fNorm;
in vec2 fUv;
in vec4 fCol;

uniform sampler2D albedo;
uniform bool albedoValid;
uniform sampler2D normal;
uniform bool normalValid;
uniform sampler2D specular;
uniform bool specularValid;
uniform sampler2D emission;
uniform bool emissionValid;

void main() {
  vec3 lightDir = normalize(vec3(1.7, 1.5, -1.0));
  vec3 norm = normalize(fNorm);

  float nl = dot(lightDir, norm) * 0.5 + 0.5;
  nl *= nl;

  vec3 albedoTex = texture(albedo, fUv).rgb;

  if (!albedoValid) {
    albedoTex = vec3(1.0);
  }
  FragColor = vec4(albedoTex, 1.0) * nl;
}