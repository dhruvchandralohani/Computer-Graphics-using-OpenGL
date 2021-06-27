#include <GL/glut.h>
#include <iostream>
using namespace std;

float x0, y0 = 165, rady, radx, ynot = 0, xnot = 0, yo = 150;

void init(void)
{
	glClearColor(0.23, 0.26, 0.32, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-540, 540, -360, 360);
}

void setPixel(GLfloat x, GLfloat y)
{
	glBegin(GL_POINTS);
		glVertex2f(x, y);
	glEnd();
}

void background()
{
	//sun.
	glShadeModel(GL_SMOOTH);
	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.64, 0.0);
		glVertex2f(-540, -180);
		glColor3f(0.85, 0.64, 0.80);
		glVertex2f(-540, 360);
		glColor3f(0.85, 0.64, 0.80);
		glVertex2f(540, 360);
		glColor3f(0.85, 0.64, 0.80);
		glVertex2f(540, -180);
	glEnd();
	//clouds.
	glColor3f(1.0, 1.0, 1.0);
	x0 = -460;
	rady = 20;
	radx = 30;
	int x1, y1, deciP1;
	x1 = 0, y1 = rady;
	deciP1 = (rady * rady) - (radx * radx * rady) + ((1 / 4) * radx * radx);
	while(rady * rady * x1 <= radx * radx * y1)
	{
		x1++;
		if(deciP1 < 0)
			deciP1 = deciP1 + (2 * rady * rady * (x1 + 1)) + (rady * rady);
		else
		{
			y1--;
			deciP1 = deciP1 + (2 * rady * rady * (x1 + 1)) - (2 * radx * radx * (y1 - 1)) + (rady * rady);
		}
		//cloud1.
		setPixel(xnot + x0 - x1, yo + y1);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1, yo + y1);
			glVertex2f(xnot + x0 - x1, yo + y1);
		glEnd();
		setPixel(xnot + x0 - x1, yo -y1);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1, yo - y1);
			glVertex2f(xnot + x0 - x1, yo - y1);
		glEnd();
		
		setPixel(xnot + x0 - x1 + 10, yo + y1 - 20);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 10, yo + y1 - 20);
			glVertex2f(xnot + x0 - x1 + 10, yo + y1 - 20);
		glEnd();
		setPixel(xnot + x0 - x1 + 10, yo -y1 - 20);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 10, yo - y1 - 20);
			glVertex2f(xnot + x0 - x1 + 10, yo - y1 - 20);
		glEnd();
		
		setPixel(xnot + x0 - x1 - 10, yo + y1 - 20);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 - 10, yo + y1 - 20);
			glVertex2f(xnot + x0 - x1 - 10, yo + y1 - 20);
		glEnd();
		setPixel(xnot + x0 - x1 - 10, yo -y1 - 20);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 - 10, yo - y1 - 20);
			glVertex2f(xnot + x0 - x1 - 10, yo - y1 - 20);
		glEnd();
		//cloud2.
		setPixel(xnot + x0 - x1 + 300, yo + y1 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 300, yo + y1 + 100);
			glVertex2f(xnot + x0 - x1 + 300, yo + y1 + 100);
		glEnd();
		setPixel(xnot + x0 - x1 + 300, yo - y1 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 300, yo - y1 + 100);
			glVertex2f(xnot + x0 - x1 + 300, yo - y1 + 100);
		glEnd();
		
		setPixel(xnot + x0 - x1 + 10 + 300, yo + y1 - 20 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 10 + 300, yo + y1 - 20 + 100);
			glVertex2f(xnot + x0 - x1 + 10 + 300, yo + y1 - 20 + 100);
		glEnd();
		setPixel(xnot + x0 - x1 + 10 + 300, yo -y1 - 20 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 10 + 300, yo - y1 - 20 + 100);
			glVertex2f(xnot + x0 - x1 + 10 + 300, yo - y1 - 20 + 100);
		glEnd();
		
		setPixel(xnot + x0 - x1 - 10 + 300, yo + y1 - 20 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 - 10 + 300, yo + y1 - 20 + 100);
			glVertex2f(xnot + x0 - x1 - 10 + 300, yo + y1 - 20 + 100);
		glEnd();
		setPixel(xnot + x0 - x1 - 10 + 300, yo -y1 - 20 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 - 10 + 300, yo - y1 - 20 + 100);
			glVertex2f(xnot + x0 - x1 - 10 + 300, yo - y1 - 20 + 100);
		glEnd();
	}
	deciP1 = (rady * rady * (x1 + (1 / 2)) * (x1 + (1/2))) + (radx * radx * (y1 - 1) *(y1 - 1)) - (radx * radx * rady * rady);
	while(y1 > 0)
	{
		y1--;
		if(deciP1 > 0)
			deciP1 = deciP1 + (radx * radx) - (2 * radx * radx * (y1 -1));
		else
		{
			x1++;
			deciP1 = deciP1 + (2 * rady * rady * (x1 + 1)) - (2 * radx * radx * (y1 -1)) + (radx * radx);
		}
		//cloud1.
		setPixel(xnot + x0 - x1, yo + y1);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1, yo + y1);
			glVertex2f(xnot + x0 - x1, yo + y1);
		glEnd();
		setPixel(xnot + x0 - x1, yo -y1);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1, yo - y1);
			glVertex2f(xnot + x0 - x1, yo - y1);
		glEnd();
		
		setPixel(xnot + x0 - x1 + 10, yo + y1 - 20);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 10, yo + y1 - 20);
			glVertex2f(xnot + x0 - x1 + 10, yo + y1 - 20);
		glEnd();
		setPixel(xnot + x0 - x1 + 10, yo -y1 - 20);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 10, yo - y1 - 20);
			glVertex2f(xnot + x0 - x1 + 10, yo - y1 - 20);
		glEnd();
		
		setPixel(xnot + x0 - x1 - 10, yo + y1 - 20);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 - 10, yo + y1 - 20);
			glVertex2f(xnot + x0 - x1 - 10, yo + y1 - 20);
		glEnd();
		setPixel(xnot + x0 - x1 - 10, yo -y1 - 20);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 - 10, yo - y1 - 20);
			glVertex2f(xnot + x0 - x1 - 10, yo - y1 - 20);
		glEnd();
		//cloud2.
		setPixel(xnot + x0 - x1 + 300, yo + y1 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 300, yo + y1 + 100);
			glVertex2f(xnot + x0 - x1 + 300, yo + y1 + 100);
		glEnd();
		setPixel(xnot + x0 - x1 + 300, yo - y1 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 300, yo - y1 + 100);
			glVertex2f(xnot + x0 - x1 + 300, yo - y1 + 100);
		glEnd();
		
		setPixel(xnot + x0 - x1 + 10 + 300, yo + y1 - 20 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 10 + 300, yo + y1 - 20 + 100);
			glVertex2f(xnot + x0 - x1 + 10 + 300, yo + y1 - 20 + 100);
		glEnd();
		setPixel(xnot + x0 - x1 + 10 + 300, yo -y1 - 20 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 + 10 + 300, yo - y1 - 20 + 100);
			glVertex2f(xnot + x0 - x1 + 10 + 300, yo - y1 - 20 + 100);
		glEnd();
		
		setPixel(xnot + x0 - x1 - 10 + 300, yo + y1 - 20 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 - 10 + 300, yo + y1 - 20 + 100);
			glVertex2f(xnot + x0 - x1 - 10 + 300, yo + y1 - 20 + 100);
		glEnd();
		setPixel(xnot + x0 - x1 - 10 + 300, yo -y1 - 20 + 100);
		glBegin(GL_LINES);
			glVertex2f(xnot + x0 + x1 - 10 + 300, yo - y1 - 20 + 100);
			glVertex2f(xnot + x0 - x1 - 10 + 300, yo - y1 - 20 + 100);
		glEnd();
	}
	//mountains.
	glShadeModel(GL_SMOOTH);
	glBegin(GL_TRIANGLES);
		glColor3f(0.3, 0.2, 0.0);
		glVertex2f(xnot - 540, -180);
		glColor3f(0.3, 0.2, 0.0);
		glVertex2f(xnot - 340, 50);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(xnot - 140, -180);
		glColor3f(0.3, 0.2, 0.0);
		glVertex2f(xnot - 240, -180);
		glColor3f(0.3, 0.2, 0.0);
		glVertex2f(xnot - 40, 0);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(xnot + 140, -180);
		glColor3f(0.3, 0.2, 0.0);
		glVertex2f(xnot + 100, -180);
		glColor3f(0.3, 0.2, 0.0);
		glVertex2f(xnot + 320, 50);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(xnot + 540, -180);
	glEnd();
	//sea.
	glBegin(GL_POLYGON);
		glColor3f(0.29, 0.61, 0.58);
		glVertex2f(-540, -180);
		glVertex2f(540, -180);
		glVertex2f(540, -360);
		glVertex2f(-540, -360);
	glEnd();
}

void aeroplane()
{
	//head.
	glColor3f(1.0, 1.0, 1.0);
	x0 = 200;
	rady = 25;
	radx = 40;
	int x1, y1, deciP1;
	x1 = 0, y1 = rady;
	deciP1 = (rady * rady) - (radx * radx * rady) + ((1 / 4) * radx * radx);
	while(rady * rady * x1 <= radx * radx * y1)
	{
		x1++;
		if(deciP1 < 0)
			deciP1 = deciP1 + (2 * rady * rady * (x1 + 1)) + (rady * rady);
		else
		{
			y1--;
			deciP1 = deciP1 + (2 * rady * rady * (x1 + 1)) - (2 * radx * radx * (y1 - 1)) + (rady * rady);
		}
		setPixel(x0 - x1, y0 + y1);
		glBegin(GL_LINES);
			glVertex2f(x0 + x1, y0 + y1);
			glVertex2f(x0 - x1, y0 + y1);
		glEnd();
		setPixel(x0 - x1, y0 -y1);
		glBegin(GL_LINES);
			glVertex2f(x0 + x1, y0 - y1);
			glVertex2f(x0 - x1, y0 - y1);
		glEnd();
	}
	deciP1 = (rady * rady * (x1 + (1 / 2)) * (x1 + (1/2))) + (radx * radx * (y1 - 1) *(y1 - 1)) - (radx * radx * rady * rady);
	while(y1 > 0)
	{
		y1--;
		if(deciP1 > 0)
			deciP1 = deciP1 + (radx * radx) - (2 * radx * radx * (y1 -1));
		else
		{
			x1++;
			deciP1 = deciP1 + (2 * rady * rady * (x1 + 1)) - (2 * radx * radx * (y1 -1)) + (radx * radx);
		}
		setPixel(x0 - x1, y0 + y1);
		glBegin(GL_LINES);
			glVertex2f(x0 + x1, y0 + y1);
			glVertex2f(x0 - x1, y0 + y1);
		glEnd();
		setPixel(x0 - x1, y0 -y1);
		glBegin(GL_LINES);
			glVertex2f(x0 + x1, y0 - y1);
			glVertex2f(x0 - x1, y0 - y1);
		glEnd();
	}
	//tail.
	x0 = 350;
	rady = 15;
	radx = 30;
	int x2, y2, deciP2;
	x2 = 0, y2 = rady;
	deciP2 = (rady * rady) - (radx * radx * rady) + ((1 / 4) * radx * radx);
	while(rady * rady * x2 <= radx * radx * y2)
	{
		x2++;
		if(deciP2 < 0)
			deciP2 = deciP2 + (2 * rady * rady * (x2 + 1)) + (rady * rady);
		else
		{
			y2--;
			deciP2 = deciP2 + (2 * rady * rady * (x2 + 1)) - (2 * radx * radx * (y2 - 1)) + (rady * rady);
		}
		setPixel(x0 - x2, y0 + y2);
		glBegin(GL_LINES);
			glVertex2f(x0 + x2, y0 + y2);
			glVertex2f(x0 - x2, y0 + y2);
		glEnd();
		setPixel(x0 - x2, y0 -y2);
		glBegin(GL_LINES);
			glVertex2f(x0 + x2, y0 - y2);
			glVertex2f(x0 - x2, y0 - y2);
		glEnd();
	}
	deciP2 = (rady * rady * (x2 + (1 / 2)) * (x2 + (1/2))) + (radx * radx * (y2 - 1) *(y2 - 1)) - (radx * radx * rady * rady);
	while(y2 > 0)
	{
		y2--;
		if(deciP2 > 0)
			deciP2 = deciP2 + (radx * radx) - (2 * radx * radx * (y2 -1));
		else
		{
			x2++;
			deciP2 = deciP2 + (2 * rady * rady * (x2 + 1)) - (2 * radx * radx * (y2 -1)) + (radx * radx);
		}
		setPixel(x0 - x2, y0 + y2);
		glBegin(GL_LINES);
			glVertex2f(x0 + x2, y0 + y2);
			glVertex2f(x0 - x2, y0 + y2);
		glEnd();
		setPixel(x0 - x2, y0 -y2);
		glBegin(GL_LINES);
			glVertex2f(x0 + x2, y0 - y2);
			glVertex2f(x0 - x2, y0 - y2);
		glEnd();
	}
	//body.
	glBegin(GL_POLYGON);
		glVertex2f(200, ynot + 75 + 115);
		glVertex2f(350, ynot + 65 + 115);
		glVertex2f(350, ynot + 35 + 115);
		glVertex2f(200, ynot + 24 + 115);
	glEnd();
	//windows.
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(5.0);
	setPixel(220, y0);
	setPixel(230, y0);
	setPixel(240, y0);
	setPixel(250, y0);
	setPixel(260, y0);
	setPixel(270, y0);
	setPixel(280, y0);
	setPixel(290, y0);
	setPixel(300, y0);
	setPixel(310, y0);
	setPixel(320, y0);
	setPixel(330, y0);
	setPixel(340, y0);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex2f(160, ynot + 60 + 115);
		glVertex2f(172, ynot + 72 + 115);
		glVertex2f(188, ynot + 77 + 115);
		glVertex2f(188, ynot + 60 + 115);
	glEnd();
	//door.
	glColor3f(0.0, 0.0, 1.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(200, ynot + 60 + 115);
		glVertex2f(210, ynot + 60 + 115);
		glVertex2f(210, ynot + 40 + 115);
		glVertex2f(200, ynot + 40 + 115);
	glEnd();
	//middle_top_flap.
	glColor3f(0.14, 0.48, 0.25);
	glBegin(GL_POLYGON);
		glVertex2f(225, ynot + 73 + 115);
		glVertex2f(279, ynot + 110 + 115);
		glVertex2f(299, ynot + 112 + 115);
		glVertex2f(278, ynot + 68 + 115);
	glEnd();
	//middle_bottom_flap.
	glBegin(GL_POLYGON);
		glVertex2f(225, ynot + 32 + 115);
		glVertex2f(273, ynot - 30 + 115);
		glVertex2f(293, ynot - 32 + 115);
		glVertex2f(278, ynot + 36 + 115);
	glEnd();
	//tail_top_flag.
	glBegin(GL_POLYGON);
		glVertex2f(350, ynot + 65 + 115);
		glVertex2f(373, ynot + 75 + 115);
		glVertex2f(386, ynot + 75 + 115);
		glVertex2f(373, ynot + 60 + 115);
	glEnd();
	//tail_bottom_flag.
	glBegin(GL_POLYGON);
		glVertex2f(350, ynot + 35 + 115);
		glVertex2f(373, ynot + 24 + 115);
		glVertex2f(386, ynot + 24 + 115);
		glVertex2f(373, ynot + 40 + 115);
	glEnd();
}

void picture(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	background();
	aeroplane();
	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-540, 540, -360, 360);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(int key,int ,int)
{
	switch (key)
	{
		case GLUT_KEY_UP:
			y0 = y0 + 1;
			ynot = ynot + 1;
			break;
		case GLUT_KEY_DOWN:
			y0 = y0 - 1;
			ynot = ynot - 1;
			break;
		default:
			cout<<key;
	}
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(1000/60, timer, 0);
	xnot = xnot + 0.75;
	if(xnot - 540 >= 540)
		xnot = xnot - 2160;
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(143, 24);
	glutInitWindowSize(1080, 720);
	glutCreateWindow("Aeroplane");
	init();
	glutDisplayFunc(picture);
	glutReshapeFunc(reshape);
	glutSpecialFunc(keyboard);
	glutTimerFunc(1000, timer, 0);
	glutMainLoop();
}
