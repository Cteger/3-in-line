#include "physObjectClass.h"

void PhysObject::setColor(double r, double g, double b)
{
	color.red = r;
	color.green = g;
	color.blue = b;
}

double PhysObject::getColor(int i)
{
	if (i == 0) return color.red;
	else if (i == 1) return color.green;
	else return color.blue;
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

void PhysObject::setVec(double x, double y)
{
	vect.x = x;
	vect.y = y;
}
double PhysObject::getVec(int i)
{
	if (i == 0)	return vect.x;
	else return vect.y;
}
