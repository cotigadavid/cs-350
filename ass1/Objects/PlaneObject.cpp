#include "PlaneObject.h"

#include "glm/glm.hpp"

PlaneObject::PlaneObject()
{
	planeMesh = ObjLoader::LoadObj("../Common/models/quad.obj");

	VAO = CreateSharedPtr<OpenGLVertexArray>(VertexArray::PrimitiveType::Triangles);
	VBO = CreateSharedPtr<OpenGLVertexBuffer>(planeMesh->get()->rawVertices.data(), planeMesh->get()->rawVertices.size() * sizeof(float));
	IBO = CreateSharedPtr<OpenGLIndexBuffer>(planeMesh->get()->rawIndices.data(), planeMesh->get()->rawIndices.size());

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

void PlaneObject::UploadTransform()
{
	glm::mat4 trans = glm::mat4(1.0f);
	glm::mat4 rot = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);

	trans = glm::translate(trans, glm::vec3(15.0f, 0.0f, 0.0f));
	rot = glm::mat4_cast(planeMesh->get()->rotation);
	scale = glm::scale(scale, planeMesh->get()->scale);

	std::vector<SharedPtr<Shader>> shaders = GetShaders();

	glm::mat4 transform = trans * rot * scale;

	SetTransform(transform);
}
