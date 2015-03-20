/*
This program is designed for noise-remove of radar-detection
Only for algorithm demonstration

Additional Terms:
DO NOT apply this source to any MILLLITARY PURPOSES

Copyright (C) 2015  Soren Chiron gionstorm@gmail.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/
#ifndef RADAR_SIMU
#define RADAR_SIMU

void rand01mat(int ** mat,int width,int height,unsigned trueThres=5);
void showMat(int ** mat,int width,int height);
vector<Node> getTargetsFromRadar(int ** mat,int width,int height);
void renderTarget(vector<vector<Node>> traces,int ** mat,int width,int height);

#endif