#include "physObjectClass.h"

#include <glut.h>


void PhysObject::setColor(double r, double g, double b)
{
	color.map["red"] = r;
	color.map["green"] = g;
	color.map["blue"] = b;
}

double PhysObject::getColor(std::string new_color)
{
	if (new_color == "red") return color.map["red"];
	else if (new_color == "green") return color.map["green"];
	else if (new_color == "blue") return color.map["blue"];
	else return 0;
}


void PhysObject::setSize(int x, int y)
{
	size.x = x;
	size.y = y;
}
int PhysObject::getSize(int i)
{
	if (i == 0)	return size.x;
	else return size.y;
}


void PhysObject::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}
int PhysObject::getPosition(int i)
{
	if (i == 0)	return position.x;
	else return position.y;
}
