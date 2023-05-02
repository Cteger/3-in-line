#include "Bonus.h"
#include "Bloks.h"

#include <glut.h>

struct Blok* BonusCheck(struct Blok* bloks, int field_size, int i)
{
	if (bloks[i].condition == 10)
	{
		bloks = BoombBoom(bloks, field_size, i);
	}
	else if (bloks[i].condition == 11)
	{
		bloks = RacketLineLaunch(bloks, field_size, i);
	}
	else if (bloks[i].condition == 12)
	{
		bloks = RacketColumLaunch(bloks, field_size, i);
	}

	return bloks;
}

struct Blok BoombInitialise(struct Blok blok0)
{
	struct Blok blok = blok0;
	
	blok.type = 10;
	blok.condition = 10;
	
	return blok;
}

struct Blok* BoombBoom(struct Blok* bloks, int field_size, int pos)
{
	for (int i = pos % field_size - 2;
		i < pos % field_size + 2; i++)
	{
		for (int j = (pos / field_size - 2) * field_size;
			j < (pos / field_size + 2) * field_size; j += field_size)
		{
			if (i >= 0 && i < field_size
				&& j >= 0 && j < field_size * field_size)
			{
				if (i != pos % field_size
					|| j != pos / field_size * field_size)
				{
					bloks = BonusCheck(bloks, field_size, i + j);
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

	glVertex2d(blok.position.x + blok.size.width,
		blok.position.y + blok.size.height);
	glVertex2d(blok.position.x + blok.size.width,
		blok.position.y);
	glVertex2d(blok.position.x, blok.position.y);

	glVertex2d(blok.position.x,
		blok.position.y + blok.size.height);

	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(blok.position.x + blok.size.width,
		blok.position.y + blok.size.height);
	glVertex2d(blok.position.x + blok.size.width / 4,
		blok.position.y + blok.size.height * 3 / 4);
	glVertex2d(blok.position.x,
		blok.position.y);
	glVertex2d(blok.position.x,
		blok.position.y + blok.size.height);

	glVertex2d(blok.position.x,
		blok.position.y + blok.size.height);
	glVertex2d(blok.position.x + blok.size.width / 4,
		blok.position.y + blok.size.height / 4);
	glVertex2d(blok.position.x + blok.size.height,
		blok.position.y);
	glVertex2d(blok.position.x,
		blok.position.y);

	glVertex2d(blok.position.x,
		blok.position.y);
	glVertex2d(blok.position.x + blok.size.width * 3 / 4,
		blok.position.y + blok.size.height / 4);
	glVertex2d(blok.position.x + blok.size.height,
		blok.position.y + blok.size.height);
	glVertex2d(blok.position.x + blok.size.height,
		blok.position.y);

	glVertex2d(blok.position.x + blok.size.width,
		blok.position.y);
	glVertex2d(blok.position.x + blok.size.width * 3 / 4,
		blok.position.y + blok.size.height * 3 / 4);
	glVertex2d(blok.position.x,
		blok.position.y + blok.size.height);
	glVertex2d(blok.position.x + blok.size.height,
		blok.position.y + blok.size.height);
}

struct Blok RacketLineInitialise(struct Blok blok0)
{
	struct Blok blok = blok0;

	blok.type = 11;
	blok.condition = 11;

	return blok;
}

struct Blok* RacketLineLaunch(struct Blok* bloks, int field_size, int pos)
{
	for (int i = pos - pos % field_size;
		i < field_size + pos / field_size + pos - pos % field_size; i++)
	{
		if (i != pos)
		{
			bloks = BonusCheck(bloks, field_size, i);
		}
		bloks[i].condition = 0;
	}

	return bloks;
}

void RacketLineDraw(struct Blok blok)
{
	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(blok.position.x + blok.size.width,
		blok.position.y + blok.size.height);
	glVertex2d(blok.position.x + blok.size.width,
		blok.position.y);
	glVertex2d(blok.position.x, blok.position.y);

	glVertex2d(blok.position.x,
		blok.position.y + blok.size.height);

	glColor3f(1.0, 0.59, 0.66);

	glVertex2d(blok.position.x + blok.size.width / 2,
		blok.position.y + blok.size.height * 3 / 4);
	glVertex2d(blok.position.x + blok.size.width,
		blok.position.y + blok.size.height / 2);
	glVertex2d(blok.position.x + blok.size.width / 2,
		blok.position.y + blok.size.height / 4);
	glVertex2d(blok.position.x,
		blok.position.y + blok.size.height / 2);
	
}

struct Blok RacketColumInitialise(struct Blok blok0)
{
	struct Blok blok = blok0;

	blok.type = 12;
	blok.condition = 12;

	return blok;
}

struct Blok* RacketColumLaunch(struct Blok* bloks, int field_size, int pos)
{
	for (int i = pos % field_size;
		i < field_size * field_size; i += field_size)
	{
		if (i != pos)
		{
			bloks = BonusCheck(bloks, field_size, i);
		}
		bloks[i].condition = 0;
	}
	return bloks;
}

void RacketColumDraw(struct Blok blok)
{
	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(blok.position.x + blok.size.width,
		blok.position.y + blok.size.height);
	glVertex2d(blok.position.x + blok.size.width,
		blok.position.y);
	glVertex2d(blok.position.x, blok.position.y);

	glVertex2d(blok.position.x,
		blok.position.y + blok.size.height);

	glColor3f(1.0, 0.59, 0.66);

	glVertex2d(blok.position.x + blok.size.width / 2,
		blok.position.y + blok.size.height);
	glVertex2d(blok.position.x + blok.size.width * 3 / 4,
		blok.position.y + blok.size.height / 2);
	glVertex2d(blok.position.x + blok.size.width / 2,
		blok.position.y);
	glVertex2d(blok.position.x + blok.size.width / 4,
		blok.position.y + blok.size.height / 2);
}