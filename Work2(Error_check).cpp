#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

GLenum errorCheck()
{
	GLenum code;
	const GLubyte * string;
	code = glGetError();
	if(code != GL_NO_ERROR)
	{
		string = gluErrorString(code);
		cout<<stderr<<" OpenGL error: "<<string;
	}
	return code;
}
int main()
{
	errorCheck();
	return 0;
}
