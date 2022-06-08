#ifndef SIMPLE_SCENE_PLANEOBJECT_H
#define SIMPLE_SCENE_PLANEOBJECT_H

#include "Object.h"
#include "ObjLoader.h"


class PlaneObject : public Object
{
public:
	PlaneObject();

	void UploadTransform();

private:
	std::optional<MeshUniquePtr> planeMesh;

	SharedPtr<OpenGLVertexArray> VAO;
	SharedPtr<OpenGLVertexBuffer> VBO;
	SharedPtr<OpenGLIndexBuffer> IBO;
};

#endif // SIMPLE_SCENE_PLANEOBJECT_H