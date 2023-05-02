#include "Bonus.h"
#include "Bloks.h"

#include <glut.h>

struct Window BonusCheck(struct Window wind0, int i, int j)
{
	struct Window wind = wind0;

	if (wind.bloks_buf[i][j] == 10)
	{
		wind = BoombBoom(wind, i, j);
	}
	else if (wind.bloks_buf[i][j] == 11)
	{
		wind = RacketLineLaunch(wind, i, j);
	}
	else if (wind.bloks_buf[i][j] == 12)
	{
		wind = RacketColumLaunch(wind, i, j);
	}

	return wind;
}

struct Window BoombInitialise(struct Window wind0, int i, int j)
{
	struct Window wind = wind0;
	
	wind.bloks[i][j].type = 10;
	wind.bloks_buf[i][j] = 10;
	
	return wind;
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
				wind.bloks_buf[i][j] = 0;
			}
		}
	}
	return wind;
}

void BoombDraw(struct Window wind, int i, int j)
{
	glColor3f(0.16, 0.36, 1.0);

	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
		wind.bloks[i][j].position.y);
	glVertex2d(wind.bloks[i][j].position.x, wind.bloks[i][j].position.y);

	glVertex2d(wind.bloks[i][j].position.x,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);

	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width / 4,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height * 3 / 4);
	glVertex2d(wind.bloks[i][j].position.x,
		wind.bloks[i][j].position.y);
	glVertex2d(wind.bloks[i][j].position.x,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);

	glVertex2d(wind.bloks[i][j].position.x,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width / 4,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height / 4);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.height,
		wind.bloks[i][j].position.y);
	glVertex2d(wind.bloks[i][j].position.x,
		wind.bloks[i][j].position.y);

	glVertex2d(wind.bloks[i][j].position.x,
		wind.bloks[i][j].position.y);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width * 3 / 4,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height / 4);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.height,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.height,
		wind.bloks[i][j].position.y);

	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
		wind.bloks[i][j].position.y);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width * 3 / 4,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height * 3 / 4);
	glVertex2d(wind.bloks[i][j].position.x,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.height,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
}

struct Window RacketLineInitialise(struct Window wind0, int i, int j)
{
	struct Window wind = wind0;

	wind.bloks[i][j].type = 11;
	wind.bloks_buf[i][j] = 11;

	return wind;
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
		wind.bloks_buf[i][jpos] = 0;
	}

	return wind;
}

void RacketLineDraw(struct Window wind, int i, int j)
{
	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
		wind.bloks[i][j].position.y);
	glVertex2d(wind.bloks[i][j].position.x, wind.bloks[i][j].position.y);

	glVertex2d(wind.bloks[i][j].position.x,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);

	glColor3f(1.0, 0.59, 0.66);

	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width / 2,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height * 3 / 4);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height / 2);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width / 2,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height / 4);
	glVertex2d(wind.bloks[i][j].position.x,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height / 2);
	
}

struct Window RacketColumInitialise(struct Window wind0, int i, int j)
{
	struct Window wind = wind0;

	wind.bloks[i][j].type = 12;
	wind.bloks_buf[i][j] = 12;

	return wind;
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
		wind.bloks_buf[ipos][j] = 0;
	}
	return wind;
}

void RacketColumDraw(struct Window wind, int i, int j)
{
	glColor3f(0.0, 0.0, 0.0);

	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
		wind.bloks[i][j].position.y);
	glVertex2d(wind.bloks[i][j].position.x, wind.bloks[i][j].position.y);

	glVertex2d(wind.bloks[i][j].position.x,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);

	glColor3f(1.0, 0.59, 0.66);

	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width / 2,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width * 3 / 4,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height / 2);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width / 2,
		wind.bloks[i][j].position.y);
	glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width / 4,
		wind.bloks[i][j].position.y + wind.bloks[i][j].size.height / 2);
}