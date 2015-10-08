#version 440

out vec4 daColor;
in vec3 normalWorld;
in vec3 vertexPositionWorld;

uniform vec3 lightPositionWorld;
uniform vec3 eyePositionWorld;
uniform vec4 ambientLight;

void main()
{
	//Diffuse
	vec3 lightVectorWorld = normalize(lightPositionWorld - vertexPositionWorld);
	float brightness = dot(lightVectorWorld, theNormal);	
	vec4 diffuseLight = vec4(brightness, brightness, brightness, 1.0); 

	//Specular
	vec3 reflectedLightVectorWorld = reflect(-lightVectorWorld, normalize(normalWorld));
	vec3 eyeVectorWorld = normalize(eyePositionWorld - vertexPositionWorld);
	float s = dot(relectedLightVectorWold, eyeVectorWorld);
	s = pow(s, 8);
	vec4 specularLight = (s, s, s, 1;)

	daColor = ambientLight + clamp(diffuseLight, 0, 1) + clamp(specularLight, 0, 1);

};