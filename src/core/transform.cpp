#include "transform.hpp"

namespace Peritwinkle {
	namespace Core {
		//setters
		void Transform::set_position(glm::vec3 position) {
			this->position = position;
			set_dirty();
		}
		void Transform::set_rotation(glm::quat rotation) {
			this->rotation = rotation;
			set_dirty();
		}
		void Transform::set_scale(glm::vec3 scale) {
			this->scale = scale;
			set_dirty();
		}
		void Transform::set_dirty() {
			dirty = true;
		}

		//getters
		glm::vec3 Transform::get_position() {
			return position;
		}
		glm::quat Transform::get_rotation() {
			return rotation;
		}
		glm::vec3 Transform::get_scale() {
			return scale;
		}
		glm::mat4 Transform::get_matrix() {
			if (dirty) {
				transformMat = glm::mat4(1.0f);
				transformMat = glm::translate(transformMat, position);
				transformMat = transformMat * glm::mat4_cast(rotation);
				transformMat = glm::scale(transformMat, scale);

				dirty = false;
			}

			return transformMat;
		}
	}
}