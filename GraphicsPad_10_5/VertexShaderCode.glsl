#version 440

in layout(location=0) vec3 position; //varrying data
in layout(location=1) vec4 vertexColor; //vec4 vertexColor; //varrying data 
in layout(location=2) vec3 normal;
uniform vec4 ambientLight;
//uniform vec3 lightPosition

uniform mat4 mvp; //uniform means the value will be the same for every single vertex

out vec3 theNormal; // declare var - we need to send the color out to the hardware to interpulate
out vec3 thePosition;

//add one more uniform to the rotationMatrix... send down a nother uniform before you draw down another taurus

void main()
{
//	vec3 lightPosition = vec3(0,1,-2);
//	vec3 normal = vec3(0,2,0);
	gl_Position = mvp * vec4(position, 1.0);
	theNormal = normal;
	thePosition = position;
//	theColor = vertexColor * ambientLight;
//	daColor = vertexColor * ambientLight * brightness;
};