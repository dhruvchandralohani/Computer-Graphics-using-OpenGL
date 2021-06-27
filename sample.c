#include <GL/glut.h>
#include <GL/gl.h>

int main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	int mode = GLUT_RGB|GLUT_DOUBLE;
	glutInitDisplayMode(mode);
	glutInitWindowSize(900,900);
	glutCreateWindow("Simple");
	//glutDisplayFunc(display);
	//glutKeyboardFunc(key);
	glutMainLoop();
	return 0;
}
