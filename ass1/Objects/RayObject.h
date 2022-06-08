#ifndef SIMPLE_SCENE_RAYOBJECT_H
#define SIMPLE_SCENE_RAYOBJECT_H

#include "Object.h"
#include "ObjLoader.h"


class RayObject : public Object
{
public:
	RayObject();

	void UploadTransform();

private:

	SharedPtr<OpenGLVertexArray> VAO;
	SharedPtr<OpenGLVertexBuffer> VBO;
	SharedPtr<OpenGLIndexBuffer> IBO;

	glm::vec3 startingPoint;
	glm::vec3 endPoint;
};

#endif // SIMPLE_SCENE_RAYOBJECT_H