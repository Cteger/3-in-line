#include "blokClass.h"

#include <glut.h>
#include <iostream>

Blok::Blok(int blok_i, int fieldSize, int windSizex, int windSizey)
{
	setSize(windSizey / fieldSize, windSizex / fieldSize);
	setPosition((blok_i % fieldSize) * getSize(0) + 2, (blok_i / fieldSize) * getSize(1) + 2);

	bonus_i = -1;
	blokColor = Empty;
	isExist = 1;
}

void Blok::setBlokColor(int color_i)
{
	switch (color_i)
	{
	case 0:
		blokColor = Empty;
		break;
	case 1:
		blokColor = Red;
		break;
	case 2:
		blokColor = Green;
		break;
	case 3:
		blokColor = Blue;
		break;
	case 4:
		blokColor = Yellow;
		break;
	case 5:
		blokColor = RB;
		break;
	case 6:
		blokColor = GB;
		break;
	case 7:
		blokColor = LGreen;
		break;
	case 8:
		blokColor = LRed;
		break;
	case 9:
		blokColor = Gray;
		break;
	case 10:
		blokColor = CBonus;
		break;
	}
}

void Blok::ResetBlokColor()
{
	switch (blokColor)//enum
	{
	case Empty:
		setColor(1.0, 1.0, 1.0);
		break;
	case Red:
		setColor(1.0, 0.0, 0.0);
		break;
	case Green:
		setColor(0.0, 1.0, 0.0);
		break;
	case Blue:
		setColor(0.0, 0.0, 1.0);
		break;
	case Yellow:
		setColor(1.0, 1.0, 0.0);
		break;
	case RB:
		setColor(1.0, 0.0, 1.0);
		break;
	case GB:
		setColor(0.0, 1.0, 1.0);
		break;
	case LGreen:
		setColor(0.5, 1.0, 0.5);
		break;
	case LRed:
		setColor(1.0, 0.5, 0.5);
		break;
	case Gray:
		setColor(0.2, 0.5, 0.5);
		break;
	case CBonus:
		setColor(0.0, 0.0, 0.0);
		break;
	}
}

void Blok::DrawLine()
{
	glColor3f(0, 0, 0);

	glBegin(GL_LINE_LOOP);

	glVertex2d(position.x + size.x, position.y + size.y);
	glVertex2d(position.x + size.x, position.y);
	glVertex2d(position.x, position.y);
	glVertex2d(position.x, position.y + size.y);

	glEnd();
}
void Blok::DrawBlok()
{
	glBegin(GL_QUADS);

	glColor3f(color.map["red"], color.map["green"], color.map["blue"]);

	glVertex2d(position.x + size.x, position.y + size.y);
	glVertex2d(position.x + size.x, position.y);
	glVertex2d(position.x, position.y);
	glVertex2d(position.x, position.y + size.y);

	glEnd();

	DrawLine();
}