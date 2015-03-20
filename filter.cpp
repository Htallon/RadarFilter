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
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <random>

#define FILTER
#define PI (3.1415926)
#define EPSILON (1e-5)

#include "filter.h"

using namespace std;

float MAX_DISTANCE=1.5;// max tolarance
float MIN_DISTANCE=1;
int MIN_TRACE_LEN=3;
vector<vector<Node2Df>> ValidTrace;
vector<vector<Node2Df>> PotentialTrace;
float K = (-180.0/MAX_DISTANCE);

Node mknode(float x,float y)
{
	Node node;
	node.x = x;
	node.y = y;
	node.flag=0;
	return node;
}

// feed-in a new graph
void advance(vector<Node> newNodes)
{
	vector<vector<Node2Df>> newValidTrace;
	vector<vector<Node2Df>> newPotentialTrace;
	for(vector<Node> trace : ValidTrace)
	{
		for(Node node : newNodes)
		{
			if(isValid(trace,node))
			{
				vector<Node> newTrace = trace;
				node.flag=1;//node used
				newTrace.push_back(node);
				newValidTrace.push_back(newTrace);
			}
		}
	}
	ValidTrace = newValidTrace;
	for(Node node : newNodes)
	{
		if(node.flag==1)
			continue;
		for(vector<Node> trace : PotentialTrace)
		{
			if(isValid(trace,node))
			{
				vector<Node> newTrace = trace;
				node.flag=1;//node used
				newTrace.push_back(node);
				if(newTrace.size() >= MIN_TRACE_LEN)//good trace
					ValidTrace.push_back(newTrace);
				else
					newPotentialTrace.push_back(newTrace);//yet too short
			}
		}
		if(node.flag==0)//bad node
		{
			vector<Node> newTrace;
			newTrace.push_back(node);
			newPotentialTrace.push_back(newTrace);
		}
	}
	PotentialTrace = newPotentialTrace;
	cout<<"advance report:"<<endl;
	cout<<"new targets:"<<newNodes.size()<<endl;
	cout<<"ValidTrace:"<<ValidTrace.size()<<" "<<"PotentialTrace:"<<PotentialTrace.size()<<endl;
}

// judge if a node can be a next of the trace
int isValid(vector<Node> trace,Node node)
{
	if(trace.size()==0)
	return 1;
	float deg = degree(trace,node);
	float dst = norm(trace.back(),node);
	
	if(dst>MAX_DISTANCE || dst<MIN_DISTANCE)
		return 0;

	float tolerate = tolerance(dst);
	if(deg<=tolerate)
	{
		float prev_deg = degree(trace,node,-1);
		if(abs(prev_deg-deg)<=tolerate)
			return 1;
	}
	return 0;
}

// degree tolerance get from distance
float tolerance(float dist)
{
	if(dist>MAX_DISTANCE)
	return 0;
	return ( 180 + K * dist );
}

// distance 2D
float norm(Node a,Node b)
{
	float dx = a.x-b.x,
		  dy = a.y-b.y;

	return sqrt( dx*dx+dy*dy );
}

// degree offset of the attempted trace, offset <=0
float degree(vector<Node> trace,Node node,int offset)
{
	int size = trace.size();
	if(size<2-offset)
		return 0.0;
	Node a = trace[size-2],b = trace[size-1];
	float dx0 = b.x-a.x , dy0 = b.y-a.y ,
		dx1 = node.x-b.x , dy1 = node.y-b.y;

	//return acos( (dx0*dx1+dy0*dy1)/sqrt(dx0*dx0+dx1*dx1+dy0*dy0+dy1*dy1) );
	return acos(
	 				(dx0*dx1+dy0*dy1) / ( norm(a,b)*norm(node,b)+EPSILON )
	 )*180.0/PI;
}












