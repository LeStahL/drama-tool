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

#ifndef XWINDOW_H
#define XWINDOW_H

#include <stdlib.h>
#include <pthread.h>

#include <GL/gl.h>
#include <GL/glx.h>

#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>

typedef struct 
{
    Display                 *display;
    Window                  root;
    GLint                   *att; 
    XVisualInfo             *vi;
    Colormap                cmap;
    XSetWindowAttributes    swa;
    Window                  win;
    GLXContext              glc;
    XWindowAttributes       gwa;
    XEvent                  xevent;
} xwindow;

void create_xwindow(xwindow *dst, int width, int height, int fullscreen);
void keyboard_function(void *f);
void render_function(void *f);

#endif
