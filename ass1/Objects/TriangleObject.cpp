#include "TriangleObject.h"

#include "glm/glm.hpp"

TriangleObject::TriangleObject()
{
	triangleMesh = ObjLoader::LoadObj("../Common/models/triangle.obj");

	VAO = CreateSharedPtr<OpenGLVertexArray>(VertexArray::PrimitiveType::Triangles);
	VBO = CreateSharedPtr<OpenGLVertexBuffer>(triangleMesh->get()->rawVertices.data(), triangleMesh->get()->rawVertices.size() * sizeof(float));
	IBO = CreateSharedPtr<OpenGLIndexBuffer>(triangleMesh->get()->rawIndices.data(), triangleMesh->get()->rawIndices.size());

	BufferLayout MyBufferLayout;

	MyBufferLayout = BufferLayout({
		{ ShaderDataType::Float3, "a_Pos" },
		{ ShaderDataType::Float3, "a_Normal" }
		});


	VBO->SetLayout(MyBufferLayout);

	VAO->AddVertexBuffer(VBO);
	VAO->SetIndexBuffer(IBO);

	SetVAO(VAO);

	VAO->Unbind();
	VBO->Unbind();
	IBO->Unbind();
}

void TriangleObject::UploadTransform()
{
	glm::mat4 trans = glm::mat4(1.0f);
	glm::mat4 rot = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);

	trans = glm::translate(trans, glm::vec3(10.0f, 0.0f, 0.0f));
	rot = glm::mat4_cast(triangleMesh->get()->rotation);
	scale = glm::scale(scale, triangleMesh->get()->scale);

	std::vector<SharedPtr<Shader>> shaders = GetShaders();

	glm::mat4 transform = trans * rot * scale;

	SetTransform(transform);
}
