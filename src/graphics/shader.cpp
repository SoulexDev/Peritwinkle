#include "shader.hpp"
#include "../util/file_read_util.hpp"
#include <format>

namespace Peritwinkle {
	namespace Graphics {
		Shader::Shader() {
			shaderProgram = 0;
			valid = false;
		}
		Shader::Shader(const char* vertexShaderPath, const char* fragmentShaderPath, std::vector<std::string> &errorLogs) {
			valid = true;
			GLuint vertexShader;
			GLuint fragmentShader;

			const char* vertexShaderRead = Utility::read_file(vertexShaderPath);
			const char* fragmentShaderRead = Utility::read_file(fragmentShaderPath);

			//create and compile shaders
			if (!create_shader(vertexShaderRead, vertexShader, GL_VERTEX_SHADER, errorLogs)) {
				valid = false;
				return;
			}

			if (!create_shader(fragmentShaderRead, fragmentShader, GL_FRAGMENT_SHADER, errorLogs)) {
				valid = false;
				return;
			}

			//create shader program
			shaderProgram = glCreateProgram();
			glAttachShader(shaderProgram, vertexShader);
			glAttachShader(shaderProgram, fragmentShader);
			glLinkProgram(shaderProgram);

			//check for errors
			int success;
			char infoLog[512];
			glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

			if (!success) {
				glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
				errorLogs.push_back(std::format("Shader compilation failed: {}", infoLog));
				valid = false;
			}

			//delete shaders, we dont need them
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
		}
		void Shader::use() {
			if (!valid)
				return;

			glUseProgram(shaderProgram);
		}
		bool Shader::create_shader(const char* source, GLuint &shader, GLenum shaderType, std::vector<std::string> &errorLogs) {
			shader = glCreateShader(GL_VERTEX_SHADER);
			glShaderSource(shader, 1, &source, NULL);
			glCompileShader(shader);

			int success;
			char infoLog[512];
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

			if (!success) {
				glGetShaderInfoLog(shader, 512, NULL, infoLog);
				errorLogs.push_back(std::format("Shader compilation failed: {}", infoLog));

				return false;
			}
			else
				return true;
		}
	}
}