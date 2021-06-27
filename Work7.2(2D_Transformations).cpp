#include <GL/glut.h>
#include <iostream>
#include <math.h>
using namespace std;

GLint X1 = 100, Y1 = 50, Z1 = 1, X2 = 200, Y2 = 250, Z2 = 1, X3 = 140, Y3 = 300, Z3 = 1, X4 = 115, Y4 = 275, Z4 = 1, tx = 300, ty = 100;
GLdouble theta = 0.72 , sX = 2, sY = 2;

void init(void)
{
	glClearColor(0.8, 0.7, 0.9, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1080.0, 0.0, 720.0);
}

void setPixel(GLint x, GLint y, GLint z)
{
	glBegin(GL_POINTS);
		glVertex3i(x, y, z);
	glEnd();
}

void polygon(GLint x1, GLint y1, GLint z1, GLint x2, GLint y2, GLint z2, GLint x3, GLint y3, GLint z3, GLint x4, GLint y4, GLint z4)
{
	glBegin(GL_POLYGON);
		glVertex3i(x1, y1, z1);
		glVertex3i(x2, y2, z2);
		glVertex3i(x3, y3, z3);
		glVertex3i(x4, y4, z4);
	glEnd();
}

void translate(GLint tx, GLint ty)
{
	polygon(X1 + tx, Y1 + ty, Z1, X2 + tx, Y2 + ty, Z2, X3 + tx, Y3 + ty, Z3, X4 + tx, Y4 + ty, Z4);
}

void rotate(GLdouble angle)
{
	GLint x1 , y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4;
	x1 = (X1 + tx) * cos(angle) - (Y1 + ty) * sin(angle);
	y1 = (X1 + tx) * sin(angle) + (Y1 + ty) * cos(angle);
	z1 = 1;
	x2 = (X2 + tx) * cos(angle) - (Y2 + ty) * sin(angle);
	y2 = (X2 + tx) * sin(angle) + (Y2 + ty) * cos(angle);
	z2 = 1;
	x3 = (X3 + tx) * cos(angle) - (Y3 + ty) * sin(angle);
	y3 = (X3 + tx) * sin(angle) + (Y3 + ty) * cos(angle);
	z3 = 1;
	x4 = (X4 + tx) * cos(angle) - (Y4 + ty) * sin(angle);
	y4 = (X4 + tx) * sin(angle) + (Y4 + ty) * cos(angle);
	z4 = 1;
	polygon(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4);
}

void scale(GLint sx, GLint sy)
{
	polygon(X1 * sx, Y1 * sy, Z1, X2 * sx, Y2 * sy, Z2, X3 * sx, Y3 * sy, Z3, X4 * sx, Y4 * sy, Z4);
}

void picture(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	polygon(X1, Y1, Z1, X2, Y2, Z2, X3, Y3, Z3, X4, Y4, Z4);
	glColor3f(0.5, 0.0, 0.0);
	translate(tx, ty);
	glColor3f(0.0, 0.5, 0.0);
	rotate(theta);
	glColor3f(0.0, 0.0, 0.5);
	scale(sX, sY);
	glFlush();
}

int main(int argc, char ** argv)
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
	glutCreateWindow("2D Transformations");
	init();
	glutDisplayFunc(picture);
	glutMainLoop();
}
