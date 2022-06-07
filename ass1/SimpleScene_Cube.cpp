

#include "SimpleScene_Cube.h"
#include <shader.hpp>
#include <glm/vec3.hpp>
#include <string>
//#include <glm/detail/type_mat.hpp>

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
void SimpleScene_Cube::SetupNanoGUI(GLFWwindow* pWindow)
{
	pWindow = nullptr;
}


//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
SimpleScene_Cube::~SimpleScene_Cube()
{
	initMembers();
}

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
SimpleScene_Cube::SimpleScene_Cube(int windowWidth, int windowHeight) : Scene(windowWidth, windowHeight),
programID(0)
{
	camera = CreateSharedPtr<Camera>(1024, 768, glm::vec3(0.0f, 0.0f, 2.0f));

	initMembers();
}

//#pragma clang diagnostic push
//#pragma ide diagnostic ignored "bugprone-unused-return-value"
//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
void SimpleScene_Cube::initMembers()
{
	programID = 0;

}
//#pragma clang diagnostic pop

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
void SimpleScene_Cube::CleanUp()
{
	// Cleanup VBO

	glDeleteProgram(programID);
}

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
void SimpleScene_Cube::SetupBuffers()
{

	cubeObj = ObjMan.CreateCubeObject();
	sphereObj = ObjMan.CreateSphereObject();
	
	cubeObj->AddShaderPass(shader);
	sphereObj->AddShaderPass(shader);

	return;
}

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
int SimpleScene_Cube::Init()
{
	// Create and compile our GLSL program from the shaders
	programID = LoadShaders("../Common/shaders/QuadVertexShader.vert",
		"../Common/shaders/QuadFragmentShader.frag");

	shader = CreateSharedPtr<OpenGLShader>("shader", "../Common/shaders/QuadVertexShader.vert", "../Common/shaders/QuadFragmentShader.frag");

	SetupBuffers();

	return Scene::Init();
}

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
int SimpleScene_Cube::Render()
{
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_FRONT);

	camera->Inputs(window);

	shader->Bind();

	glm::mat4 model = glm::mat4(1.0f);
	
	Renderer::BeginScene(*camera);

	camera->updateMatrix(45.0f, 0.1f, 100.0f);

	//cubeObj->SetTransform(model);
	sphereObj->SetTransform(model);
		
	shader->SetFloat4("lightColor", glm::vec4(1.0f, 0.0f, 1.0f, 1.0f));
	//shader->SetFloat3("lightPos", glm::vec3(-2, -2, -2));
	shader->SetFloat3("camPos", camera->Position);

	camera->Matrix(*shader, "camMatrix");

	ObjMan.RenderAllObject();

	Renderer::EndScene();


	return 0;
}

//////////////////////////////////////////////////////
//////////////////////////////////////////////////////
int SimpleScene_Cube::postRender()
{

	return 0;
}
