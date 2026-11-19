#include "material.hpp"
#include <glm/gtc/type_ptr.hpp>

namespace Peritwinkle {
	namespace Graphics {
		Material::Material() { }
		Material::Material(Shader shader) {
			this->shader = shader;
		}
		void Material::use() {
			//TODO: implement textures
			shader.use();
		}
		void Material::set_float(const char* name, float value) {
			int location = glGetUniformLocation(shader.shaderProgram, name);
			shader.use();
			glUniform1f(location, value);
		}
		void Material::set_integer(const char* name, int value) {
			int location = glGetUniformLocation(shader.shaderProgram, name);
			shader.use();
			glUniform1i(location, value);
		}
		void Material::set_texture(const char* name, int value) {
			int location = glGetUniformLocation(shader.shaderProgram, name);
			shader.use();
			glUniform1i(location, value);
		}
		void Material::set_vec2(const char* name, glm::vec2 value) {
			int location = glGetUniformLocation(shader.shaderProgram, name);
			shader.use();
			glUniform2f(location, value.x, value.y);
		}
		void Material::set_vec3(const char* name, glm::vec3 value) {
			int location = glGetUniformLocation(shader.shaderProgram, name);
			shader.use();
			glUniform3f(location, value.x, value.y, value.z);
		}
		void Material::set_vec4(const char* name, glm::vec4 value) {
			int location = glGetUniformLocation(shader.shaderProgram, name);
			shader.use();
			glUniform4f(location, value.x, value.y, value.z, value.w);
		}
		void Material::set_mat4(const char* name, glm::mat4 value) {
			int location = glGetUniformLocation(shader.shaderProgram, name);
			shader.use();
			glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
		}
	}
}