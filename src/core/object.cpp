#include "object.hpp"

namespace Peritwinkle {
	namespace Core {
		Object::Object(Peritwinkle::Graphics::Mesh mesh) {
			this->mesh = mesh;
			transform = Transform();
		}
		void Object::draw_object(Camera& camera) {
			mesh.material.use();

			mesh.material.set_mat4("model", transform.get_matrix());
			mesh.material.set_mat4("view", camera.viewMatrix);
			mesh.material.set_mat4("proj", camera.projMatrix);

			mesh.vertexBuffer.use();
		}
	}
}