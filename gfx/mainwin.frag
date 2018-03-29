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
 
#version 130

vec4 fcolor;

void addRect(float x1, float y1, float x2, float y2, vec4 color)
{
    float scale = step(x1, gl_FragCoord.x);
    scale = (1.-step(x2, gl_FragCoord.x)) * scale;
    scale = step(y1, gl_FragCoord.y) * scale;
//     scale = (
//     color = mix(fcolor, color, 
}

void main()
{
    gl_FragColor = vec4(1.,0.,0.,1.);
//     gl_FragColor = vec4(.5+.5*sin(length(gl_FragCoord)), .5+.5*sin(length(gl_FragCoord)), 0., 1.);
}
