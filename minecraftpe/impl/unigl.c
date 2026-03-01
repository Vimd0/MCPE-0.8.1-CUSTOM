#include <unigl.h>
#ifdef USEGLES
#include <math.h>
/*
 * maybe mojang used
 * https://storage.googleapis.com/google-code-archive-downloads/v2/code.google.com/glues/glues-1.4.tar.gz
 * ?
*/
void gluPerspective(GLfloat fovy, GLfloat aspect, GLfloat zNear, GLfloat zFar) {
	double v7; // d8
	double v8; // r0
	GLfloat v9; // s18
	GLfloat v10; // s22
	GLfloat v11; // s14
	GLfloat v12[16]; // [sp+0h] [bp-68h] BYREF

	v7 = (float)((float)((float)(fovy * 0.5) * 3.1416) / 180.0);
	v8 = sin(v7);
	v9 = zFar - zNear;
	if((float)(zFar - zNear) != 0.0) {
		v10 = v8;
		if(v10 != 0.0 && aspect != 0.0) {
			v12[12] = 0.0;
			v12[1] = v12[2] = v12[3] = v12[4] = 0;
			v12[13] = 0.0;
			v12[6] = v12[7] = v12[8] = v12[9] = 0;
			v12[11] = -1.0;
			v12[15] = 0.0;
			v11 = cos(v7) / v10;
			v12[5] = v11;
			v12[10] = (float)-(float)(zFar + zNear) / v9;
			v12[0] = v11 / aspect;
			v12[14] = (float)((float)(zNear * -2.0) * zFar) / v9;
			glMultMatrixf(v12);
		}
	}
}
#else

void (*glDeleteBuffers)(GLsizei n, const GLuint* buffers);
void (*glGenBuffers)(GLsizei n, GLuint *buffers);
void (*glBindBuffer)(GLenum target, GLuint buffer);
void (*glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);

#ifdef __WIN32__
#include <wingdi.h>
#define GLFUNCADDR wglGetProcAddress
#else
#include <GL/glx.h>
#define GLFUNCADDR glXGetProcAddress
#endif
void initGlFuncs(){
	glDeleteBuffers = (void (*)(GLsizei, const GLuint*)) GLFUNCADDR("glDeleteBuffers");
	glGenBuffers = (void (*)(GLsizei, GLuint*)) GLFUNCADDR("glGenBuffers");
	glBindBuffer = (void (*)(GLenum, GLuint)) GLFUNCADDR("glBindBuffer");
	glBufferData = (void (*)(GLenum, GLsizeiptr, const void*, GLenum)) GLFUNCADDR("glBufferData");
}
#endif
