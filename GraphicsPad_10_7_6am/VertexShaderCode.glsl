#version 440

in layout(location=0) vec4 vertexPositionModel; //varrying data
in layout(location=1) vec3 vertexColor; //vec4 vertexColor; //varrying data 
in layout(location=2) vec3 normalModel;

//uniform vec3 lightPosition

uniform mat4 modelToProjectionMatrix; //uniform means the value will be the same for every single vertex
uniform mat4 modelToWorldMatrix;

out vec3 normalWorld; // declare var - we need to send the color out to the hardware to interpulate
out vec3 vertexPositionWorld;

//add one more uniform to the rotationMatrix... send down a nother uniform before you draw down another taurus

void main()
{
	gl_Position = modelToProjectionMatrix * vvertexPositionModel
	normalWorld = vec3(modelToWorldMatrix * vec4(normalModel, 0);
	vertexPositionWorld = vec3(modelToWorldMatrix * vertexPositionModel);
};