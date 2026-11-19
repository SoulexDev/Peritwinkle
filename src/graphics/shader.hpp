#ifndef PERITWINKLE_SHADER_H
#define PERITWINKLE_SHADER_H

#include <glad/glad.h>
#include <vector>
#include <string>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

namespace Peritwinkle {
	namespace Graphics {
		struct Shader {
		public:
			GLuint shaderProgram;
			bool valid;

			Shader();
			Shader(const char* vertexShaderPath, const char* fragmentShaderPath, std::vector<std::string> &errorLogs);
			void use();
		private:
			static bool create_shader(std::string source, GLuint& shader, GLenum shaderType, std::vector<std::string>& errorLogs);
		};
	}
}

#endif