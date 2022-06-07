#ifndef SIMPLE_SCENE_SIMPLESCENE_CUBE_H
#define SIMPLE_SCENE_SIMPLESCENE_CUBE_H

#include "Scene.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <vector>

#include "OpenGL/OpenGLBuffer.h"
#include "OpenGL/OpenGLRendererAPI.h"
#include "OpenGL/OpenGLShader.h"
#include "OpenGL/OpenGLMesh.h"

#include "Objects/Object.h"
#include "Objects/ObjLoader.h"
#include "Objects/ObjectManager.h"
#include "Objects/CubeObject.h"
#include "Objects/SphereObject.h"


#include "Renderer/Renderer.h"

#include "Renderer/Camera.h"

class SimpleScene_Cube : public Scene
{

public:
	SimpleScene_Cube() = default;
	SimpleScene_Cube(int windowWidth, int windowHeight);
	virtual ~SimpleScene_Cube();


public:
	int Init() override;
	void CleanUp() override;

	int Render() override;
	int postRender() override;

	void SetWindow(GLFWwindow* newWindow) override { window = newWindow; }

private:

	// member functions
	void initMembers();

	// This is the non-software engineered portion of the code
	// Go ahead and modularize the VAO and VBO setup into
	// BufferManagers and ShaderManagers
	void SetupBuffers();

	void SetupNanoGUI(GLFWwindow* pWwindow) override;

	// data members
	GLuint  programID;

	SharedPtr<OpenGLShader> shader;

	//SharedPtr<Object> cubeObj;
	
	ObjectManager ObjMan;
	SharedPtr<Camera> camera;

	GLFWwindow* window;

	SharedPtr<CubeObject> cubeObj;
	SharedPtr<SphereObject> sphereObj;
};


#endif //SIMPLE_SCENE_SIMPLESCENE_CUBE_H