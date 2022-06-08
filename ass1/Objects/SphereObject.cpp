#include "SphereObject.h"

SphereObject::SphereObject()
{
	sphereMesh = ObjLoader::LoadObj("../Common/models/sphere.obj");

	VAO = CreateSharedPtr<OpenGLVertexArray>(VertexArray::PrimitiveType::Triangles);
	VBO = CreateSharedPtr<OpenGLVertexBuffer>(sphereMesh->get()->rawVertices.data(), sphereMesh->get()->rawVertices.size() * sizeof(float));
	IBO = CreateSharedPtr<OpenGLIndexBuffer>(sphereMesh->get()->rawIndices.data(), sphereMesh->get()->rawIndices.size());

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

void SphereObject::UploadTransform()
{
	glm::mat4 trans = glm::mat4(1.0f);
	glm::mat4 rot = glm::mat4(1.0f);
	glm::mat4 scale = glm::mat4(1.0f);

	trans = glm::translate(trans, glm::vec3(5.0f, 0.0f, 0.0f));
	rot = glm::mat4_cast(sphereMesh->get()->rotation);
	scale = glm::scale(scale, sphereMesh->get()->scale);

	std::vector<SharedPtr<Shader>> shaders = GetShaders();

	glm::mat4 transform =  trans * rot * scale;

	SetTransform(transform);
}
