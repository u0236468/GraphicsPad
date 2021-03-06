/*
Earl Kirkland 
Shader Development
Original Code by Jamie King
*/

#include <gl\glew.h>
#include <iostream>
#include "MeOpenGl.h"
#include <cassert>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtx\transform.hpp>
#include "ShapeGenerator.h"
#include <fstream>
#include <QtGui\qmouseevent>
#include <QtGui\qkeyevent>
#include "Camera.h"
#include "DebugGuiManager.h"

//#define GENERATED_SHAPE

using namespace std;
using glm::vec3;
using glm::vec4;
using glm::mat4;

//const uint NUM_VERTICES_PER_TRI = 3;
//const uint NUM_FLOATS_PER_VERTICE = 9;
//const uint VERTEX_BYTE_SIZE = NUM_FLOATS_PER_VERTICE * sizeof(float);
GLuint programID;
GLuint planeNumIndices;
GLuint sphereNumIndices;
GLuint torusNumIndices;
GLuint numIndices;
Camera camera;

void MeOpenGl::loadDataPlane()
{
	//ShapeData plane = ShapeGenerator::makePlane(10);
	//ShapeData shape = ShapeGenerator::makeTorus(50);

	/*
	float verts[] =
	{
		// Top
		-1.0f, +1.0f, +1.0f, // 0
		+1.0f, +0.0f, +0.0f, +1.0f, // Color
		+1.0f, +1.0f, +1.0f, // 1
		+0.0f, +1.0f, +0.0f, +1.0f, // Color
		+1.0f, +1.0f, -1.0f, // 2
		+0.0f, +0.0f, +1.0f, +1.0f, // Color
		-1.0f, +1.0f, -1.0f, // 3
		+1.0f, +1.0f, +1.0f, +1.0f, // Color

									// Front
		-1.0f, +1.0f, -1.0f, // 4
		+1.0f, +0.0f, +1.0f, +1.0f, // Color
		+1.0f, +1.0f, -1.0f, // 5
		+0.0f, +0.5f, +0.2f, +1.0f, // Color
		+1.0f, -1.0f, -1.0f, // 6
		+0.8f, +0.6f, +0.4f, +1.0f, // Color
		-1.0f, -1.0f, -1.0f, // 7
		+0.3f, +1.0f, +0.5f, +1.0f, // Color

									// Right
		+1.0f, +1.0f, -1.0f, // 8
		+0.2f, +0.5f, +0.2f, +1.0f, // Color
		+1.0f, +1.0f, +1.0f, // 9
		+0.9f, +0.3f, +0.7f, +1.0f, // Color
		+1.0f, -1.0f, +1.0f, // 10
		+0.3f, +0.7f, +0.5f, +1.0f, // Color
		+1.0f, -1.0f, -1.0f, // 11
		+0.5f, +0.7f, +0.5f, +1.0f, // Color

									// Left
		-1.0f, +1.0f, +1.0f, // 12
		+0.7f, +0.8f, +0.2f, +1.0f, // Color
		-1.0f, +1.0f, -1.0f, // 13
		+0.5f, +0.7f, +0.3f, +1.0f, // Color
		-1.0f, -1.0f, -1.0f, // 14
		+0.4f, +0.7f, +0.7f, +1.0f, // Color
		-1.0f, -1.0f, +1.0f, // 15
		+0.2f, +0.5f, +1.0f, +1.0f, // Color

									// Back
		+1.0f, +1.0f, +1.0f, // 16
		+0.6f, +1.0f, +0.7f, +1.0f, // Color
		-1.0f, +1.0f, +1.0f, // 17
		+0.6f, +0.4f, +0.8f, +1.0f, // Color
		-1.0f, -1.0f, +1.0f, // 18
		+0.2f, +0.8f, +0.7f, +1.0f, // Color
		+1.0f, -1.0f, +1.0f, // 19
		+0.2f, +0.7f, +1.0f, +1.0f, // Color

									// Bottom
		+1.0f, -1.0f, -1.0f, // 20
		+0.8f, +0.3f, +0.7f, +1.0f, // Color
		-1.0f, -1.0f, -1.0f, // 21
		+0.8f, +0.9f, +0.5f, +1.0f, // Color
		-1.0f, -1.0f, +1.0f, // 22
		+0.5f, +0.8f, +0.5f, +1.0f, // Color
		+1.0f, -1.0f, +1.0f, // 23
		+0.9f, +1.0f, +0.2f, +1.0f, // Color
	};*/

	/*
	GLushort Indices[] = {  //indices are to tell us how the vertices are connected.
		0, 1, 2, 0, 2, 3, // Top
		4, 5, 6, 4, 6, 7, // Front
		8, 9, 10, 8, 10, 11, // Right 
		12, 13, 14, 12, 14, 15, // Left
		16, 17, 18, 16, 18, 19, // Back
		20, 22, 21, 20, 23, 22, // Bottom
	};
	*/

	//Triagle
	//GLfloat verts[] = {
	//	+0.0f, +1.0f,
	//	+1.0f, +0.0f, +0.0f,
	//	-1.0f, -1.0f,
	//	+0.0f, +1.0f, +0.0f,
	//	+1.0f, -1.0f,
	//	+0.0f, +0.0f, +1.0f,
	//};

	/*GLuint vertexBufferID;
	glGenBuffers(1, &vertexBufferID);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(GLfloat) * 5, (char*)(sizeof(float) * 2));
	
	GLshort indices[] = { 0, 1, 2 };
	GLuint indexBufferID;
	glGenBuffers(1, &indexBufferID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/
/*float verts[] =
{
	-1.0f, -1.0f,
	+0.0f, +0.0f,

	+1.0f, -1.0f,
	+1.0f, +0.0f,

	+1.0f, +1.0f,
	+1.0f, +1.0f,

	-1.0f, +1.0f,
	+0.0f, +1.0f,
};

GLushort indices[] = {
	0,1,2,
	2,3,0
};*/

/*#ifdef GENERATED_SHAPE
	//ShapeData shape = ShapeGenerator::makePlane(10);
	//ShapeData shape = ShapeGenerator::makeTorus(100);
	//ShapeData shape = ShapeGenerator::make2DTriangle();
	//ShapeData shape = ShapeGenerator::makeTeapot();

#else*/
	ShapeDataPnut shape;

	std::ifstream input("E:\\GraphicsPad\\brick_wall.bin", std::ios::binary);
	assert(input.good());

	input.read(reinterpret_cast<char*>(&shape.numVerts), sizeof(shape.numVerts));
	assert(input.good());
	input.read(reinterpret_cast<char*>(&shape.numIndices), sizeof(shape.numIndices));

	shape.verts = new VertexPNUT[shape.numVerts];
	input.read(reinterpret_cast<char*>(shape.verts), shape.vertexBufferSize());
	int sanity = shape.vertexBufferSize();
	shape.indices = new ushort[shape.numIndices];
	input.read(reinterpret_cast<char*>(shape.indices), shape.vertexBufferSize());

	glGenBuffers(1, &vertexBufferID);
	glGenBuffers(1, &indexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, shape.vertexBufferSize(), shape.verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, shape.indexBufferSize(), shape.indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	numIndices = shape.numIndices;
	shape.cleanUp();


	//textures
	/*glGenBuffers(1, &textureVertexBufferID);
	glGenBuffers(1, &textureIndexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, textureVertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, textureIndexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	numIndices = 6;*/
	
	//torus
	/*ShapeData torus = ShapeGenerator::makeTorus(50);

	glGenBuffers(1, &torusVertexBufferID);
	glGenBuffers(1, &torusIndexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, torusVertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, torus.vertexBufferSize(), torus.verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, torusIndexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, torus.indexBufferSize(), torus.indices, GL_STATIC_DRAW);

	torusNumIndices = torus.numIndices;
	torus.cleanup();

	//shpere
	ShapeData sphere = ShapeGenerator::makeSphere(50);

	glGenBuffers(1, &sphereVertexBufferID);
	glGenBuffers(1, &sphereIndexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, sphereVertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sphere.vertexBufferSize(), sphere.verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphereIndexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sphere.indexBufferSize(), sphere.indices, GL_STATIC_DRAW);

	sphereNumIndices = sphere.numIndices;
	sphere.cleanup();

	//plane
	ShapeData plane = ShapeGenerator::makePlane(10);

	glGenBuffers(1, &planeVertexBufferID);
	glGenBuffers(1, &planeIndexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, planeVertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, plane.vertexBufferSize(), plane.verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, planeIndexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, plane.indexBufferSize(), plane.indices, GL_STATIC_DRAW);

	planeNumIndices = plane.numIndices;
	plane.cleanup();*/

	//connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	//myTimer.start(100);
};

bool checkStatus(
	GLuint objectID,
	PFNGLGETSHADERIVPROC objectPropertyGetterFunc,
	PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
	GLenum statusType)
{
	GLint status;
	objectPropertyGetterFunc(objectID, statusType, &status);
	if (status != GL_TRUE)
	{
		GLint infoLogLength;
		objectPropertyGetterFunc(objectID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = new GLchar[infoLogLength];

		GLsizei bufferSize;
		glGetShaderInfoLog(objectID, infoLogLength, &bufferSize, buffer);
		cout << buffer << endl;

		delete[] buffer;
		return false;
	}
	return true;
}

bool checkShaderStatus(GLuint shaderID)
{
	return checkStatus(shaderID, glGetShaderiv, glGetShaderInfoLog, GL_COMPILE_STATUS);
}

bool checkProgramStatus(GLuint programID)
{
	return checkStatus(programID, glGetProgramiv, glGetProgramInfoLog, GL_LINK_STATUS); 
}

string readShaderCode(const char* fileName)
{
	ifstream meInput(fileName);
	if (!meInput.good())
	{
		cout << "File failed to load.... " << fileName;
		exit(1);
	}
	return std::string(
		std::istreambuf_iterator<char>(meInput),
		std::istreambuf_iterator<char>());
}

void MeOpenGl::installShaders()
{
	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	const char* adapter[1];
	string temp = readShaderCode("VertexShaderCode.glsl");
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	temp = readShaderCode("FragmentShaderCode.glsl");
	adapter[0] = temp.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	GLint compileStatus;
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE)
	{
		GLint infoLogLength;
		glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = new GLchar[infoLogLength];

		GLsizei bufferSize;
		glGetShaderInfoLog(vertexShaderID, infoLogLength, &bufferSize, buffer);
		cout << buffer << endl;

		delete[] buffer;

	}

	if (!checkShaderStatus(vertexShaderID) || !checkShaderStatus(fragmentShaderID))
		return;

	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID); 
	glAttachShader(programID, fragmentShaderID); 
	glLinkProgram(programID);

	if (!checkProgramStatus(programID))
		return;

	glUseProgram(programID);
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

}

void MeOpenGl::sendDownUniform(float rotationAmount)
{
	//GLuint uniformLocation = glGetUniformLocation(programID, "modelToProjectionMatrix");

	/*glm::mat4 translate = glm::translate(0.0f, 0.0f, 0.0f);
	
	rotationAmount += 1.0f;
	//glm::mat4 modelToWorld = glm::scale(0.5f, 1.0f, 1.0f) * 
	glm::mat4 rotate = glm::rotate(0.0f, //angle
									1.0f, //x axis
									0.0f, //y axis set to 1 if you want to rotation on this axis
									0.0f) * //z axis
		glm::rotate(0.0f, 0.0f, 1.0f, 0.0f);//(rotationAmount, 1.0f, 0.0f, 0.0f) * glm::rotate(rotationAmount, 0.0f, 1.0f, 0.0f);
	
	glm::mat4 modelToWorld = translate * rotate;

	glm::mat4 worldToView = glm::lookAt(
		glm::vec3(0.0f, 1.0f, 0.0f), //eyePosition
		glm::vec3(0.0f, 1.0f, -1.0f), //Center
		glm::vec3(0.0f, 1.0f, 0.0f)); //Up direction

	glm::mat4 perspective = glm::perspective(60.0f, ((float)width()) / height(), 0.1f, 15.0f); //changed 100.0f to 1|||||5.0f

	//glm::mat4 modelToProjectionMatrix = modelToWorld * worldToView * viewToProjection;
	glm::mat4 modelToProjectionMatrix = perspective * camera.getWorldToViewMatrix() *modelToWorld * worldToView;// *worldToView * perspective;
	
	//Plane
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &modelToProjectionMatrix[0][0]);

	//Torus 1:
	modelToWorld = glm::translate(-5.0f, 0.0f, 0.0f);
	modelToProjectionMatrix = perspective* worldToView * modelToWorld;
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &modelToProjectionMatrix[0][0]);*/

	//Torus 2:
	//modelToWorld = glm::translate(-2.0f, 0.0f, 0.0f);

	//GLint location = glGetUniformLocation(programID, "modelToProjectionMatrix");

	//glUniformMatrix4fv(location, 1, GL_FALSE, &modelToProjectionMatrix[0][0]);
	

	/*GLint ambientLightUniformLocation = glGetUniformLocation(programID, "ambientLight");
	glm::vec4 ambientLight(0.1f, 0.1f, 0.1f, 1.0f);
	glUniform4fv(ambientLightUniformLocation, 1, &ambientLight[0]);

	GLint lightPositionUniformLocation = glGetUniformLocation(programID, "lightPosition");
	glm::vec3 lightPosition(0.0f, 2.0f, 0.0f);
	glUniform3fv(lightPositionUniformLocation, 1, &lightPosition[0]);

	GLint eyePositionWorldUniformLocation = glGetUniformLocation(programID, "eyePositionWorld");
	glm::vec3 eyePositionWorld = camera.position;
	glUniform3fv(eyePositionWorldUniformLocation, 1, &eyePositionWorld[0]);*/

	//glm::mat4 translate = glm::translate(0.0f, 0.0f, -5.0f);
	//glm::mat4 rotate = glm::rotate(45.0f, 1.0f, 0.0f) * glm::rotate(45.0f, 1.0f, 0.0f); //rotate 45 degrees around the x, then the Y

	//disfuse - draw a plane with 4 dot product s on it going up. Then there is light coming in from different angles, 
	//and the cosine of the angle to the vector will show how bright is. 
	//if the angle is coming from 0 and 180 degreens to the cosine, it will hit 0 which is the darkest.
	
	//vector is a position off the origin
	//translate will really mess with your vectors as it stretches them
	//rotation will change the normals but not translate
	//next assignment - plain down and drop the taurus orianted up with light hitting the side. Then put more taurus in there, put a camera in there and then put lighting in the fragment shader.


}

void MeOpenGl::myUpdate()
{
	sendDownUniform(rotationAmount);
	rotationAmount = rotationAmount + 0.5f;
	repaint();
}

void MeOpenGl::loadTexture()
{
	GLuint textureID;
	glGenTextures(1, &textureID);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textureID);
	
	QImage myTexture = QGLWidget::convertToGLFormat(QImage("brick.png", "PNG"));
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, myTexture.width(), myTexture.height(), 
		0, GL_RGBA, GL_UNSIGNED_BYTE, myTexture.bits());

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	GLint textureUniformLocation = glGetUniformLocation(programID, "meTexture");
	glUniform1i(textureUniformLocation, 0);
}

void MeOpenGl::initializeGL()
{
	QGLWidget::initializeGL();
	GLenum errorCode = glewInit();
	if (errorCode != GLEW_OK)
		return;
	installShaders();
	loadDataPlane();
	loadTexture();
	//loadDataSphere();
	//sendDownUniform();

	glEnable(GL_DEPTH_TEST);
	connect(&myTimer, SIGNAL(timeout()),
		this,
		SLOT(myUpdate()));
	myTimer.start();
}

void MeOpenGl::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, width(), height());
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	GLuint uniformLocation = glGetUniformLocation(programID, "modelToProjectionMatrix");
	GLuint normalUniformLocation = glGetUniformLocation(programID, "normalMatrix");

	/*glm::mat4 translate = glm::translate(0.0f, 0.0f, 0.0f);

	//rotationAmount += 1.0f;
	//glm::mat4 modelToWorld = glm::scale(0.5f, 1.0f, 1.0f) * 
	glm::mat4 rotate = glm::rotate(0.0f, //angle
		1.0f, //x axis
		0.0f, //y axis set to 1 if you want to rotation on this axis
		0.0f) * //z axis
		glm::rotate(0.0f, 0.0f, 1.0f, 0.0f);*///(rotationAmount, 1.0f, 0.0f, 0.0f) * glm::rotate(rotationAmount, 0.0f, 1.0f, 0.0f);

	//glm::mat4 modelToWorld = 
		//glm::rotate(90.0f, glm::vec3(+1.0f, +0.0f, +0.0f)) *
		//glm::rotate(180.0f, glm::vec3(+1.0f, +1.0f, +0.0f)); // = camera.getWorldToViewMatrix(); // = translate * rotate;
	glm::mat4 worldToView = camera.getWorldToViewMatrix();
	/*glm::lookAt(
		glm::vec3(0.0f, 1.0f, 0.0f), //eyePosition
		glm::vec3(0.0f, 1.0f, -1.0f), //Center
		glm::vec3(0.0f, 1.0f, 0.0f));*/ //Up direction
	glm::mat4 perspective = glm::perspective(60.0f, ((float)width()) / height(), 0.1f, 100.0f); //changed 100.0f to 1|||||5.0f																						   //glm::mat4 modelToProjectionMatrix = modelToWorld * worldToView * viewToProjection;
	glm::mat4 modelToProjectionMatrix = perspective * worldToView;// *modelToWorld; // = perspective * camera.getWorldToViewMatrix() *modelToWorld * worldToView;// *worldToView * perspective;
	glm::mat3 normalMatrix;
																												//Plane
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &modelToProjectionMatrix[0][0]);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexPNUT), (void*)VertexOffsets::VO_PNUT_POSITION);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexPNUT), (void*)VertexOffsets::VO_PNUT_NORMAL);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexPNUT), (void*)VertexOffsets::VO_PNUT_UV);
	
	debugGuiManager.update();
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, 0);
	
	//textures
	/*glBindBuffer(GL_ARRAY_BUFFER, textureVertexBufferID);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE,
		4 * sizeof(float), //Stride
		(void*)(2 * sizeof(float)));//offset
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, textureIndexBufferID);*/

	//torus
	/*glBindBuffer(GL_ARRAY_BUFFER, torusVertexBufferID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), //Stride
		(void*)(7 * sizeof(float)));//offset
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, torusIndexBufferID);

	//Torus 1:
	modelToWorld = glm::translate(3.0f, 0.0f, -5.0f) * glm::rotate(90.0f, 1.0f, 0.0f, 02.0f);
	modelToProjectionMatrix = perspective* worldToView * modelToWorld;
	normalMatrix = glm::mat3(modelToWorld);
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &modelToProjectionMatrix[0][0]);
	glUniformMatrix3fv(normalUniformLocation, 1, GL_FALSE, &normalMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, torusNumIndices, GL_UNSIGNED_SHORT, 0);

	//Torus 2:
	modelToWorld = glm::translate(-3.0f, 0.0f, -5.0f) * glm::rotate(45.0f, 1.0f, 0.0f, 0.0f);
	modelToProjectionMatrix = perspective* worldToView * modelToWorld;
	normalMatrix = glm::mat3(modelToWorld);
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &modelToProjectionMatrix[0][0]);
	glUniformMatrix3fv(normalUniformLocation, 1, GL_FALSE, &normalMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, torusNumIndices, GL_UNSIGNED_SHORT, 0);
	
	//Sphere
	glBindBuffer(GL_ARRAY_BUFFER, sphereVertexBufferID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), //Stride
		(void*)(7 * sizeof(float)));//offset
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, sphereIndexBufferID);

	//sphere1
	modelToWorld = glm::translate(0.0f, 0.0f, -5.0f) * glm::rotate(90.0f, 1.0f, 0.0f, 02.0f);
	modelToProjectionMatrix = perspective* worldToView * modelToWorld;
	normalMatrix = glm::mat3(modelToWorld);
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &modelToProjectionMatrix[0][0]);
	glUniformMatrix3fv(normalUniformLocation, 1, GL_FALSE, &normalMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, sphereNumIndices, GL_UNSIGNED_SHORT, 0);
	
	//Plane
	glBindBuffer(GL_ARRAY_BUFFER, planeVertexBufferID);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE,
		sizeof(Vertex), //Stride
		(void*)(7 * sizeof(float)));//offset
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, planeIndexBufferID);

	//Plane 1:
	modelToWorld = glm::translate(0.0f, -5.0f, -5.0f) * glm::rotate(0.0f, 1.0f, 0.0f, 02.0f);
	modelToProjectionMatrix = perspective* worldToView * modelToWorld;
	normalMatrix = glm::mat3(modelToWorld);
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &modelToProjectionMatrix[0][0]);
	glUniformMatrix3fv(normalUniformLocation, 1, GL_FALSE, &normalMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, 0);*/

	/*...............
	glUniformMatrix4v(uniformLocation, 1, GL_FALSE, &modelToProjectionMatrix[0][0]);
	glUniformMatrix3v(normalUniformLocation, 1, GL_FALSE, &normalMatrix[0][0]);
	glDraw....
	..............*/
	//Torus1
	//glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, 0); // there are 6 indices for one side of the cube, 3 for each triabngle
	/*glm::vec3 lightPositionWorld(0.0f, 2.0f, 0.0f);

	mat4 modelToProjectionMatrix;
	mat4 viewToProjectionMatrix = glm::perspective(60.0f, ((float)width()) / height(), 0.1f, 20.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	GLint modelToWorldTransformMatrixUniformLocation =
		glGetUniformLocation(programID, "modelToWorldMatrix");*/

	

}

void MeOpenGl::mouseMoveEvent(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
	setFocus();
	repaint();
}

void MeOpenGl::keyPressEvent(QKeyEvent* e)
{
	switch (e->key())
	{
	case Qt::Key::Key_W:
		camera.moveForward();
		break;
	case Qt::Key::Key_S:
		camera.moveBackward();
		break;
	case Qt::Key::Key_A:
		camera.strafeLeft();
		break;
	case Qt::Key::Key_D:
		camera.strafeRight();
		break;
	case Qt::Key::Key_R:
		camera.moveUp();
		break;
	case Qt::Key::Key_F:
		camera.moveDown();
		break;
	}
	repaint();
}