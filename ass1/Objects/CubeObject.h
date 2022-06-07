#ifndef SIMPLE_SCENE_CUBEOBJECT_H
#define SIMPLE_SCENE_CUBEOBJECT_H

#include "Object.h"
#include "ObjLoader.h"
#include "OpenGL/OpenGLMesh.h"
#include "OpenGL/OpenGLBuffer.h"

class CubeObject : public Object
{
public:
	CubeObject();

private:
	std::optional<MeshUniquePtr> cubeMesh;

	SharedPtr<OpenGLVertexArray> VAO;
	SharedPtr<OpenGLVertexBuffer> VBO;
	SharedPtr<OpenGLIndexBuffer> IBO;
};

#endif // SIMPLE_SCENE_CUBE_H