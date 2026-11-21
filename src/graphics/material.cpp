#include "material.hpp"
#include <glm/gtc/type_ptr.hpp>

namespace Peritwinkle {
	namespace Graphics {
		Material::Material() {
			this->glossiness = 1.0f;
			this->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		}
		Material::Material(Shader& shader) {
			this->shader = shader;
			this->glossiness = 1.0f;
			this->color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
		}
		void Material::use() {
			//TODO: implement textures
			shader.use();
			unsigned int texIndex = 0;

			if (albedo.valid) {
				albedo.bind(texIndex);
				set_texture("albedo", texIndex);
			}
			set_bool("albedoValid", albedo.valid);
			texIndex++;

			if (normal.valid) {
				normal.bind(texIndex);
				set_texture("normal", texIndex);
			}
			set_bool("normalValid", normal.valid);
			texIndex++;

			if (specular.valid) {
				specular.bind(texIndex);
				set_texture("specular", texIndex);
			}
			set_bool("specularValid", specular.valid);
			texIndex++;

			if (emission.valid) {
				emission.bind(texIndex);
				set_texture("emission", texIndex);
			}
			set_bool("emissionValid", emission.valid);
		}
		void Material::assign_abledo(Texture& texture) {
			albedo = texture;
		}
		void Material::assign_normal(Texture& texture) {
			normal = texture;
		}
		void Material::assign_specular(Texture& texture) {
			specular = texture;
		}
		void Material::assign_emission(Texture& texture) {
			emission = texture;
		}
		void Material::set_glossiness(float glossiness) {
			this->glossiness = glossiness;
		}
		void Material::set_color(glm::vec4 color) {
			this->color = color;
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
		void Material::set_bool(const char* name, bool value) {
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