#include "object.hpp"

namespace Peritwinkle {
	namespace Core {
		Object::Object() {

		}
		Object::Object(std::string name, Peritwinkle::Graphics::Mesh mesh) {
			this->name = name;
			this->mesh = mesh;
			transform = Transform();
		}
		void Object::draw_object(Camera& camera) {
			mesh.material.use();

			mesh.material.set_mat4("model", transform.get_matrix());
			mesh.material.set_mat4("view", camera.viewMatrix);
			mesh.material.set_mat4("proj", camera.projMatrix);

			mesh.vertexBuffer.use();

			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}
}