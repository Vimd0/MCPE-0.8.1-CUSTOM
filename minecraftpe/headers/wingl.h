#ifndef WINGL_H
#define WINGL_H
#ifdef __WIN32__
#include <gl/GL11.h>
void (*glDeleteBuffers)(GLsizei n, const GLuint *buffers);
void (*glBufferData)(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
void (*glBindBuffer)(GLenum target, GLuint buffer);
#endif
#endif
