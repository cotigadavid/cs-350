#include "CubeObject.h"

#include "glm/glm.hpp"

CubeObject::CubeObject()
{
	cubeMesh = ObjLoader::LoadObj("../Common/models/cube.obj");

	VAO = CreateSharedPtr<OpenGLVertexArray>(VertexArray::PrimitiveType::Triangles);
	VBO = CreateSharedPtr<OpenGLVertexBuffer>(cubeMesh->get()->rawVertices.data(), cubeMesh->get()->rawVertices.size() * sizeof(float));
	IBO = CreateSharedPtr<OpenGLIndexBuffer>(cubeMesh->get()->rawIndices.data(), cubeMesh->get()->rawIndices.size());

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

void CubeObject::UploadTransform()
{
	glm::mat4 trans = glm::mat4(1.0f);
	glm::mat4 rot = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);

	trans = glm::translate(trans, cubeMesh->get()->translation);
	rot = glm::mat4_cast(cubeMesh->get()->rotation);
	scale = glm::scale(scale, cubeMesh->get()->scale);

	std::vector<SharedPtr<Shader>> shaders = GetShaders();

	glm::mat4 transform = trans * rot * scale;

	SetTransform(transform);
}
