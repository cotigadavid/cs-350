#ifndef SIMPLE_SCENE_POINTOBJECT_H
#define SIMPLE_SCENE_POINTOBJECT_H

#include "Object.h"
#include "ObjLoader.h"

class PointObject : public Object
{
public:
	PointObject();

	void UploadTransform();

private:

	SharedPtr<OpenGLVertexArray> VAO;
	SharedPtr<OpenGLVertexBuffer> VBO;
	SharedPtr<OpenGLIndexBuffer> IBO;

	glm::vec3 Position;
};

#endif // SIMPLE_SCENE_POINTOBJECT_H