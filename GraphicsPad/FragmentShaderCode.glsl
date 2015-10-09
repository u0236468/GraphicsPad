#version 440

out vec4 daColor;
in vec3 normalWorld;
in vec3 vertexPositionWorld;

uniform vec3 lightPosition;
uniform vec3 eyePositionWorld;
uniform vec4 ambientLight;

void main()
{
	//Diffuse
	vec3 lightVectorWorld = normalize(lightPosition - vertexPositionWorld);
	float brightness = dot(lightVectorWorld, normalWorld);
	vec4 diffuseLight = vec4(brightness, brightness, brightness, 1);

	//Specular
	vec3 reflectedLightVectorWorld = reflect(-lightVectorWorld, normalWorld);
	vec3 eyeVectorWorld = normalize(eyePositionWorld - vertexPositionWorld);
	float s = dot(reflectedLightVectorWorld, eyeVectorWorld);
	s = pow(s,64);
	vec4 specularLight = vec4(s, s, s, 1);
	
	daColor =  ambientLight + clamp(specularLight, 0, 1) + clamp(diffuseLight, 0, 1);
		 //clamp just limits it between 1-0 so the angle is not more than 90 so it doens't go negative and goes black
		//
	//daColor = clamp(specularLight, 0, 1);
	//before specular -> daColor = vec4(brightness, brightness, brightness, 1.0); //channels and 1 for alpha(no transparency) 
};