#ifndef ME_OPEN_GL_H
#define ME_OPEN_GL_H
#include <QtOpenGL\qglwidget>
#include <Qt\qtimer.h>

class MeOpenGl : public QGLWidget
{
	Q_OBJECT 

	GLuint vertexBufferID;
	GLuint indexBufferID;
	GLuint programID;
	//GLfloat rotationAmount = 0.0f;
	uint numIndices;
	float rotationAmount;

	QTimer myTimer;

	void loadData();
	void installShaders();
	void sendDownUniform(float rotationAmount);

protected:
	void initializeGL();
	void paintGL();
	//void mouseMoveEvent(QMouseEvent*);
	//void keyPressEvent(QKeyEvent*);
public:
	MeOpenGl() {}
private slots:
	void myUpdate();
};

#endif