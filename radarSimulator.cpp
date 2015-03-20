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
#include <iostream>
#include <random>
#include "filter.h"
using namespace std;

void rand01mat(int ** mat,int width,int height,unsigned int trueThres)
{
	std::random_device rd;
	for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
		{
			(((int *)mat))[i*width+j]=( (rd()%100)  >=trueThres ? 1:0 );
		}
}
void showMat(int ** mat,int width,int height)
{
	cout<<"next mat:"<<endl;
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if( ((int *)mat)[i*width+j] )
			{
				if(((int *)mat)[i*width+j]>1)
				cout<<"x";
				else
				cout<<"o";
			}
			else
				cout<<" ";
		}
		cout<<endl;
	}
}
vector<Node> getTargetsFromRadar(int ** mat,int width,int height)
{
	vector<Node> result;
	for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
		{
			if  ( (((int *)mat))[i*width+j]  )
			{
				result.push_back(mknode(j,i));
			}
		}
	return result;
}

void renderTarget(vector<vector<Node>> traces,int ** mat,int width,int height)
{
	for(vector<Node> trace: traces)
	{
		Node n = trace.back();
		if(n.x>width || n.y>height)
			continue;
		(((int *)mat))[((int)n.y) * width+(int)n.x]=2;
	}

}




