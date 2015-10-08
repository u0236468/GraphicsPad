#version 440

out vec4 daColor;
in vec3 normalWorld;
in vec3 vertexPositionWorld;

uniform vec3 lightPosition;
uniform vec4 ambientLight;

void main()
{
	vec3 lightVectorWorld = normalize(lightPosition - vertexPositionWorld);
	float brightness = dot(lightVectorWorld, normalWorld);


	daColor = vec4(brightness, brightness, brightness, 1.0); //channels and 1 for alpha(no transparency) 
};