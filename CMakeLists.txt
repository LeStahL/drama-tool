#
# DRaMa Tool - Demo RayMarching Tool
# Copyright (C) 2018  Alexander Kraus <nr4@z10.info>
# 
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
    
cmake_minimum_required(VERSION 2.8.11)
project(drama-tool)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_library(C_LIBRARY NAMES c)
find_library(MATH_LIBRARY NAMES m)
find_library(PTHREAD_LIBRARY NAMES pthread)
find_library(DL_LIBRARY NAMES dl)
find_library(X11_LIBRARY NAMES X11)
find_library(GL_LIBRARY NAMES GL)

configure_file(gldef.c.in gldef.c NEWLINE_STYLE UNIX)

find_program(SHADER_MINIFIER NAMES shader_minifier)
add_custom_target(minification
    ${SHADER_MINIFIER} "${CMAKE_SOURCE_DIR}/gfx/mainwin.frag" -o "${CMAKE_BINARY_DIR}/mainwin.h"
)

set(DRAMA_TOOL_SRC
    drama.c
    "${PROJECT_BINARY_DIR}/gldef.c"
    xwindow.c
    shaderprogram.c
)
add_definitions(-Wall)
add_executable(drama-tool ${DRAMA_TOOL_SRC})
add_dependencies(drama-tool minification)

target_link_libraries(drama-tool ${C_LIBRARY} ${MATH_LIBRARY} ${PTHREAD_LIBRARY} ${DL_LIBRARY} ${X11_LIBRARY} ${GL_LIBRARY})

find_program(UPX_COMMAND NAMES upx)
add_custom_command(TARGET drama-tool COMMAND ${UPX_COMMAND} --best "${PROJECT_BINARY_DIR}/drama-tool")

install(TARGETS drama-tool DESTINATION bin)
