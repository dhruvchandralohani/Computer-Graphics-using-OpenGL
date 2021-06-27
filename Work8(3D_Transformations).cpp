#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

GLint i, j, k;
GLfloat X1 = 1.0, Y1 = -1.0, Z1 = 1.0, X2 = 1.0, Y2 = 1.0, Z2 = 1.0, X3 = -1.0, Y3 = 1.0, Z3 = 1.0, X4 = -1.0, Y4 = -1.0, Z4 = 1.0;
GLfloat X5 = -1.0, Y5 = -1.0, Z5 = -1.0, X6 = -1.0, Y6 = 1.0, Z6 = -1.0, X7 = 1.0, Y7 = 1.0, Z7 = -1.0, X8 = 1.0, Y8 = -1.0, Z8 = -1.0;
GLfloat tx = 0.0, ty = 0.0, tz = 10.0;
GLfloat theta = -45;
GLfloat sx = 0.5, sy = 1.0, sz;
GLfloat original[8][4] = { {X1, Y1, Z1, 1}, {X2, Y2, Z2, 1}, {X3, Y3, Z3, 1}, {X4, Y4, Z4, 1}, {X5, Y5, Z5, 1}, {X6, Y6, Z6, 1}, {X7, Y7, Z7, 1}, {X8, Y8, Z8, 1}};
GLfloat translation[4][4] = { {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0},  {tx, ty, tz, 1} };
GLfloat rotation_about_X[4][4] = { {1, 0, 0, 0}, {0, cos(theta), sin(theta), 0}, {0, -sin(theta), cos(theta), 0}, {0, 0, 0, 1} };
GLfloat rotation_about_Y[4][4] = { {cos(theta), sin(theta), 0, 0}, {-sin(theta), cos(theta), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1} };
GLfloat rotation_about_Z[4][4] = { {cos(theta), 0, -sin(theta), 0}, {0, 1, 0, 0}, {sin(theta) , 0, cos(theta), 0}, {0, 0, 0, 1} };
GLfloat scaling[4][4] = { {sx, 0, 0, 0}, {0, sy, 0, 0}, {0, 0, sz, 0}, {0, 0, 0, 1} };
GLfloat result[8][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };
GLfloat final_result[8][4] = { {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0} };

GLvoid init()
{
	glClearColor(0.8, 0.7, 0.9, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
}

GLvoid polygon(GLfloat mat[8][4])
{
	glBegin(GL_QUADS);
		//front face
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(mat[0][0], mat[0][1], mat[0][2]);
		glVertex3f(mat[1][0], mat[1][1], mat[1][2]);
		glVertex3f(mat[2][0], mat[2][1], mat[2][2]);
		glVertex3f(mat[3][0], mat[3][1], mat[3][2]);
		//back face
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(mat[4][0], mat[4][1], mat[4][2]);
		glVertex3f(mat[5][0], mat[5][1], mat[5][2]);
		glVertex3f(mat[6][0], mat[6][1], mat[6][2]);
		glVertex3f(mat[7][0], mat[7][1], mat[7][2]);
		//right face
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(mat[0][0], mat[0][1], mat[0][2]);
		glVertex3f(mat[1][0], mat[1][1], mat[1][2]);
		glVertex3f(mat[6][0], mat[6][1], mat[6][2]);
		glVertex3f(mat[7][0], mat[7][1], mat[7][2]);
		//left face
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(mat[3][0], mat[3][1], mat[3][2]);
		glVertex3f(mat[2][0], mat[2][1], mat[2][2]);
		glVertex3f(mat[5][0], mat[5][1], mat[5][2]);
		glVertex3f(mat[4][0], mat[4][1], mat[4][2]);
		//top face
		glColor3f(1.0, 0.0, 1.0);
		glVertex3f(mat[1][0], mat[1][1], mat[1][2]);
		glVertex3f(mat[2][0], mat[2][1], mat[2][2]);
		glVertex3f(mat[5][0], mat[5][1], mat[5][2]);
		glVertex3f(mat[6][0], mat[6][1], mat[6][2]);
		//bottom face
		glColor3f(0.0, 1.0, 1.0);
		glVertex3f(mat[0][0], mat[0][1], mat[0][2]);
		glVertex3f(mat[3][0], mat[3][1], mat[3][2]);
		glVertex3f(mat[4][0], mat[4][1], mat[4][2]);
		glVertex3f(mat[7][0], mat[7][1], mat[7][2]);
	glEnd();
}

GLvoid multiply(GLfloat matRslt[8][4], GLfloat matOrig[8][4], GLfloat matTrnsfrm[4][4])
{
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 4; j++)
		{
			GLfloat sum = 0;
			for(k = 0; k < 4; k++)
				sum = sum + matOrig[i][k] * matTrnsfrm[k][j];
			matRslt[i][j] = sum;
		}
	}
}

GLvoid picture(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//polygon(original);								this will not be visible since it is behind the near clip window.
	multiply(result, original, translation);			//translating the figure (-5) in z axis to make it visible.
	for(i = 0; i < 8; i++)
	{
		for(j = 0; j < 3; j++)
		{
			final_result[i][j] = result[i][j];
			result[i][j] = 0;
		}
	}
	multiply(result, final_result, rotation_about_X);
	gluPerspective(60, 1, 1.1, 50.0);
	polygon(result);
	/*multiply(result, original, rotation_about_Y);
	polygon(result);
	multiply(result, original, rotation_about_Z);
	polygon(result);
	glColor3f(0.0, 0.0, 0.5);
	multiply(result, original, scaling);
	polygon(result);*/
	glFlush();
	glutSwapBuffers();
}

GLint main(GLint argc, GLchar ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB |GLUT_DEPTH);
	glutInitWindowPosition(143, 24);
	glutInitWindowSize(500, 500);
	glutCreateWindow("2D - Transformations");
	init();
	glutDisplayFunc(picture);
	glutMainLoop();
}
