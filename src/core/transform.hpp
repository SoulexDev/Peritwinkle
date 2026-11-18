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
			void set_position(glm::vec3 position);
			void set_rotation(glm::quat rotation);
			void set_scale   (glm::vec3 scale);
			void set_dirty();

			glm::vec3 get_position();
			glm::quat get_rotation();
			glm::vec3 get_scale();
			glm::mat4 get_matrix();
		private:
			glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
			glm::quat rotation = glm::quat(glm::vec3(0.0f, 0.0f, 0.0f));
			glm::vec3 scale    = glm::vec3(1.0f, 1.0f, 1.0f);
			glm::mat4 transformMat;
			bool dirty;
		};
	}
}

#endif
