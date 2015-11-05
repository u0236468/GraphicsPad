#version 440

in layout(location=0) vec3 vertexPositionModel; //varrying data
//in layout(location=1) vec4 vertexColor;
in layout(location=1) vec2 uv; //vec4 vertexColor; //varrying data 
in layout(location=2) vec3 normalModel;


uniform mat4 modelToProjectionMatrix; //uniform means the value will be the same for every single vertex
uniform mat3 normalMatrix;

out vec3 normalWorld; // declare var - we need to send the color out to the hardware to interpolate
out vec3 vertexPositionWorld;
out vec2 daUV;

//add one more uniform to the rotationMatrix... send down a nother uniform before you draw down another taurus

void main()
{
//	vec3 lightPosition = vec3(0,1,-2);
//	vec3 normalModel = vec3(0,2,0);
	gl_Position = modelToProjectionMatrix * vec4(vertexPositionModel, 1.0);
	//vec3 normalModel = vec3(0,1.0,0);
	normalWorld = normalMatrix * normalModel;
	vertexPositionWorld = vertexPositionModel;
	daUV = uv;
//	theColor = vertexColor * ambientLight;
//	daColor = vertexColor * ambientLight * brightness;
};