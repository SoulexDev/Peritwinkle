#ifndef PERITWINKLE_MATERIAL_H
#define PERITWINKLE_MATERIAL_H

#include "shader.hpp"

namespace Peritwinkle {
	namespace Graphics {
		struct Material {
		public:
			Shader shader;

			Material();
			Material(Shader shader);
			void use();

			//TODO: implement
			/*void assign_abledo();
			void assign_normal();
			void assign_specular();
			void assign_emission();
			void set_color();
			void set_glossiness(float glossiness);*/

			void set_float  (const char* name,	   float value);
			void set_integer(const char* name,		 int value);
			void set_texture(const char* name,		 int value);
			void set_vec2	(const char* name, glm::vec2 value);
			void set_vec3	(const char* name, glm::vec3 value);
			void set_vec4	(const char* name, glm::vec4 value);
			void set_mat4	(const char* name, glm::mat4 value);
		};
	}
}

#endif