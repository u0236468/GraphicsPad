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
//#include <Vertex.h>
#include "Camera.h"

using namespace std;
using glm::vec3;
using glm::vec4; 
using glm::mat4;

const uint NUM_VERTICES_PER_TRI = 3;
const uint NUM_FLOATS_PER_VERTICE = 9;
const uint VERTEX_BYTE_SIZE = NUM_FLOATS_PER_VERTICE * sizeof(float);
GLuint programID;
GLuint numIndices;
Camera camera;
GLuint passThroughProgramID;
//using std::cout;
//using std::endl;

void MeOpenGl::loadData()
{
	ShapeData plane = ShapeGenerator::makePlane(10);
	ShapeData sphere = ShapeGenerator::makeSphere(10);

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
	
	
	//GLshort indices[] = { 0, 1, 2 };
	GLuint theBufferID;
	glGenBuffers(1, &vertexBufferID);
	glGenBuffers(1, &indexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	//Changes for the AO and Diffuse
	//glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, plane.vertexBufferSize(), plane.verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	//Chagnes for the AO and Diffuse
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, plane.indexBufferSize(), plane.indices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, theBufferID);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	//Chagnes for the AO and Diffuse
	//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, 0);  //This explains the data to the shader
	glBindBuffer(GL_ARRAY_BUFFER, theBufferID);
	GLuint sphereByteOffset;
	GLuint planeByteOffset = sphereByteOffset + sphere.vertexBufferSize() + sphere.indexBufferSize();
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_BYTE_SIZE, (void*)planeByteOffset); //sizeof(Vertex), 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, VERTEX_BYTE_SIZE, (void*)(planeByteOffset + sizeof(float)));
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, VERTEX_BYTE_SIZE, (void*)(planeByteOffset + sizeof(float)));
	//glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	//glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	numIndices = plane.numIndices;
	plane.cleanup();
	sphere.cleanup();

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
	
	//const char* vertexShaderCode = ""

	//const char* fragmentShaderCode = ""

	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// You fill this in. You will need these functions.
	// Helpful videos in that playlist: #16 and #17
	const GLchar* adapter[1];
	string temp = readShaderCode("VertexShaderCode.glsl");
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	temp = readShaderCode("FragmentShaderCode.glsl");
	adapter[0] = temp.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	if (!checkShaderStatus(vertexShaderID) || !checkShaderStatus(fragmentShaderID))
		return;

	programID = glCreateProgram();
	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);
	glLinkProgram(programID);

	//GLint compileStatus;
	//glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &compileStatus);
	/*if (compileStatus != GL_TRUE)
	{
		GLint infoLogLength;
		glGetShaderiv(vertexShaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = new GLchar[infoLogLength];

		GLsizei bufferSize;
		glGetShaderInfoLog(vertexShaderID, infoLogLength, &bufferSize, buffer);
		cout << buffer << endl;

		delete[] buffer;

	}*/

	/*passThroughProgramID = glCreateProgram();
	glAttachShader(passThroughProgramID, vertexShaderID);
	glAttachShader(passThroughProgramID, fragmentShaderID);
	glLinkProgram(passThroughProgramID);
	
	if (!checkProgramStatus(passThroughProgramID))
	return;*/

	if (!checkProgramStatus(programID))
		return;

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	temp = readShaderCode("VertexShaderPassThroughCode.glsl");
	adapter[0] = temp.c_str();
	glShaderSource(vertexShaderID, 1, adapter, 0);
	temp = readShaderCode("FragmentShaderPassThroughCode.glsl");
	adapter[0] = temp.c_str();
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

	passThroughProgramID = glCreateProgram();
	glAttachShader(passThroughProgramID, vertexShaderID);
	glAttachShader(passThroughProgramID, fragmentShaderID);
	glLinkProgram(passThroughProgramID);

	if (!checkProgramStatus(passThroughProgramID))
		return;

	//glUseProgram(programID);


}

void MeOpenGl::sendDownUniform()
{
	GLuint uniformLocation = glGetUniformLocation(programID, "mvp");

	//glm::mat4 translate = glm::translate(0.0f, 0.0f, -5.0f);
	
	//rotationAmount += 1.0f;
	//glm::mat4 modelToWorld = glm::scale(0.5f, 1.0f, 1.0f) * 
	//glm::mat4 rotate = glm::rotate(rotationAmount, 1.0f, 0.0f, 0.0f) * glm::rotate(rotationAmount, 0.0f, 1.0f, 0.0f);
	
	/*glm::mat4 worldToView = glm::lookAt(
		glm::vec3(5.0f, 3.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));*/

	glm::mat4 perspective = glm::perspective(120.0f, ((float)width()) / height(), 0.1f, 15.0f); //changed 100.0f to 1|||||5.0f

	//glm::mat4 mvp = modelToWorld * worldToView * viewToProjection;
	glm::mat4 mvp = perspective * glm::lookAt(
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, -1.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));// *translate * rotate;

	//GLint location = glGetUniformLocation(programID, "mvp");

	//glUniformMatrix4fv(location, 1, GL_FALSE, &mvp[0][0]);
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &mvp[0][0]);

	GLint ambientLightUniformLocation = glGetUniformLocation(programID, "ambientLight");
	glm::vec3 ambientLight(0.9f, 0.5f, 0.5f);
	glUniform3fv(ambientLightUniformLocation, 1, &ambientLight[0]);

	GLint lightPositionUniformLocation = glGetUniformLocation(programID, "lightPosition");
	glm::vec3 lightPosition(0.0f, 1.0f, 0.0f);
	glUniform3fv(lightPositionUniformLocation, 1, &lightPosition[0]);

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
	sendDownUniform();
	repaint();
}

void MeOpenGl::initializeGL()
{
	setMouseTracking(true);
	QGLWidget::initializeGL();
	GLenum errorCode = glewInit();
	if (errorCode != GLEW_OK)
		return;
	resize(width() * 1.2f, height() *1.3f);
	glewInit();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	sendDownUniform();
	installShaders();
	//loadData();
	
	fullTransformUniformLocation = glGetUniformLocation(programID, "modelToProjectionMatrix");
}

MeOpenGl::MeOpenGl()
{
	glDeleteBuffers(1, &theBufferID);
	glUseProgram(0);
	glDeleteProgram(programID);
}

void MeOpenGl::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT); //could do glCear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, width(), height());

	glm::vec3 lightPositionWorld(0.0f, 2.0f, 0.0f);

	mat4 modelToProjectionMatrix;
	mat4 viewToProjectionMatrix = glm::perspective(60.0f, ((float)width()) / height(), 0.1f, 20.0f);
	mat4 worldToViewMatrix = camera.getWorldToViewMatrix();
	mat4 worldToProjectionMatrix = viewToProjectionMatrix * worldToViewMatrix;

	GLint modelToWorldTransformMatrixUniformLocation =
		glGetUniformLocation(programID, "modelToWorldMatrix");

	/*GLint ambientLightUniformLocation = glGetUniformLocation(programID, "ambientLight");
	vec4 ambientLight(0.3f, 0.3f, 0.3f, 1.0f);
	glUniform4fv(ambientLightUniformLocation, 1, &ambientLight[0]);
	GLint lightPositionUniformLocation = glGetUniformLocation(programID, "lightPositionWorld");
	glm::vec3 lightPositionWorld(0.0f, 1.0f, 0.0f);
	glUniform3fv(lightPositionUniformLocation, 1, &lightPositionWorld[0]);*/

	//Cube
	/*glBindVertexArray(cubeVertexArrayObjectID);
	mat4 cubeModelToWorldMatrix =
		glm::translate(lightPositionWorld)*
		glm::scale(0.1f, 0.1f, 0.1f);
	modelToProjectionMatrix = worldToProjectionMatrix * cubeModelToWorldMatrix;
	GLint modelToProjectionMatrixUniformLocation =
		glGetUniformLocation(passThroughProgramID, "modelToProjectionMatrix");
	glUseProgram(passThroughProgramID);
	glUniformMatrix4fv(modelToProjectionMatrixUniformLocation, 1, GL_FALSE,
		&modelToProjectionMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, cubeNumIndices, GL_UNSIGNED_SHORT, (void*)cubeIndexDataByteOffset);*/

	//Sphere

	//Arrow translated
	/*glUseProgram(programID);
	glBindVertexArray(arrowVertexArrayObjectID);
	mat4 arrowModelToWorldMatrix =
		glm::translate(0.0f, 2.0f, -8.0f) *
		glm::rotate(-90.0f, 1.0f, 0.0f, 0.0f);
	modelToProjectionMatrix = worldToProjectionMatrix * arrowModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformUniformLocation, 1, GL_FALSE, &fullTransformMatrix[0][0]);
	glUniformMatrix4fv(modelToWorldTransformMatrixUniformLocaiton, 1, GL_FALSE,
		&arrowModelToWorldMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, arrowNumIndices, GL_UNSIGNED_SHORT, (void*)arrowIndexData);

	//Arrow centered
	arrowModelToWorldMatrix = mat4();
	modelToProjectionMatrix = worldToProjectionMatrix * arrowModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformUniformLocation, 1, GL_FALSE, &modelToProjectionMatrix[0][0]);
	glUniformMatrix4fv(modelToWorldTransformMatrixUniformLocaiton, 1, GL_FALSE,
		&arrowModelToWorldMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, arrowNumIndices, GL_UNSIGNED_SHORT, (void*)arrowIndexData);*/

	//Plane
	/*glUseProgram(programID);
	GLint ambientLightUniformLocation = glGetUniformLocation(programID, "ambientLight");
	vec4 ambientLight(0.05f, 0.05f, 0.05f, 1.0f);
	glUniform4fv(ambientLightUniformLocation, 1, &ambientLight[0]);
	GLint eyePositionWorldUniformLocation = glGetUniformLocation(programID, "eyePositionWorld");
	glm::vec3 eyePosition = camera.getPosition();
	glUniform3fv(eyePositionWorldUniformLocation, 1, &eyePosition[0]);
	GLint lightPositionUniformLocation = glGetUniformLocation(programID, "lightPositionWorld");
	glUniform3fv(lightPositionUniformLocation, 1, &lightPositionWorld[0]);

	glBindVertexArray(planeVertexArrayObjectID);
	mat4 planeModelToWorldMatrix;
	modelToProjectionMatrix = worldToProjectionMatrix * planeModelToWorldMatrix;
	glUniformMatrix4fv(fullTransformUniformLocation, 1, GL_FALSE, &modelToProjectionMatrix[0][0]);
	glUniformMatrix4fv(modelToWorldTransformMatrixUniformLocaiton, 1, GL_FALSE,
		&planeModelToWorldMatrix[0][0]);
	glDrawElements(GL_TRIANGLES, planeNumIndices, GL_UNSIGNED_SHORT, (void*)planeIndexData);*/




	//glViewport(0, 0, width(), height());
	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glClear(GL_DEPTH_BUFFER_BIT);
	//glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, 0); // there are 6 indices for one side of the cube, 3 for each triabngle
	//glDrawElements(GL_TRIANGLES, torusNumIndices, GL_UNSIGNED_SHORT, (void*)torusIndexDataByteOffset);
}

void MeOpenGl::mouseMoveEvent(QMouseEvent* e)
{
	camera.mouseUpdate(glm::vec2(e->x(), e->y()));
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