#include "transform.hpp"

namespace Peritwinkle {
	namespace Core {
		Transform::Transform() {
			position = glm::vec3(0.0f, 0.0f, 0.0f);
			rotation = glm::quat(glm::vec3(0.0f, 0.0f, 0.0f));
			scale =    glm::vec3(1.0f, 1.0f, 1.0f);

			set_dirty();
		}
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
		glm::vec3 Transform::get_forward() {
			return rotation * glm::vec3(0.0f, 0.0f, 1.0f);
		}
		glm::vec3 Transform::get_right() {
			return rotation * glm::vec3(1.0f, 0.0f, 0.0f);
		}
		glm::vec3 Transform::get_up() {
			return rotation * glm::vec3(0.0f, 1.0f, 0.0f);
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