#version 440

in layout(location=0) vec3 vertexPositionModel; //varrying data
in layout(location=1) vec3 color;
in layout(location=2) vec2 uv;
//in layout(location=2) vec3 normalModel;


uniform mat4 modelToProjectionMatrix; //uniform means the value will be the same for every single vertex
//uniform mat3 normalMatrix;

//out vec3 normalWorld; // declare var - we need to send the color out to the hardware to interpolate
//out vec3 vertexPositionWorld;
out vec2 daUV;
out vec3 daColor;

void main()
{
//	vec3 lightPosition = vec3(0,1,-2);
//	vec3 normalModel = vec3(0,2,0);
	daColor = color;
	daUV = uv;
	gl_Position = modelToProjectionMatrix * vec4(vertexPositionModel, 1.0);
	//vec3 normalModel = vec3(0,1.0,0);
	//normalWorld = normalMatrix * normalModel;
	//vertexPositionWorld = vertexPositionModel;
//	theColor = vertexColor * ambientLight;
//	daColor = vertexColor * ambientLight * brightness;
};