#include "mesh.hpp"
#include <format>

namespace Peritwinkle {
	namespace Graphics {
		Mesh::Mesh() {

		}
		Mesh::Mesh(VertexBuffer vertexBuffer, Material& material) {
			this->vertexBuffer = vertexBuffer;
			this->material = material;
		}
		std::vector<Mesh> Mesh::load_model(const char* modelPath, Shader& shader, std::vector<std::string>& warningLogs) {
			Assimp::Importer importer;
			const aiScene* scene = importer.ReadFile(modelPath, aiProcess_Triangulate);
			std::vector<Mesh> meshes;

			if (scene == NULL || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || scene->mRootNode == NULL) {
				warningLogs.push_back(importer.GetErrorString());
				return meshes;
			}

			process_node(scene->mRootNode, scene, meshes, shader, warningLogs);

			return meshes;
		}
		void Mesh::process_node(aiNode* node, const aiScene* scene, std::vector<Mesh>& meshes, Shader& shader, std::vector<std::string>& warningLogs) {
			for (unsigned int i = 0; i < node->mNumMeshes; i++) {
				aiMesh* mesh = scene->mMeshes[node->mMeshes[0]];
				meshes.push_back(process_mesh(mesh, scene, shader, warningLogs));
			}
			for (unsigned int i = 0; i < node->mNumChildren; i++) {
				process_node(node->mChildren[i], scene, meshes, shader, warningLogs);
			}
		}
		Mesh Mesh::process_mesh(aiMesh* mesh, const aiScene* scene, Shader& shader, std::vector<std::string>& warningLogs) {
			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;

			//process vertices
			for (unsigned int i = 0; i < mesh->mNumVertices; i++) {
				Vertex v;

				if (mesh->HasPositions()) {
					v.position.x = mesh->mVertices[i].x;
					v.position.y = mesh->mVertices[i].y;
					v.position.z = mesh->mVertices[i].z;
				}

				if (mesh->HasNormals()) {
					v.normal.x = mesh->mNormals[i].x;
					v.normal.y = mesh->mNormals[i].y;
					v.normal.z = mesh->mNormals[i].z;
				}

				if (mesh->HasTextureCoords(0)) {
					v.uv.x = mesh->mTextureCoords[0][i].x;
					v.uv.y = mesh->mTextureCoords[0][i].y;
				}
				else {
					v.uv = glm::vec2(0.0f, 0.0f);
				}

				if (mesh->HasVertexColors(0)) {
					v.color.r = mesh->mColors[0][i].r;
					v.color.g = mesh->mColors[0][i].g;
					v.color.b = mesh->mColors[0][i].b;
					v.color.a = mesh->mColors[0][i].a;
				}
				else {
					v.color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				}

				vertices.push_back(v);
			}

			//process indices
			for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
				aiFace face = mesh->mFaces[i];
				for (unsigned int j = 0; j < face.mNumIndices; j++)
					indices.push_back(face.mIndices[j]);
			}

			//process material(wip)
			Material mat = Material(shader);
			if (mesh->mMaterialIndex >= 0) {
				aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
				std::vector<Texture> albedoTextures = load_material_textures(material, aiTextureType_DIFFUSE, warningLogs);

				if (albedoTextures.size() > 0) {
					mat.assign_abledo(albedoTextures[0]);
					warningLogs.push_back(std::format("textures size: {}", albedoTextures.size()));
				}
				//std::vector<Texture> normalTextures = load_material_textures(material, aiTextureType_DISPLACEMENT, warningLogs);
				//std::vector<Texture> specularTextures = load_material_textures(material, aiTextureType_DIFFUSE, warningLogs);
				//std::vector<Texture> emissionTextures = load_material_textures(material, aiTextureType_DIFFUSE, warningLogs);
			}
			warningLogs.push_back("loaded mesh");
			return Mesh(VertexBuffer(vertices, indices), mat);
		}
		std::vector<Texture> Mesh::load_material_textures(aiMaterial* mat, aiTextureType type, std::vector<std::string>& warningLogs) {
			std::vector<Texture> textures;

			for (unsigned int i = 0; i < mat->GetTextureCount(type); i++) {
				aiString str;
				mat->GetTexture(type, i, &str);
				Texture tex = Texture(str.C_Str(), warningLogs);

				warningLogs.push_back(str.C_Str());
				textures.push_back(tex);
			}

			return textures;
		}
	}
}