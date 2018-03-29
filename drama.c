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
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#include <X11/Xlib.h>
#include <X11/Xatom.h>

#include "gldef.h"
#include "xwindow.h"
#include "shaderprogram.h"

// int saved = 1; >//FIXME add this to separate document.c

xwindow mainwin;
shader_program mainview;

void keyboardfunction()
{
    while(1)
    {
        while(XPending(mainwin.display))
        {
            XNextEvent(mainwin.display, &(mainwin.xevent));
        }
        if(mainwin.xevent.type == KeyPress) 
        {
            XKeyPressedEvent *e = (XKeyPressedEvent*) &(mainwin.xevent);
            
            if(e->keycode == XKeysymToKeycode(mainwin.display, XK_Escape))
                exit(0);
        }
    }
}

int main(int argc, char **args)
{
    glinitext();
    
    create_xwindow(&mainwin, 600, 400, 0);
    keyboard_function(&keyboardfunction);
    
#include "mainwin.h"
    create_shader(&mainview, (GLchar**)&mainwin_frag);
    glUseProgram(mainview.program);
    
    struct timeval tv, t;
    gettimeofday(&tv, NULL);
    unsigned long long t0 = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000;

    int x_file_descriptor = ConnectionNumber(mainwin.display);
    fd_set x_file_descriptor_set;
    
    while(1) 
    {
        FD_ZERO(&x_file_descriptor_set);
        FD_SET(x_file_descriptor, &x_file_descriptor_set);
        
        t.tv_usec = 1.e6/60.;
        t.tv_sec = 0;
        
        int num_ready_fds = select(x_file_descriptor + 1, &x_file_descriptor_set, NULL, NULL, &t);
        if (num_ready_fds == 0)
        {
            gettimeofday(&tv, NULL);
            unsigned long long newtime_l = (unsigned long long)(tv.tv_sec) * 1000 + (unsigned long long)(tv.tv_usec) / 1000 - t0;
            double newtime = (double)newtime_l/1000.;
            
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            
            glBegin(GL_QUADS);
            glVertex3f(-1,-1,0);
            glVertex3f(-1,1,0);
            glVertex3f(1,1,0);
            glVertex3f(1,-1,0);
            glEnd();
        
            glXSwapBuffers(mainwin.display, mainwin.win);
        }   
    }
    
    return 0;
}
