#ifndef SIMPLE_SCENE_SPHEREOBJECT_H
#define SIMPLE_SCENE_SPHEREOBJECT_H

#include "Object.h"
#include "ObjLoader.h"


class SphereObject : public Object
{
public:
	SphereObject();

	void UploadTransform();

private:
	std::optional<MeshUniquePtr> sphereMesh;

	SharedPtr<OpenGLVertexArray> VAO;
	SharedPtr<OpenGLVertexBuffer> VBO;
	SharedPtr<OpenGLIndexBuffer> IBO;
};

#endif // SIMPLE_SCENE_SPHEREOBJECT_H