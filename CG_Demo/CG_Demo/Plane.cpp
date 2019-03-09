/*
Norberto Reyes A01651207
Luis Villa A01335048
Paola López López A01334775
Carlos Eduardo Reyna Avila A01339412
*/
#include "header\Plane.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
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
				myfile << "mtllib Shape.mtl\n";
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
			case 5:
				myfile << createFaces() + "\n";
				break;
			default:
				break;
		}

		cont++;
		if (cont > 6) {
			break;
		}
		else continue;
	}
	myfile.close();
}

string Plane::createVertexes(){
	string line;
	int numFaces = hDivs * vDivs;
	float distHDivs = height / float(hDivs);
	float distVDivs = width / float(vDivs);
	float initialPointx = width / 2.0;
	float initialPointz = height / 2.0;
	for (float i = -initialPointz; i <= initialPointz; i += distHDivs) {
		for (float f = -initialPointx; f <= initialPointx; f += distVDivs) {
			line += "v " + std::to_string(f) + " 0 " + std::to_string(i) + "\n";
		}
	}
	return line;
}

string Plane::createFaces() {
	/*string faces="";
	for (i=vertices.begin(); i !=vertices.end(); i++) {
		cout << *i << " ";
	}*/
	string faces = "";
	for (int i = 0; i <= hDivs; i++) {
		for (int j = 0; j < vDivs; j++) {
			int numV = vDivs + 2 +j;
			faces += "f " + std::to_string(numV) + "//1 " + std::to_string(numV-vDivs) + "//1 " + std::to_string(numV-vDivs-1) + "//1 \n";
			faces += "f " + std::to_string(numV) + "//1 " + std::to_string(numV+1) + "//1 " + std::to_string(numV - vDivs) + "//1 \n";
		}
	}
	return faces;


	
}


