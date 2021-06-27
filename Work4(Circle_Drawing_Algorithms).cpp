#include <GL/glut.h>
#include <iostream>
using namespace std;

int centreXcord, centreYcord, radius;

void init(void)
{
	glClearColor(0.8, 0.7, 0.9, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-540, 540, -360, 360);
}

void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}

void MidPointCircle(GLint x0, GLint y0, GLint rad)
{
	int x = 0, y = rad;
	int deciP = 1 - rad;
	glColor3f(0.0, 0.0, 0.5);
	while(x <= y)
	{
		x++;
		if(deciP < 0)
			deciP = deciP + (2 * (x + 1)) + 1;
		else
		{
			y--;
			deciP = deciP + (2 * (x - y)) + 1;
		}
		setPixel(x + x0, y + y0);
		setPixel(-x + x0, y + y0);
		setPixel(x + x0, -y + y0);
		setPixel(-x + x0, -y + y0);
		setPixel(y + x0, x + y0);
		setPixel(-y + x0, x + y0);
		setPixel(y + x0, -x + y0);
		setPixel(-y + x0, -x + y0);
	}
}

void picture(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	MidPointCircle(centreXcord, centreYcord, radius);
	glFlush();
}

int main(int argc, char ** argv)
{
	cout<<"Range of x is -540 to 540 and Range of y is -360 to 360\n";
	cout<<"Enter the X-coordinate of centre:";
	cin>>centreXcord;
	cout<<endl<<"Enter the Y-coordinate of centre:";
	cin>>centreYcord;
	cout<<endl<<"Enter the Radius to draw circle:";
	cin>>radius;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(143, 24);
	glutInitWindowSize(1080, 720);
	glutCreateWindow("Circle Drawing Algorithms");
	init();
	glutDisplayFunc(picture);
	glutMainLoop();
}
