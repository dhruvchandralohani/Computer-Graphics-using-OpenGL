#include <GL/glut.h>
#include <iostream>
using namespace std;

int X1 = 200, Y1 = 100, X2 = 100, Y2 = 200, X3 = 200, Y3 = 300, X4 = 300, Y4 = 200;
int Xcord[1080], Ycord[1080], i, j, flag = 1;

void init(void)
{
	glClearColor(0.8, 0.7, 0.9, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1080.0, 0.0, 720.0);
}

void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
}

void ScanLineIntersection(GLint x1, GLint y1, GLint x2, GLint y2)
{
	if(y2 < y1)
	{
		int temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	int x = x1;
	int slope = (y2 - y1) / (x2 - x1);
	for(i = y1; i < y2; i++)
	{
		if(x < Xcord[i])
			Xcord[i] = x;
		if(x > Ycord[i])
			Ycord[i] = x;
		x = x + (1 / slope);
	}
}

void polygon(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
		glVertex2i(x3, y3);
		glVertex2i(x4, y4);
	glEnd();
}

void picture(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	polygon(X1, Y1, X2, Y2, X3, Y3, X4, Y4);
	for(i = 0; i < 1080; i++)
		Xcord[i] = 1080;
	for(j = 0; j < 1080; j++)
		Ycord[j] = 0;
	ScanLineIntersection(X1, Y1, X2, Y2);
	ScanLineIntersection(X2, Y2, X3, Y3);
	ScanLineIntersection(X3, Y3, X4, Y4);
	ScanLineIntersection(X4, Y4, X1, Y1);
	for (i = 0; i < 1080; i++)
	{
		if (Xcord[i] < Ycord[i])
		{
			for (j = Xcord[i]; j < Ycord[i]; j++)
			{
				glColor3f(0.3, 0.3, 0.3);
				glBegin(GL_POINTS);
					glVertex2f(j, i);
				glEnd();
			}
		}
	}
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
	cin>>Y4;*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(143, 24);
	glutInitWindowSize(1080, 720);
	glutCreateWindow("Scan-Line Polygon Filling");
	init();
	glutDisplayFunc(picture);
	glutMainLoop();
}
