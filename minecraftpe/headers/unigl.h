#ifndef UNIGL_H
#define UNIGL_H
#include <GL/glu.h>
#ifdef USEGLES
#include <GLES/gl.h>
#include <GLES/glext.h>
#else
#include <GL/gl.h>
#include <GL/glext.h>

#ifdef __cplusplus
extern "C" {
#endif
void initGlFuncs();
extern void (*glDeleteBuffers)(GLsizei n, const GLuint* buffers);
extern void (*glGenBuffers)(GLsizei n, GLuint* buffers);
extern void (*glBindBuffer)(GLenum target, GLuint buffer);
extern void (*glBufferData)(GLenum target, GLsizeiptr size, const void* data, GLenum usage);

#ifdef __cplusplus
}
#endif

#endif
#endif
