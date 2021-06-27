#include <GL/glut.h>
#include <iostream>
using namespace std;

int centreXcord, centreYcord, radiusY, radiusX;

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

void MidPointEllipse(GLint x0, GLint y0, GLint rady, GLint radx)
{
	glColor3f(0.0, 0.6, 0.0);
	int x, y, deciP;
	x = 0, y = rady;
	deciP = (rady * rady) - (radx * radx * rady) + ((1 / 4) * radx * radx);
	while(rady * rady * x <= radx * radx * y)
	{
		x++;
		if(deciP < 0)
			deciP = deciP + (2 * rady * rady * (x + 1)) + (rady * rady);
		else
		{
			y--;
			deciP = deciP + (2 * rady * rady * (x + 1)) - (2 * radx * radx * (y - 1)) + (rady * rady);
		}
		setPixel(x0 + x, y0 + y);
		setPixel(x0 - x, y0 + y);
		setPixel(x0 + x, y0 -y);
		setPixel(x0 - x, y0 -y);
	}
	deciP = (rady * rady * (x + (1 / 2)) * (x + (1/2))) + (radx * radx * (y - 1) *(y - 1)) - (radx * radx * rady * rady);
	while(y > 0)
	{
		y--;
		if(deciP > 0)
			deciP = deciP + (radx * radx) - (2 * radx * radx * (y -1));
		else
		{
			x++;
			deciP = deciP + (2 * rady * rady * (x + 1)) - (2 * radx * radx * (y -1)) + (radx * radx);
		}
		setPixel(x0 + x, y0 + y);
		setPixel(x0 - x, y0 + y);
		setPixel(x0 + x, y0 -y);
		setPixel(x0 - x, y0 -y);
	}
}

void picture(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	MidPointEllipse(centreXcord, centreYcord, radiusY, radiusX);
	glFlush();
}

int main(int argc, char ** argv)
{
	cout<<"Range of x is -540 to 540 and Range of y is -360 to 360\n";
	cout<<"Enter the X-coordinate of centre:";
	cin>>centreXcord;
	cout<<endl<<"Enter the Y-coordinate of centre:";
	cin>>centreYcord;
	cout<<endl<<"Enter the Radius on Y-axis of Ellipse:";
	cin>>radiusY;
	cout<<endl<<"Enter the Radius on X-axis of Ellipse:";
	cin>>radiusX;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(143, 24);
	glutInitWindowSize(1080, 720);
	glutCreateWindow("Ellipse Drawing Algorithms");
	init();
	glutDisplayFunc(picture);
	glutMainLoop();
}
