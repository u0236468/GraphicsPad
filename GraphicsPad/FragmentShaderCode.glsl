#version 440

//out vec4 daColor;
//in vec3 normalWorld;
//in vec3 vertexPositionWorld;
in vec3 daColor;
in vec2 daUV;

out vec4 fragColor;

//uniform vec3 lightPosition;
//uniform vec3 eyePositionWorld;
//uniform vec4 ambientLight;
uniform sampler2D meTexture;

void main()
{
	fragColor = texture(meTexture, daUV);

	//Diffuse
	//vec3 lightVectorWorld = normalize(lightPosition - vertexPositionWorld);
	//float brightness = clamp(dot(lightVectorWorld, normalWorld), 0, 1);
	//vec4 diffuseLight = vec4(brightness, brightness, brightness, 1.0);

	//Specular
	//vec3 reflectedLightVectorWorld = reflect(-lightVectorWorld, normalWorld);
	//vec3 eyeVectorWorld = normalize(eyePositionWorld - vertexPositionWorld);
	//float s = clamp(dot(reflectedLightVectorWorld, eyeVectorWorld), 0, 1);
	//s = pow(s,32);
	//vec4 specularLight = vec4(0, 0, s, 1);
	
	//daColor =  texture(meTexture, daUV) + ambientLight + specularLight + diffuseLight;
		 //clamp just limits it between 1-0 so the angle is not more than 90 so it doens't go negative and goes black
		 //daColor = clamp(specularLight, 0, 1);
		 //before specular -> daColor = vec4(brightness, brightness, brightness, 1.0); //channels and 1 for alpha(no transparency) 
};