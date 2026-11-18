#include "material.hpp"

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
		void Material::assign_abledo() {

		}
		void Material::assign_normal() {

		}
		void Material::assign_specular() {

		}
		void Material::assign_emission() {

		}
		void Material::set_color() {

		}
		void Material::set_glossiness(float glossiness) {

		}
	}
}