#include "RayObject.h"

RayObject::RayObject()
{
	startingPoint = glm::vec3(10.01f);
	endPoint = glm::vec3(0.0f);

	VAO = CreateSharedPtr<OpenGLVertexArray>(VertexArray::PrimitiveType::Lines);

	float vertexBuffer[] = { startingPoint.x, startingPoint.y, startingPoint.z, 
							endPoint.x, endPoint.y, endPoint.z};

	unsigned int indexBuffer[] = { 0, 1 };

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

void RayObject::UploadTransform()
{
}
