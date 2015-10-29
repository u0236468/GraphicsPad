#ifndef ME_OPEN_GL_H
#define ME_OPEN_GL_H
#include <QtOpenGL\qglwidget>
#include <Qt\qtimer.h>

class MeOpenGl : public QGLWidget
{
	Q_OBJECT 

	GLuint torusVertexBufferID;
	GLuint torusIndexBufferID;
	GLuint sphereVertexBufferID;
	GLuint sphereIndexBufferID;
	GLuint planeVertexBufferID;
	GLuint planeIndexBufferID;
	GLuint programID;
	//GLfloat rotationAmount = 0.0f;
	//uint numIndices;
	float rotationAmount;

	QTimer myTimer;

	void loadDataPlane();
	//void loadDataSphere();
	void installShaders();
	void sendDownUniform(float rotationAmount);

protected:
	void initializeGL();
	void paintGL();
	void mouseMoveEvent(QMouseEvent*);
	void keyPressEvent(QKeyEvent*);
public:
	MeOpenGl() {}
private slots:
	void myUpdate();
};

#endif