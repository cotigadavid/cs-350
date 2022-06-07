#version 410 core

// Input from the rasterizer
// Conceptually equivalent to
// "WritePixel( x, y, rasterColor )"

out vec4 FragColor;

in vec3 color;
in vec3 normal;
in vec3 crntPos;

uniform vec4 lightColor;
//uniform vec3 lightPos;
uniform vec3 camPos;

void main()
{
	float ambient = 0.20f;
	vec3 Normal = normalize(normal);

	//vec3 lightDirection = normalize(lightPos - crntPos);
	vec3 lightDirection = normalize(vec3(2.0f, 2.0f, 2.0f));
	float diffuse = max(dot(normal, lightDirection), 0.0);

	float specularLight = 0.50f;
	vec3 viewDirection = normalize(camPos - crntPos);
	vec3 reflectionDirection = reflect(-lightDirection, normal);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 16);
	float specular = specAmount * specularLight;

	FragColor = vec4(color, 1.0f) * lightColor * (diffuse + ambient + specular);
	FragColor.w = 1.0f;
}
