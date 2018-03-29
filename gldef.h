/*
 * DRaMa Tool - Demo RayMarching Tool
 * Copyright (C) 2018  Alexander Kraus <nr4@z10.info>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GLDEF_H
#define GLDEF_H

#include <GL/gl.h>
typedef char GLchar;

typedef void (*glGetShaderiv_t)(GLuint,  GLenum,  GLint *);
glGetShaderiv_t glGetShaderiv;
typedef void (*glGetShaderInfoLog_t)(GLuint,  GLsizei, GLsizei,  GLchar *);
glGetShaderInfoLog_t glGetShaderInfoLog;
typedef GLuint (*glCreateShader_t)(GLenum);
glCreateShader_t glCreateShader;
typedef GLuint (*glCreateProgram_t)();
glCreateProgram_t glCreateProgram;
typedef void (*glShaderSource_t)(GLuint, GLsizei, GLchar **, GLint *);
glShaderSource_t glShaderSource;
typedef void (*glCompileShader_t)(GLuint);
glCompileShader_t glCompileShader;
typedef void (*glAttachShader_t)(GLuint, GLuint);
glAttachShader_t glAttachShader;
typedef void (*glLinkProgram_t)(GLuint);
glLinkProgram_t glLinkProgram;
typedef void (*glUseProgram_t)(GLuint);
glUseProgram_t glUseProgram;
typedef GLint (*glGetUniformLocation_t)(GLuint, const GLchar *);
glGetUniformLocation_t glGetUniformLocation;
typedef void (*glUniform2f_t)(GLint, GLfloat, GLfloat);
glUniform2f_t glUniform2f;
typedef void (*glUniform1f_t)(GLint, GLfloat);
glUniform1f_t glUniform1f;
typedef void (*glGenFramebuffers_t)(GLsizei, GLuint*);
glGenFramebuffers_t glGenFramebuffers;
typedef void (*glBindFramebuffer_t)(GLenum, GLuint);
glBindFramebuffer_t glBindFramebuffer;
typedef void (*glFramebufferTexture2D_t)(GLenum, GLenum, GLenum, GLuint, GLint);
glFramebufferTexture2D_t glFramebufferTexture2D;
typedef void (*glBlitFramebuffer_t)(GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLint, GLbitfield, GLenum);
glBlitFramebuffer_t glBlitFramebuffer;
typedef void (*glNamedRenderbufferStorage_t) (GLuint, GLenum, GLsizei, GLsizei);
glNamedRenderbufferStorage_t glNamedRenderbufferStorage;

void glinitext();

#endif
