#include "bonusClass.h"

#include <glut.h>

Bonus::Bonus(int posx, int posy, int sizex, int sizey, int blok_i)
{
	setSize(sizex, sizey);
}

void Boomb::BonusInitialize(int fieldSize, std::array<Blok, FIELD_SIZE* FIELD_SIZE>& bloks, int pos)
{
	srand(time(0));
	bloks[pos].setIsExist(false);
	bloks[pos].setBonus_i(false);
	int count = 0;
	while (count < 5)
	{
		pos = rand() % (fieldSize * fieldSize);
		if (bloks[pos].getIsExist())
		{
			bloks[pos].setIsExist(false);
			count++;
		}
	}
}

void LineRacket::BonusInitialize(int fieldSize, std::array<Blok, FIELD_SIZE* FIELD_SIZE>& bloks, int pos)
{
	bloks[pos].setBonus_i(false);

	for (int i = pos - pos % fieldSize; i < pos - pos % fieldSize + fieldSize; i++)
	{
		bloks[i].setIsExist(false);
	}
}

void ColumRacket::BonusInitialize(int fieldSize, std::array<Blok, FIELD_SIZE* FIELD_SIZE>& bloks, int pos)
{
	for (int i = pos % fieldSize; i < fieldSize * fieldSize; i += fieldSize)
	{
		bloks[i].setIsExist(false);
	}
}

void Boomb::DrawBonus(int blokPosx, int blokPosy)
{
	glBegin(GL_QUADS);

	glColor3f(0.16, 0.36, 1.0);

	glVertex2d(blokPosx + getSize(0), blokPosy + getSize(1));
	glVertex2d(blokPosx + getSize(0), blokPosy);
	glVertex2d(blokPosx, blokPosy);
	glVertex2d(blokPosx, blokPosy + getSize(1));

	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(blokPosx + getSize(0), blokPosy + getSize(1));
	glVertex2d(blokPosx + getSize(0) / 4, blokPosy + getSize(1) * 3 / 4);
	glVertex2d(blokPosx, blokPosy);
	glVertex2d(blokPosx, blokPosy + getSize(1));

	glVertex2d(blokPosx, blokPosy + getSize(1));
	glVertex2d(blokPosx + getSize(0) / 4, blokPosy + getSize(1) / 4);
	glVertex2d(blokPosx + getSize(1), blokPosy);
	glVertex2d(blokPosx, blokPosy);

	glVertex2d(blokPosx, blokPosy);
	glVertex2d(blokPosx + getSize(0) * 3 / 4, blokPosy + getSize(1) / 4);
	glVertex2d(blokPosx + getSize(1), blokPosy + getSize(1));
	glVertex2d(blokPosx + getSize(1), blokPosy);

	glVertex2d(blokPosx + getSize(0), blokPosy);
	glVertex2d(blokPosx + getSize(0) * 3 / 4, blokPosy + getSize(1) * 3 / 4);
	glVertex2d(blokPosx, blokPosy + getSize(1));
	glVertex2d(blokPosx + getSize(1), blokPosy + getSize(1));

	glEnd();
}


void LineRacket::DrawBonus(int blokPosx, int blokPosy)
{
	glBegin(GL_QUADS);

	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(blokPosx + getSize(0), blokPosy + getSize(1));
	glVertex2d(blokPosx + getSize(0), blokPosy);
	glVertex2d(blokPosx, blokPosy);
	glVertex2d(blokPosx, blokPosy + getSize(1));

	glColor3f(1.0, 0.59, 0.66);

	glVertex2d(blokPosx + getSize(0) / 2, blokPosy + getSize(1) * 3 / 4);
	glVertex2d(blokPosx + getSize(0), blokPosy + getSize(1) / 2);
	glVertex2d(blokPosx + getSize(0) / 2, blokPosy + getSize(1) / 4);
	glVertex2d(blokPosx, blokPosy + getSize(1) / 2);

	glEnd();
}

void ColumRacket::DrawBonus(int blokPosx, int blokPosy)
{
	glBegin(GL_QUADS);

	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(blokPosx + getSize(0), blokPosy + getSize(1));
	glVertex2d(blokPosx + getSize(0), blokPosy);
	glVertex2d(blokPosx, blokPosy);
	glVertex2d(blokPosx, blokPosy + getSize(1));

	glColor3f(1.0, 0.59, 0.66);

	glVertex2d(blokPosx + getSize(0) / 2, blokPosy + getSize(1));
	glVertex2d(blokPosx + getSize(0) * 3 / 4, blokPosy + getSize(1) / 2);
	glVertex2d(blokPosx + getSize(0) / 2, blokPosy);
	glVertex2d(blokPosx + getSize(0) / 4, blokPosy + getSize(1) / 2);

	glEnd();
}