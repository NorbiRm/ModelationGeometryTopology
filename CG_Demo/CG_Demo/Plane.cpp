#include "header\Plane.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

Plane::Plane()
{
	width, height = 1;
	vDivs, hDivs = 1;
}

Plane::Plane(float _width, float _height, int _vDivs, int _hDivs)
{
	width = _width;
	height = _height;
	vDivs = _vDivs;
	hDivs = _hDivs;
}


Plane::~Plane()
{
}

void Plane::createObj() {
	ofstream myfile;
	myfile.open("myPlane.obj");

	int cont = 0;
	while (true) {
		switch (cont){
			case 0:
				myfile << "# Paola, Norberto, Luis, and Carlos.\n\n";
				break;
			case 1:
				myfile << "mtllib myMtl.mtl\n\n";
				break;
			case 2:
				myfile << "#Geometry:\n";
				myfile << createVertexes()+"\n";
				break;
			case 3:
				myfile << "#Normals:\nvn 0 1 0\n\n";
				break;
			case 4:
				myfile << "#TOPOLOGY f vi/ti/ni vi/ti/ni vi/ti/ni\n\nusemtl cube\n\n";
				break;
			default:
				break;
		}

		cont++;
		if (cont > 4) {
			break;
		}
		else continue;
	}
	myfile.close();
}

string Plane::createVertexes(){
	return "v \n";
}

string Plane::createFaces() {
	return "#front:\n#Right:\n#Back:\n#Left:\#Up:\n#Down\n";
}


