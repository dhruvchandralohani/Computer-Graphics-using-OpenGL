#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

GLint i, j, k;
GLfloat X1 = 500, Y1 = 150, X2 = 700, Y2 = 300, X3 = 540, Y3 = 400, X4 = 470, Y4 = 350;
GLfloat tx = 300, ty = 100;
GLfloat theta = 0.72;
GLfloat sx = 0.5, sy = 1.0;
GLfloat original[4][3] = { {X1, Y1, 1}, {X2, Y2, 1}, {X3, Y3, 1}, {X4, Y4, 1}};
GLfloat translation[3][3] = { {1, 0, 0}, {0, 1, 0}, {tx, ty, 1} };
GLfloat rotation[3][3] = { {cos(theta), sin(theta), 0}, {-sin(theta), cos(theta), 0}, {0, 0, 1} };
GLfloat scaling[3][3] = { {sx, 0, 0}, {0, sy, 0}, {0, 0, 1} };
GLfloat result[4][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0} };

GLvoid init()
{
	glClearColor(0.8, 0.7, 0.9, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1080.0, 0.0, 720);
}

GLvoid polygon(GLfloat mat[4][3])
{
	glBegin(GL_POLYGON);
		glVertex2f(mat[0][0], mat[0][1]);
		glVertex2f(mat[1][0], mat[1][1]);
		glVertex2f(mat[2][0], mat[2][1]);
		glVertex2f(mat[3][0], mat[3][1]);
	glEnd();
}

GLvoid multiply(GLfloat matRslt[4][3], GLfloat matOrig[4][3], GLfloat matTrnsfrm[3][3])
{
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 3; j++)
		{
			GLfloat sum = 0;
			for(k = 0; k < 3; k++)
				sum = sum + matOrig[i][k] * matTrnsfrm[k][j];
			matRslt[i][j] = sum;
		}
	}
}

GLvoid picture(GLvoid)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	polygon(original);
	glColor3f(0.5, 0.0, 0.0);
	multiply(result, original, translation);
	polygon(result);
	glColor3f(0.0, 0.5, 0.0);
	multiply(result, original, rotation);
	polygon(result);
	glColor3f(0.0, 0.0, 0.5);
	multiply(result, original, scaling);
	polygon(result);
	glFlush();
}

GLint main(GLint argc, GLchar ** argv)
{
	/*cout<<"Enter the coordinates of vertex to create a Polygon";
	cout<<"\nX1:";
	cin>>X1;
	cout<<"\nY1:";
	cin>>Y1;
	cout<<"\nX2:";
	cin>>X2;
	cout<<"\nY2:";
	cin>>Y2;
	cout<<"\nX3:";
	cin>>X3;
	cout<<"\nY3:";
	cin>>Y3;
	cout<<"\nX4:";
	cin>>X4;
	cout<<"\nY4:";
	cin>>Y4;
	cout<<"\nTranslation in X-axis:";
	cin>>tx;
	cout<<"\nTranslation in Y-axis:";
	cin>>ty;
	cout<<"\nAngle of Rotation:";
	cin>>theta;
	cout<<"\nScaling factor for x:";
	cin>>sX;
	cout<<"\nScaling factor for y:";
	cin>>sY;*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(143, 24);
	glutInitWindowSize(1080, 720);
	glutCreateWindow("2D - Transformations");
	init();
	glutDisplayFunc(picture);
	glutMainLoop();
}
