#include "CubeObject.h"

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