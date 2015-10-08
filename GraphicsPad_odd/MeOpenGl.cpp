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
#include <glm\gtx\transform.hpp>
using namespace std;
using std::cout;
using std::endl;
//extern const char* vertexShaderCode;
//extern const char* fragmentShaderCode;

void MeOpenGl::loadData()
{
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
	};

	GLushort Indices[] = {  //indices are to tell us how the vertices are connected.
		0, 1, 2, 0, 2, 3, // Top
		4, 5, 6, 4, 6, 7, // Front
		8, 9, 10, 8, 10, 11, // Right 
		12, 13, 14, 12, 14, 15, // Left
		16, 17, 18, 16, 18, 19, // Back
		20, 22, 21, 20, 23, 22, // Bottom
	};

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
	
	glGenBuffers(1, &vertexBufferID);
	glGenBuffers(1, &indexBufferID);

	glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(Indices), Indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, 0);  //This explains the data to the shader
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(3 * sizeof(float)));

	connect(&myTimer, SIGNAL(timeout()), this, SLOT(myUpdate()));
	myTimer.start(100);
}

/*bool checkStatus(
	GLuint objectID,
	PFNGLGETSHADERIVPROC objectPropertyGetter,
	PFNGLGETSHADERINFOLOGPROC getInfoLogFunc,
	GLenum statusType)
{*/

bool checkShaderStatus(GLuint shaderID)
{
	GLint compileStatus;
	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &compileStatus);
	if (compileStatus != GL_TRUE)
	{
		GLint infoLogLength;
		glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = new GLchar[infoLogLength];

		GLsizei bufferSize;
		glGetShaderInfoLog(shaderID, infoLogLength, &bufferSize, buffer);
		cout << buffer << endl;

		delete[] buffer;
		return false;
	}
	return true;
}

bool checkProgramStatus(GLuint programID)
{
	GLint linkStatus;
	glGetProgramiv(programID, GL_LINK_STATUS, &linkStatus);
	if (linkStatus != GL_TRUE)
	{
		GLint infoLogLength;
		glGetProgramiv(programID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* buffer = new GLchar[infoLogLength];

		GLsizei bufferSize;
		glGetProgramInfoLog(programID, infoLogLength, &bufferSize, buffer);
		cout << buffer << endl;

		delete[] buffer;
		return false;
	}
	return true;
}

void MeOpenGl::installShaders()
{
	// I have completed what you need in this playlist up until
	// this video: https://www.youtube.com/watch?v=-N-ncMdwfAU&list=PLRwVmtr-pp06qT6ckboaOhnm9FxmzHpbY&index=12

	// You fill this in...
	
	const char* vertexShaderCode = ""
		"#version 400\r\n"
		""
		"in layout(location=0) vec3 position;"  //varrying data
		"in layout(location=1) vec4 vertexColor;" //varrying data 
		""
		"out vec4 daColor;"// declare var - we need to send the color out to the hardware to interpulate
		""
		"uniform mat4 mvp;" //uniform means the value will be the same for every single vertex
		""
		"void main()"
		"{"
		"	gl_Position = mvp * vec4(position, 1);"
		"	daColor = vertexColor;"
		"}";
	const char* fragmentShaderCode = ""
		"#version 400\r\n"
		""
		"out vec4 fragColor;"
		"in vec4 daColor;"
		""
		"void main()"
		"{"
		"	fragColor = daColor;"
		"}"
		""
		;


	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

	// You fill this in. You will need these functions.
	// Helpful videos in that playlist: #16 and #17
	const char* adapter[1];
	adapter[0] = vertexShaderCode;
	glShaderSource(vertexShaderID, 1, adapter, 0);
	adapter[0] = fragmentShaderCode;
	glShaderSource(fragmentShaderID, 1, adapter, 0);

	glCompileShader(vertexShaderID);
	glCompileShader(fragmentShaderID);

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

void MeOpenGl::sendDownUniform()
{
	GLuint uniformLocation = glGetUniformLocation(programID, "mvp");

	glm::mat4 translate = glm::translate(0.0f, 0.0f, -5.0f);
	
	rotationAmount += 1.0f;
	//glm::mat4 modelToWorld = glm::scale(0.5f, 1.0f, 1.0f) * 
	glm::mat4 rotate = glm::rotate(rotationAmount, 1.0f, 0.0f, 0.0f) * glm::rotate(rotationAmount, 0.0f, 1.0f, 0.0f);
	
	/*glm::mat4 worldToView = glm::lookAt(
		glm::vec3(5.0f, 3.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f));*/

	glm::mat4 perspective = glm::perspective(60.0f, ((float)width()) / height(), 0.1f, 15.0f); //changed 100.0f to 1|||||5.0f

	//glm::mat4 mvp = modelToWorld * worldToView * viewToProjection;
	glm::mat4 mvp = perspective *translate * rotate;

	//GLint location = glGetUniformLocation(programID, "mvp");

	//glUniformMatrix4fv(location, 1, GL_FALSE, &mvp[0][0]);
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, &mvp[0][0]);

	//glm::mat4 translate = glm::translate(0.0f, 0.0f, -5.0f);
	//glm::mat4 rotate = glm::rotate(45.0f, 1.0f, 0.0f) * glm::rotate(45.0f, 1.0f, 0.0f); //rotate 45 degrees around the x, then the Y

}

void MeOpenGl::myUpdate()
{
	sendDownUniform();
	repaint();
}

void MeOpenGl::initializeGL()
{
	QGLWidget::initializeGL();
	GLenum errorCode = glewInit();
	if (errorCode != GLEW_OK)
		return;
	installShaders();
	loadData();
	sendDownUniform();

	glEnable(GL_DEPTH_TEST);
}

void MeOpenGl::paintGL()
{
	glViewport(0, 0, width(), height());
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, 0); // there are 6 indices for one side of the cube, 3 for each triabngle
}