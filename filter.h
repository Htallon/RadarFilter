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

#ifndef FILTER_H
#define FILTER_H

#include <vector>
using namespace std;
typedef struct _Node2Df
{
	float x;
	float y;
	int flag;
}Node2Df,Node;

Node mknode(float x,float y);
void advance(vector<Node> newNodes);
int isValid(vector<Node> trace,Node node);
float norm(Node a,Node b);
float degree(vector<Node> trace,Node node,int offset=0);
float tolerance(float dist);

#ifndef FILTER
extern vector<vector<Node2Df>> ValidTrace;
extern vector<vector<Node2Df>> PotentialTrace;
#endif

#endif

