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