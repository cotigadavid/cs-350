//
// Created by roland on 9/14/20.
//

#ifndef SIMPLE_SCENE_OBJLOADER_H
#define SIMPLE_SCENE_OBJLOADER_H

#include "../stdafx.h"

class VertexArray;

struct Mesh
{
	virtual ~Mesh() = default;
	union Face
	{
		unsigned point[3];
		struct
		{
			unsigned index1, index2, index3;
		};
		bool Contains(int unsigned) const ;
	};
	struct Edge
	{
		glm::vec4 point[2];
	};
	
	// Vertex data
	std::vector<float> rawVertices;
	std::vector<unsigned int> rawIndices;
	std::vector<glm::vec4> Vertices;
	std::vector<glm::vec4> VertexNormals;
	std::vector<glm::vec3> faceNormals;
	std::vector<glm::vec4> Color;
	std::vector<glm::vec2> UV;

	glm::vec3 translation = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::quat rotation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);
	glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f);

	// This is also the index array.
	std::vector<Face> Faces;
	// Alternative indexer (for non-triangles)
	std::vector<unsigned> Index;

	// Lighting Data
	glm::vec3 DiffuseColor;
	glm::vec3 SpecularColor;
	float shininess;

	virtual Mesh& SetIndexBuffer(SharedPtr<VertexArray>& vaoOwner) = 0;
	virtual Mesh& SetVerticeBuffer(SharedPtr<VertexArray>& vaoOwner) = 0;
	virtual Mesh& SetVertexNormal(SharedPtr<VertexArray>& vaoOwner) = 0;
	virtual Mesh& GenerateRandomColors(SharedPtr<VertexArray>& vaoOwner) = 0;
	virtual Mesh& GenerateVertexColor(SharedPtr<VertexArray>& vaoOwner) = 0;
	virtual Mesh& GenerateFaceNormalLines(SharedPtr<VertexArray>& vaoOwner) = 0;
	virtual Mesh& GenerateVertexNormalLines(SharedPtr<VertexArray>& vaoOwner) = 0;
	virtual Mesh& CalcVertexNormal(SharedPtr<VertexArray>& vaoOwner) = 0;
};

using MeshUniquePtr = UniquePtr<Mesh>;

class ObjLoader
{
public:
	static void AssembleBuffers(Mesh& mesh);
	static std::optional<MeshUniquePtr> LoadObj(const char* fileLocation);
	static std::optional<MeshUniquePtr> CreateSphere(float radius, unsigned numDivisions);
	static std::optional<MeshUniquePtr> CreateCircularLine(float radius, unsigned divisions);
};


std::ostream& operator<< (std::ostream& os, Mesh::Face const & face);
std::ostream& operator<< (std::ostream& os, Mesh::Edge const & face);
#endif //SIMPLE_SCENE_OBJLOADER_H
