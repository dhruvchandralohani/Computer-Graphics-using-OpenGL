#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

float xStrtp, yStrtp, xEndp, yEndp;

void init(void)
{
	glClearColor(0.8, 0.7, 0.9, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1080.0, 0.0, 720.0);
}

void setPixel(GLfloat x, GLfloat y)
{
	glBegin(GL_POINTS);
		glVertex2f(x, y);
	glEnd();
}

void DDA(GLfloat x0, GLfloat y0, GLfloat xEnd, GLfloat yEnd)
{
	float i, steps;
	float dx = xEnd - x0, dy = yEnd - y0;
	float xIncrement = x0, yIncrement = y0 , x = x0, y = y0;
	if(fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xIncrement = dx/steps;
	yIncrement = dy/steps;
	glColor3f(0.5, 0.0, 0.0);
	setPixel(x, y);
	for(i = 0; i < steps; i++)
	{
		x = x + xIncrement;
		y = y + yIncrement;
		setPixel(x, y);
	}
}

void Bresenham(GLfloat x0, GLfloat y0, GLfloat xEnd, GLfloat yEnd)
{
	int dx = xEnd - x0, dy = yEnd - y0;
	int slope = dy/dx;
	int x = x0, y = y0;
	glColor3f(0.0, 0.5, 0.0);
	if(slope < 1)
	{
		int deciP = 2 * dy - dx;
		setPixel(x, y);
		while(x < xEnd)
		{
			x++;
			if(deciP <= 0)
				deciP = deciP + 2 * dy;
			else
			{
				y++;
				deciP = deciP + 2 * (dy - dx);
			}
			setPixel(x, y);
		}
	}
	else
	{
		int deciP = 2 * dx - dy;
		while(y < yEnd)
		{
			y++;
			if(deciP <= 0)
				deciP = deciP + 2 * dx;
			else
			{
				x++;
				deciP = deciP + 2 * (dx - dy);
			}
			setPixel(x, y);
		}
	}
}

void picture(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	DDA(xStrtp, yStrtp, xEndp, yEndp);
	Bresenham(xStrtp + xEndp, yStrtp, xEndp + xEndp, yEndp);
	glFlush();
}

int main(int argc, char** argv)
{
	cout<<"Range of x is 0 to 1080 and Range of y is 0 to 720\n";
	cout<<"Enter the x-coordinate of starting point:";
	cin>>xStrtp;
	cout<<endl<<"Enter the y-coordinate of starting point:";
	cin>>yStrtp;
	cout<<endl<<"Enter the x-coordinate of ending point:";
	cin>>xEndp;
	cout<<endl<<"Enter the y-coordinate of ending point:";
	cin>>yEndp;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(143, 24);
	glutInitWindowSize(1080, 720);
	glutCreateWindow("Line Drawing Algorithms");
	init();
	glutDisplayFunc(picture);
	glutMainLoop();
}
