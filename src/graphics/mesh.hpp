#ifndef PERITWINKLE_MESH_H
#define PERITWINKLE_MESH_H

#include "vertex_buffer.hpp"
#include "material.hpp"
#include "../core/camera.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <vector>
#include <string>

namespace Peritwinkle {
	namespace Graphics {
		struct Mesh {
		public:
			VertexBuffer vertexBuffer;
			Material material;
			//Core::Object* objPtr;

			Mesh();
			Mesh(VertexBuffer vertexBuffer, Material& material);
			//Mesh();
			static std::vector<Mesh> load_model(const char* modelPath, Shader& shader, std::vector<std::string>& warningLogs);
		private:
			static void process_node(aiNode* node, const aiScene* scene, std::vector<Mesh>& meshes, Shader& shader, std::vector<std::string>& warningLogs);
			static Mesh process_mesh(aiMesh* mesh, const aiScene* scene, Shader& shader, std::vector<std::string>& warningLogs);
			static std::vector<Texture> load_material_textures(aiMaterial* mat, aiTextureType type, std::vector<std::string>& warningLogs);
		};
	}
}

#endif