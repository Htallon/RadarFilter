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
#include "filter.h"
#include "radarSimulator.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
	for(int i=0;i<20;i++)
	{

		int mat[20][20];
		rand01mat((int **)mat,20,20,99);
		mat[i][i]=1;//true target

		
		advance(getTargetsFromRadar((int **)mat,20,20));
		renderTarget(ValidTrace,(int **)mat,20,20);

		showMat((int **)mat,20,20);
		system("pause");
	}
	
	system("pause");
    return 0;
}






