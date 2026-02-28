#include <unigl.h>
#ifdef USEGLES

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
	glDeleteBuffers = GLFUNCADDR("glDeleteBuffers");
	glGenBuffers = GLFUNCADDR("glGenBuffers");
	glBindBuffer = GLFUNCADDR("glBindBuffer");
	glBufferData = GLFUNCADDR("glBufferData");
}
#endif
