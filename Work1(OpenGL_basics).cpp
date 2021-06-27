#include <GL/glut.h>									//or others, depending on the system in use

void init(void)											//Initialization function.
{
	glClearColor(0.8, 0.7, 0.9, 0.0);					//Set display window color to a light shade of Purple.
	glMatrixMode(GL_PROJECTION);						//Set projection parameters.
	gluOrtho2D(0.0, 1080.0, 0.0, 720.0);
}

void picture(void)										//Function to draw line segments.
{
	glClear(GL_COLOR_BUFFER_BIT);						//Set the bit values of color buffer(refresh buffer) indicated in the glClearColor().
	
	glColor3f(0.7, 0.0, 0.3);							//Set the line segment color to Dark Red.(3f) because it takes 3 float values.
	glBegin(GL_LINES);									//Specify line segment geometry.
		glVertex2i(0, 0);								//starting coordinate of line 1.
		glVertex2i(1080, 720);							//ending coordinate of line 1.
		glVertex2i(0, 720);								//starting coordinate of line 2.
		glVertex2i(1080, 0);							//ending coordinate of line 2.
		glVertex2i(540, 0);
		glVertex2i(540, 720);
		glVertex2i(0, 360);
		glVertex2i(1080, 360);
	glEnd();
	
	glBegin(GL_POINTS);									//Points of Green color.
		glColor3f(0.0, 1.0, 0.0);
		glPointSize(5.0);
		glVertex2i(210, 210);
		glVertex2i(340, 450);
		glVertex2i(460 ,50);
		glVertex2i(590, 290);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_STRIP);								//Does not need to repeat vertex endpoints to join them,
		glVertex2i(1080/2, 720/4);						//except for the last endpoint which is also the first endpoint.
		glVertex2i(1080/4, 720/2);
		glVertex2i(1080/2, (720/4)*3);
		glVertex2i((1080/4)*3, 360);
		glVertex2i(1080/2, 720/4);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);								//Performs the same function as GL_LINE STRIP but with one less vertex.
		glVertex2i(1080/2, 720/4-10);					//Always form a loop of line segments.
		glVertex2i(1080/4-10, 720/2);					//No repetition of vertex.
		glVertex2i(1080/2, (720/4)*3+10);
		glVertex2i((1080/4)*3+10, 360);
	glEnd();
	
	glColor3f(1.0, 1.0, 0.0);
	glRecti(10, 150, 150, 720/2);						//Directly draw a filled polygon(Square/Rectangle).
	
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POLYGON);								//Draw any polygon with any number of vertices.
		glVertex2i(1080/2,720/4+10);					//Write vertices in counterclockwise manner.
		glVertex2i((1080/4)*3-10, 360);
		glVertex2i(1080/2, (720/4)*3-10);
		glVertex2i(1080/4+10, 720/2);
	glEnd();
	//glPolygonMode(GL_FRONT, GL_LINE);					//Draw the same polygon defined above but with different colour boundary;
	glBegin(GL_POLYGON);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2i(1080/2,720/4+10);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2i((1080/4)*3-10, 360);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2i(1080/2, (720/4)*3-10);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2i(1080/4+10, 720/2);
	glEnd();
	
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_TRIANGLES);								//Draw triangle of any shape.
		glVertex2i(1080/2 + 270,720/4+20);					//Write vertices in counterclockwise manner.
		glVertex2i((1080/4)*3-20 + 270, 360);
		glVertex2i(1080/2 + 270, (720/4)*3-20);
	glEnd();
	
	glShadeModel (GL_SMOOTH);//GL_FLAT to fill with color specified in the end.
	glBegin (GL_TRIANGLES);
		glColor3f (0.0, 0.0, 1.0);
		glVertex2i (150, 50);
		glColor3f (1.0, 0.0, 0.0);
		glVertex2i (250, 50);
		glColor3f (0.0, 1.0, 0.0);
		glVertex2i (200, 150);
	glEnd ( );
	
	glBegin(GL_QUAD_STRIP);
		glColor3f(0.5, 0.0, 0.0);
		glVertex2i(100, 70);
		glVertex2i(40, 50);
		glVertex2i(50, 0);
		glVertex2i(0, 30);
		glColor3f(0.0, 0.5, 0.0);
		glVertex2i(40, 100);
		glVertex2i(90, 90);
	glEnd();
	glFlush();											//Process all OpenGL routines as quickly as possible.
}
void winReshapeFcn (int newWidth, int newHeight)		//Adjusts the window after reshaping.
{
	glViewport(0.0, 0.0, (GLsizei)newWidth, (GLsizei)newHeight);
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity ( );
	gluOrtho2D(0, 1080, 0, 720);
	glClear (GL_COLOR_BUFFER_BIT);
}
int main(int argc, char** argv)							//Main function.
{
	//Order of Function calls is important.
	glutInit(&argc, argv);								//Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);		//GLUT_SINGLE for use of a single buffer & GLUT_RGB for RGB color mode.(DEFAULT SETTING).
	glutInitWindowPosition(143, 24);					//Sets the position of window.(Does not put the Display Window on the screen).
	glutInitWindowSize(1080, 720);						//Sets the size of window.(Does not put the Display Window on the screen).
	glutCreateWindow("An example of OpenGL Program");	//Create the Window.(Puts the Display Window on the screen)
	init();												//Execute initialization procedure.
	glutDisplayFunc(picture);							//Send graphics to Display window. Display window now contains picture.
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();										//This completes the window processing &
														//All windows and their graphics are now activated &
														//This must be the last function of the program.
}
