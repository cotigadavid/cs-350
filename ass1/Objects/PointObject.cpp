#include "PointObject.h"

PointObject::PointObject()
{
	Position = glm::vec3(5.01f, 5.0f, 0.0f);

	VAO = CreateSharedPtr<OpenGLVertexArray>(VertexArray::PrimitiveType::Points);

	float vertexBuffer[] = { Position.x, Position.y, Position.z};

	unsigned int indexBuffer[] = { 0 };

	VBO = CreateSharedPtr<OpenGLVertexBuffer>(vertexBuffer, sizeof(vertexBuffer));
	IBO = CreateSharedPtr<OpenGLIndexBuffer>(indexBuffer, sizeof(indexBuffer) / sizeof(unsigned int));

	BufferLayout MyBufferLayout;

	MyBufferLayout = BufferLayout({
		{ ShaderDataType::Float3, "a_Pos" }
		//{ ShaderDataType::Float3, "a_Normal" }
		});


	VBO->SetLayout(MyBufferLayout);

	VAO->AddVertexBuffer(VBO);
	VAO->SetIndexBuffer(IBO);

	SetVAO(VAO);

	VAO->Unbind();
	VBO->Unbind();
	IBO->Unbind();
}

void PointObject::UploadTransform()
{
}
