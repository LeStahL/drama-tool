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

#include <stdio.h>
#include <string.h>

#include "shaderprogram.h"

void debug_shader(GLint shader_handle)
{
    int compile_status = 0;
    glGetShaderiv(shader_handle, GL_COMPILE_STATUS, &compile_status);
    if(compile_status != GL_TRUE)
    {
        printf("FAILED.\n");
        int len = 12;
        glGetShaderiv(shader_handle, GL_INFO_LOG_LENGTH, &len);
        printf("log length: %d\n", len);
        GLchar CompileLog[len];
        glGetShaderInfoLog(shader_handle, len, 0, CompileLog);
        printf("error: %s\n", CompileLog);
    }
}

void create_shader(shader_program* p, GLchar** code)
{
    int size = strlen(*code);
    
    p->shader = glCreateShader(GL_FRAGMENT_SHADER); 
    p->program = glCreateProgram();
    
    glShaderSource(p->shader, 1, code, &size);
    glCompileShader(p->shader);
    
    debug_shader(p->shader);
    
    glAttachShader(p->program, p->shader);
    glLinkProgram(p->program);
}
