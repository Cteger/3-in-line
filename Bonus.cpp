#include "Bonus.h"
#include "Bloks.h"

#include <glut.h>

struct Window BonusCheck(struct Window wind0, int i, int j)
{
	struct Window wind = wind0;

	if (wind.bloks[i][j].condition == 10)
	{
		wind = BoombBoom(wind, i, j);
	}
	else if (wind.bloks[i][j].condition == 11)
	{
		wind = RacketLineLaunch(wind, i, j);
	}
	else if (wind.bloks[i][j].condition == 12)
	{
		wind = RacketColumLaunch(wind, i, j);
	}

	return wind;
}

struct Blok BoombInitialise(struct Blok blok0)
{
	struct Blok blok = blok0;
	
	blok.type = 10;
	blok.condition = 10;
	
	return blok;
}

struct Window BoombBoom(struct Window wind0, int ipos, int jpos)
{
	struct Window wind = wind0;

	for (int i = ipos - 2; i < ipos + 2; i++)
	{
		for (int j = jpos - 2; j < jpos + 2; j++)
		{
			if (i >= 0 && i < wind.field_size
				&& j >= 0 && j < wind.field_size)
			{
				if (i != ipos && j != jpos)
				{
					wind = BonusCheck(wind, i, j);
				}
				wind.bloks[i][j].condition = 0;
			}
		}
	}
	return wind;
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

struct Window RacketLineLaunch(struct Window wind0, int ipos, int jpos)
{
	struct Window wind = wind0;

	for (int i = 0; i < wind.field_size; i++)
	{
		if (i != ipos)
		{
			wind = BonusCheck(wind, i, jpos);
		}
		wind.bloks[i][jpos].condition = 0;
	}

	return wind;
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

struct Window RacketColumLaunch(struct Window wind0, int ipos, int jpos)
{
	struct Window wind = wind0;

	for (int j = 0; j < wind.field_size; j++)
	{
		if (j != jpos)
		{
			wind = BonusCheck(wind, ipos, j);
		}
		wind.bloks[ipos][j].condition = 0;
	}
	return wind;
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