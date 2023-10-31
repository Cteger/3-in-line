#include "blokClass.h"
#include "bonusClass.h"

#include <glut.h>
#include <iostream>

Blok::Blok()
{

}

Blok::Blok(int i, int fieldSize, int windSizex, int windSizey)
{
	setSize(windSizey / fieldSize, windSizex / fieldSize);
	setPosition((i % fieldSize) * getSize(0) + 2, (i / fieldSize)	* getSize(1) + 2);

	srand(time(0));
	type = rand() % 5;
	condition = 1;
}

void Blok::ResetBlokColor()
{
	if (type == 0)
	{
		glColor3f(1.0, 1.0, 1.0);
	}
	else if (type == 1)
	{
		glColor3f(1.0, 0.0, 0.0);
	}
	else if (type == 2)
	{
		glColor3f(0.0, 1.0, 0.0);
	}
	else if (type == 3)
	{
		glColor3f(0.0, 0.0, 1.0);
	}
	else if (type == 4)
	{
		glColor3f(1.0, 1.0, 0.0);
	}
	else if (type == 5)
	{
		glColor3f(1.0, 0.0, 1.0);
	}
	else if (type == 6)
	{
		glColor3f(0.0, 1.0, 1.0);
	}
	else if (type == 7)
	{
		glColor3f(0.5, 1.0, 0.5);
	}
	else if (type == 8)
	{
		glColor3f(1.0, 0.5, 0.5);
	}
	else if (type == 9)
	{
		glColor3f(0.2, 0.5, 0.5);
	}
	else if (type == 10)
	{
		glColor3f(0.0, 0.0, 0.0);
	}
}

void Blok::DrawBlok()
{
	if (type == 10)
	{
		BoombDraw();
	}
	else if (type == 11)
	{
		RacketLineDraw();
	}
	else if (type == 12)
	{
		RacketColumDraw();
	}
	else
	{
		ResetBlokColor();

		glBegin(GL_QUADS);

		glColor3f(getColor(0), getColor(1), getColor(2));

		glVertex2d(getPosition(0) + getSize(0), getPosition(1) + getSize(1));
		glVertex2d(getPosition(0) + getSize(0),	getPosition(1));
		glVertex2d(getPosition(0), getPosition(1));
		glVertex2d(getPosition(0), getPosition(1) + getSize(1));

		glEnd();
	}
	
	glColor3f(0, 0, 0);

	glBegin(GL_LINE_LOOP);

	glVertex2d(getPosition(0) + getSize(0),	getPosition(1) + getSize(1));
	glVertex2d(getPosition(0) + getSize(0),	getPosition(1));
	glVertex2d(getPosition(0), getPosition(1));
	glVertex2d(getPosition(0), getPosition(1) + getSize(1));

	glEnd();
}

void Blok::setType(int type)
{
	this->type = type;
}
int Blok::getType()
{
	return type;
}

void Blok::setCondition(int condition)
{
	this->condition = condition;
}

int Blok::getCondition()
{
	return condition;
}