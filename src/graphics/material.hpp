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
			void assign_abledo();
			void assign_normal();
			void assign_specular();
			void assign_emission();
			void set_color();
			void set_glossiness(float glossiness);
		};
	}
}

#endif