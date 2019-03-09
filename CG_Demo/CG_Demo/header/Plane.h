#pragma once
#include <stdio.h>
#include <string>
#include <list>
using namespace std;

class Plane
{
public:
	Plane();
	Plane(float _width, float _height, int _vDivs, int _hDivs);
	~Plane();

	float width, height;
	int vDivs, hDivs;

	void createObj();
	string createVertexes();
	string createFaces();
};

