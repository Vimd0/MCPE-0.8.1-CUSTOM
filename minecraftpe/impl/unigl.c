#include <unigl.h>
#ifdef USEGLES

#else

void (*glDeleteBuffers)(GLsizei n, const GLuint* buffers);
void (*glGenBuffers)(GLsizei n, GLuint *buffers);
void (*glBindBuffer)(GLenum target, GLuint buffer);
void (*glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
#include <GL/glx.h>
void initGlFuncs(){
	glDeleteBuffers = glXGetProcAddress("glDeleteBuffers");
	glGenBuffers = glXGetProcAddress("glGenBuffers");
	glBindBuffer = glXGetProcAddress("glBindBuffer");
	glBufferData = glXGetProcAddress("glBufferData");
}
#endif
