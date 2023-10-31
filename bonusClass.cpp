#include "bonusClass.h"

#include <glut.h>

void Bonus::BonusCheck(int condition, int fieldSize, int i)
{
	if (condition == 10)
	{
		BoombBoom(fieldSize, i);
	}
	else if (condition == 11)
	{
		RacketLineLaunch(fieldSize, i);
	}
	else if (condition == 12)
	{
		RacketColumLaunch(fieldSize, i);
	}
}

void Bonus::BoombInitialise()
{
	type = 10;
	condition = 10;
}

struct Blok* BoombBoom(struct Blok* bloks, int fieldSize, int pos)
{
	for (int i = pos % fieldSize - 2;
		i < pos % fieldSize + 2; i++)
	{
		for (int j = (pos / fieldSize - 2) * fieldSize;
			j < (pos / fieldSize + 2) * fieldSize; j += fieldSize)
		{
			if (i >= 0 && i < fieldSize
				&& j >= 0 && j < fieldSize * fieldSize)
			{
				if (i != pos % fieldSize
					|| j != pos / fieldSize * fieldSize)
				{
					bloks = BonusCheck(bloks, fieldSize, i + j);
				}
				bloks[i + j].condition = 0;
			}
		}
	}
	return bloks;
}

void BoombDraw(struct Blok blok)
{
	glColor3f(0.16, 0.36, 1.0);

	glVertex2d(blok.getPosition(0) + blok.getSize(0), blok.getPosition(1) + blok.getSize(1));
	glVertex2d(blok.getPosition(0) + blok.getSize(0), blok.getPosition(1));
	glVertex2d(blok.getPosition(0), blok.getPosition(1));

	glVertex2d(blok.getPosition(0),
		blok.getPosition(1) + blok.getSize(1));

	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(blok.getPosition(0) + blok.getSize(0),
		blok.getPosition(1) + blok.getSize(1));
	glVertex2d(blok.getPosition(0) + blok.getSize(0) / 4,
		blok.getPosition(1) + blok.getSize(1) * 3 / 4);
	glVertex2d(blok.getPosition(0),
		blok.getPosition(1));
	glVertex2d(blok.getPosition(0),
		blok.getPosition(1) + blok.getSize(1));

	glVertex2d(blok.getPosition(0),
		blok.getPosition(1) + blok.getSize(1));
	glVertex2d(blok.getPosition(0) + blok.getSize(0) / 4,
		blok.getPosition(1) + blok.getSize(1) / 4);
	glVertex2d(blok.getPosition(0) + blok.getSize(1),
		blok.getPosition(1));
	glVertex2d(blok.getPosition(0),
		blok.getPosition(1));

	glVertex2d(blok.getPosition(0),
		blok.getPosition(1));
	glVertex2d(blok.getPosition(0) + blok.getSize(0) * 3 / 4,
		blok.getPosition(1) + blok.getSize(1) / 4);
	glVertex2d(blok.getPosition(0) + blok.getSize(1),
		blok.getPosition(1) + blok.getSize(1));
	glVertex2d(blok.getPosition(0) + blok.getSize(1),
		blok.getPosition(1));

	glVertex2d(blok.getPosition(0) + blok.getSize(0),
		blok.getPosition(1));
	glVertex2d(blok.getPosition(0) + blok.getSize(0) * 3 / 4,
		blok.getPosition(1) + blok.getSize(1) * 3 / 4);
	glVertex2d(blok.getPosition(0),
		blok.getPosition(1) + blok.getSize(1));
	glVertex2d(blok.getPosition(0) + blok.getSize(1),
		blok.getPosition(1) + blok.getSize(1));
}

struct Blok RacketLineInitialise(struct Blok blok0)
{
	struct Blok blok = blok0;

	blok.type = 11;
	blok.condition = 11;

	return blok;
}

struct Blok* RacketLineLaunch(struct Blok* bloks, int fieldSize, int pos)
{
	for (int i = pos - pos % fieldSize;
		i < fieldSize + pos / fieldSize + pos - pos % fieldSize; i++)
	{
		if (i != pos)
		{
			bloks = BonusCheck(bloks, fieldSize, i);
		}
		bloks[i].condition = 0;
	}

	return bloks;
}

void RacketLineDraw(struct Blok blok)
{
	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(blok.getPosition(0) + blok.getSize(0),
		blok.getPosition(1) + blok.getSize(1));
	glVertex2d(blok.getPosition(0) + blok.getSize(0),
		blok.getPosition(1));
	glVertex2d(blok.getPosition(0), blok.getPosition(1));

	glVertex2d(blok.getPosition(0),
		blok.getPosition(1) + blok.getSize(1));

	glColor3f(1.0, 0.59, 0.66);

	glVertex2d(blok.getPosition(0) + blok.getSize(0) / 2,
		blok.getPosition(1) + blok.getSize(1) * 3 / 4);
	glVertex2d(blok.getPosition(0) + blok.getSize(0),
		blok.getPosition(1) + blok.getSize(1) / 2);
	glVertex2d(blok.getPosition(0) + blok.getSize(0) / 2,
		blok.getPosition(1) + blok.getSize(1) / 4);
	glVertex2d(blok.getPosition(0),
		blok.getPosition(1) + blok.getSize(1) / 2);
	
}

struct Blok RacketColumInitialise(struct Blok blok0)
{
	struct Blok blok = blok0;

	blok.type = 12;
	blok.condition = 12;

	return blok;
}

struct Blok* RacketColumLaunch(struct Blok* bloks, int fieldSize, int pos)
{
	for (int i = pos % fieldSize;
		i < fieldSize * fieldSize; i += fieldSize)
	{
		if (i != pos)
		{
			bloks = BonusCheck(bloks, fieldSize, i);
		}
		bloks[i].condition = 0;
	}
	return bloks;
}

void RacketColumDraw(struct Blok blok)
{
	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(blok.getPosition(0) + blok.getSize(0),
		blok.getPosition(1) + blok.getSize(1));
	glVertex2d(blok.getPosition(0) + blok.getSize(0),
		blok.getPosition(1));
	glVertex2d(blok.getPosition(0), blok.getPosition(1));

	glVertex2d(blok.getPosition(0),
		blok.getPosition(1) + blok.getSize(1));

	glColor3f(1.0, 0.59, 0.66);

	glVertex2d(blok.getPosition(0) + blok.getSize(0) / 2,
		blok.getPosition(1) + blok.getSize(1));
	glVertex2d(blok.getPosition(0) + blok.getSize(0) * 3 / 4,
		blok.getPosition(1) + blok.getSize(1) / 2);
	glVertex2d(blok.getPosition(0) + blok.getSize(0) / 2,
		blok.getPosition(1));
	glVertex2d(blok.getPosition(0) + blok.getSize(0) / 4,
		blok.getPosition(1) + blok.getSize(1) / 2);
}