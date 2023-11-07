#pragma once

#include "vectorStruct.h"
#include "colorMapStruct.h"

class PhysObject
{
protected:
	ColorMap color;
	CustomVec position; // без шаблона
	CustomVec size;

public:
	void setColor(double r, double g, double b);
	double getColor(std::string color);

	void setSize(int x, int y);
	int getSize(int i);

	void setPosition(int x, int y);
	int getPosition(int i);
};