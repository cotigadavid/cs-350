#ifndef SIMPLE_SCENE_TRIANGLEOBJECT_H
#define SIMPLE_SCENE_TRIANGLEOBJECT_H

#include "Object.h"
#include "ObjLoader.h"


class TriangleObject : public Object
{
public:
	TriangleObject();

	void UploadTransform();

private:
	std::optional<MeshUniquePtr> triangleMesh;

	SharedPtr<OpenGLVertexArray> VAO;
	SharedPtr<OpenGLVertexBuffer> VBO;
	SharedPtr<OpenGLIndexBuffer> IBO;
};

#endif // SIMPLE_SCENE_TRIANGLEOBJECT_H