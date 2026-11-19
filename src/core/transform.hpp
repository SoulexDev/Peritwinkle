#ifndef PERITWINKLE_TRANSFORM_H
#define PERITWINKLE_TRANSFORM_H

#include <glm/vec3.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Peritwinkle {
	namespace Core {
		struct Transform {
		public:
			Transform();

			void set_position(glm::vec3 position);
			void set_rotation(glm::quat rotation);
			void set_scale   (glm::vec3 scale);
			void set_dirty();

			glm::vec3 get_position();
			glm::quat get_rotation();
			glm::vec3 get_scale();
			glm::mat4 get_matrix();

			glm::vec3 get_forward();
			glm::vec3 get_right();
			glm::vec3 get_up();
		private:
			glm::vec3 position;
			glm::quat rotation;
			glm::vec3 scale;
			glm::mat4 transformMat;
			bool dirty;
		};
	}
}

#endif
