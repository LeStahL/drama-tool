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

#include "xwindow.h"

void create_xwindow(xwindow *dst, int width, int height, int fullscreen)
{
    dst->att = (GLint *)malloc(5*sizeof(GLint));
    
    dst->att[0] = GLX_RGBA;
    dst->att[1] = GLX_DEPTH_SIZE;
    dst->att[2] = 24;
    dst->att[3] = GLX_DOUBLEBUFFER;
    dst->att[4] = None;
    
    XInitThreads();
    
    dst->display = XOpenDisplay(0);
    dst->root = DefaultRootWindow(dst->display);
    dst->vi = glXChooseVisual(dst->display, 0, dst->att);
    dst->cmap = XCreateColormap(dst->display, dst->root, dst->vi->visual, AllocNone);
    dst->swa.colormap = dst->cmap;
    dst->swa.event_mask = ExposureMask | KeyPressMask | ButtonPressMask;
    dst->win = XCreateWindow(dst->display, dst->root, 0, 0, width, height, 0, dst->vi->depth, InputOutput, dst->vi->visual, CWColormap | CWEventMask, &(dst->swa));
    
    if(fullscreen == 1)
    {
        Atom atoms[2] = { XInternAtom(dst->display, "_NET_WM_STATE_FULLSCREEN", True), None };
        XChangeProperty(dst->display, dst->win, XInternAtom(dst->display, "_NET_WM_STATE", True), XA_ATOM, 32, PropModeReplace,(unsigned char*) atoms, 1);
    }
    
    XMapWindow(dst->display, dst->win);
    dst->glc = glXCreateContext(dst->display, dst->vi, 0, GL_TRUE);
    glXMakeCurrent(dst->display, dst->win, dst->glc);
}

void keyboard_function(void* f)
{
    pthread_t exithread;
    pthread_create(&exithread, NULL, f, 0);
}

void render_function(void* f)
{
    pthread_t renderthread;
    pthread_create(&renderthread, NULL, f, 0);
}
