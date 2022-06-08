#version 410 core

layout (location = 0) in vec3 aPos;
//layout (location = 1) in vec3 aNormal;

out vec3 color;
//out vec3 normal;
//out vec3 crntPos;

//uniform mat4 model;
uniform mat4 camMatrix;

//uniform mat4 translation;
//uniform mat4 rotation;
//uniform mat4 scale;

void main()
{
	//crntPos = vec3(model * translation * -rotation * scale * vec4(aPos, 1.0f));
	//crntPos = vec3(model * vec4(aPos, 1.0f));
	gl_Position = camMatrix * vec4(aPos, 1.0);
	//normal = aNormal;
	color = vec3(1.0, 1.0, 1.0);
	
}
