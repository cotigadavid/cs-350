
This project provides a way of testing 14 types of intersections between 6 primitive objects: 3DPoint, Plane, Triangle, Boundig Sphere, AABB and Ray;

When the app is opened, the user can select which of the 14 examples to test. The camera is controlled with the WASD keys for movement and the left mouse button for rotation. After selecting the desired example, the user can change the properties of both objects in two smaller windows in the top corners. If, at any point, there is an intersection detected between the two object, the message "Object touch" will be displayed and "Objects don't touch" in the opposite case. 

The folders are arranged as follows:
The source code is in "ass1".
The libraries and assets(3D models and shaders) are in "Common"(with the exception of ImGui, which is in a separate folder in "ass1".
In Debug and Release there are the compiled .exe files for the two configurations respectively, both built in 32 bits.

The app's entry point is in file ass1/GLApplication.cpp. In the main function glfw is initialized and the scene is created. Also here is the app's "main loop", called every frame. The scene used in the project is an object of class "MainScene", which inherits from "Scene". The files are both in "ass1". In the initialization of the scene the objects are also created. Each primitive inherits from Object. The ObjectManager stores an array of all the objects and renders them. This classes can be found in ass1/Objects. Each primitive class contains information about its position in the 3d space and a function named "Intersects" which determines whether the object intersects with the other primitive. In the MainScene file there are also the functions "ImGuiSetup" and "RenderImGui" which initialize, respectively render the user interface. When it comes to the opengl rendering, the vertex arrays, vertex buffers, index buffers, and shaders are abstracted into separate classes, which automate and simplify the entire rendering process. The cube, sphere and triangle's vertices are loaded from obj files into meshes(ass1/OpenGL/OpenGLMesh.h). This is done in the ObjLoader class, without the use of any library, but simply processing the characters in the file(ass1/Objects/ObjLoader.cpp LoadObj function).

Libraries used:
	-glfw https://www.glfw.org/
	-glew http://glew.sourceforge.net/
	-glm https://glm.g-truc.net/0.9.9/
	-ImGui https://github.com/ocornut/imgui
