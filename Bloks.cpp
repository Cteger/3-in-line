#include "Bloks.h"
#include "Bonus.h"

#include <glut.h>
#include <windows.h>
#include <iostream>

struct Window BloksInitialise(struct Window wind0)
{
	struct Window wind = wind0;

	srand(time(0));

	for (int i = 0; i < wind.field_size; i++)
	{
		for (int j = 0; j < wind.field_size; j++)
		{
			wind.bloks[i][j].size.height = wind.size.height / wind.field_size;
			wind.bloks[i][j].size.width = wind.size.width / wind.field_size;

			wind.bloks[i][j].position.x = (i % wind.field_size)
				* wind.bloks[i][j].size.width + 2;
			wind.bloks[i][j].position.y = (j % wind.field_size)
				* wind.bloks[i][j].size.height + 2;

			wind.bloks[i][j].type = rand() % 5;
			wind.bloks_buf[i][j] = 1;
		}
	}
	return wind;
}

void DrawBloks(struct Window wind)
{
	glBegin(GL_QUADS);
	for (int i = 0; i < wind.field_size; i++)
	{
		for (int j = 0; j < wind.field_size; j++)
		{
			if (wind.bloks[i][j].type == 10)
			{
				BoombDraw(wind, i, j);
			}
			else if (wind.bloks[i][j].type == 11)
			{
				RacketLineDraw(wind, i, j);
			}
			else if (wind.bloks[i][j].type == 12)
			{
				RacketColumDraw(wind, i, j);
			}
			else
			{
				if (wind.bloks[i][j].type == 0)
				{
					glColor3f(1.0, 1.0, 1.0);
				}
				else if (wind.bloks[i][j].type == 1)
				{
					glColor3f(1.0, 0.0, 0.0);
				}
				else if (wind.bloks[i][j].type == 2)
				{
					glColor3f(0.0, 1.0, 0.0);
				}
				else if (wind.bloks[i][j].type == 3)
				{
					glColor3f(0.0, 0.0, 1.0);
				}
				else if (wind.bloks[i][j].type == 4)
				{
					glColor3f(1.0, 1.0, 0.0);
				}
				else if (wind.bloks[i][j].type == 5)
				{
					glColor3f(1.0, 0.0, 1.0);
				}
				else if (wind.bloks[i][j].type == 6)
				{
					glColor3f(0.0, 1.0, 1.0);
				}
				else if (wind.bloks[i][j].type == 7)
				{
					glColor3f(0.5, 1.0, 0.5);
				}
				else if (wind.bloks[i][j].type == 8)
				{
					glColor3f(1.0, 0.5, 0.5);
				}
				else if (wind.bloks[i][j].type == 9)
				{
					glColor3f(0.2, 0.5, 0.5);
				}
				else if (wind.bloks[i][j].type == 10)
				{
					glColor3f(0.0, 0.0, 0.0);
				}

				glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
					wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
				glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
					wind.bloks[i][j].position.y);
				glVertex2d(wind.bloks[i][j].position.x, wind.bloks[i][j].position.y);

				glVertex2d(wind.bloks[i][j].position.x,
					wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
			}
		}
	}
	glEnd();

	for (int i = 0; i < wind.field_size; i++)
	{
		for (int j = 0; j < wind.field_size; j++)
		{
			glColor3f(0, 0, 0);

			glBegin(GL_LINE_LOOP);

			glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
				wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);
			glVertex2d(wind.bloks[i][j].position.x + wind.bloks[i][j].size.width,
				wind.bloks[i][j].position.y);
			glVertex2d(wind.bloks[i][j].position.x, wind.bloks[i][j].position.y);

			glVertex2d(wind.bloks[i][j].position.x,
				wind.bloks[i][j].position.y + wind.bloks[i][j].size.height);

			glEnd();
		}
	}
}

struct Window SwapPlates(struct Window wind0, struct Position first_plate, struct Position second_plate)
{
	struct Window wind = wind0;

	int type_buf;
	int blok_buf_buf;

	blok_buf_buf = wind.bloks_buf[first_plate.x][first_plate.y];
	wind.bloks_buf[first_plate.x][first_plate.y]
		= wind.bloks_buf[second_plate.x][second_plate.y];
	wind.bloks_buf[second_plate.x][second_plate.y] = blok_buf_buf;

	type_buf = wind.bloks[first_plate.x][first_plate.y].type;
	wind.bloks[first_plate.x][first_plate.y].type
		= wind.bloks[second_plate.x][second_plate.y].type;
	wind.bloks[second_plate.x][second_plate.y].type = type_buf;

	return wind;
}

struct Window CheckFildToDestroy(struct Window wind0)
{
	struct Window wind = wind0;
	wind.destroy_count = 0;

	wind.bonus_count = 0;

	for (int i = 0; i < wind.field_size; i++)
	{
		for (int j = 0; j < wind.field_size; j++)
		{
			if (i < wind.field_size - 2)
			{
				if (wind.bloks[i][j].type == wind.bloks[i + 1][j].type
					&& wind.bloks[i][j].type == wind.bloks[i + 2][j].type
					&& wind.bloks[i][j].type != 0)
				{
					wind.bloks_buf[i][j] = 0;

					for (int k = i; k < wind.field_size - 1; k++)
					{
						if (wind.bloks[k][j].type == wind.bloks[k + 1][j].type)
						{
							if (wind.bloks_buf[k + 1][j] == 1)
							{
								wind.bloks_buf[k + 1][j] = 0;
							}
							wind.bonus_count++;
						}
						else
						{
							if (wind.bonus_count == 3 && wind.destroy_start_flag == 1)
							{
								wind = RacketLineInitialise(wind, i, j);
							}
							else if (wind.bonus_count > 5 && wind.destroy_start_flag == 1)
							{
								wind = BoombInitialise(wind, i, j);
							}
							else
							{
								wind.bonus_count = 0;
							}
							break;
						}
					}
				}
			}
			if (j < wind.field_size - 1)
			{
				if (wind.bloks[i][j].type == wind.bloks[i][j + 1].type
					&& wind.bloks[i][j + 1].type == wind.bloks[i][j + 2].type
					&& wind.bloks[i][j].type != 0)
				{
					wind.bloks_buf[i][j] = 0;

					for (int k = j; k < wind.field_size - 1; k++)
					{
						if (wind.bloks[i][k].type == wind.bloks[i][k + 1].type)
						{
							if (wind.bloks_buf[i][k + 1] == 1)
							{
								wind.bloks_buf[i][k + 1] = 0;
							}
							wind.bonus_count++;
						}
						else
						{
							if (wind.bonus_count == 3 && wind.destroy_start_flag == 1)
							{
								wind = RacketColumInitialise(wind, i, j);
							}
							else if (wind.bonus_count > 5 && wind.destroy_start_flag == 1)
							{
								wind = BoombInitialise(wind, i, j);
							}
							else
							{
								wind.bonus_count = 0;
							}
							break;
						}
					}
				}
			}
		}
	}

	wind = Destroy(wind);

	return wind;
}

struct Window Destroy(struct Window wind0)
{
	struct Window wind = wind0;
	wind.destroy_flag = 0;

	for (int i = 0; i < wind.field_size; i++)
	{
		for (int j = 0; j < wind.field_size; j++)
		{
			if (wind.bloks_buf[i][j] == 0)
			{
				wind.destroy_count = 1;
				wind.destroy_flag = 1;
				wind.bloks[i][j].type = 0;
				wind.bloks_buf[i][j] = 1;
				if (wind.destroy_start_flag == 1)
				{
					wind.score++;
				}
			}
		}
	}
	return wind;
}

struct Window CheckFildToFill(struct Window wind0)
{
	srand(time(0));
	struct Window wind = wind0;
	int count = 1;

	while (count != 0)
	{
		count = 0;
		for (int j = 0; j < wind.field_size - 1; j++)
		{
			for (int i = 0; i < wind.field_size; i++)
			{
				if (wind.bloks[i][0].type == 0 && j == 0)
				{
					wind.bloks[i][0].type = rand() % 5;
					wind.bloks_buf[i][0] = 1;
					count++;
				}

				if (wind.bloks[i][j + 1].type == 0)
				{
					wind.bloks[i][j + 1].type = wind.bloks[i][j].type;
					wind.bloks[i][j].type = 0;

					wind.bloks_buf[i][j + 1] = wind.bloks_buf[i][j];
					wind.bloks_buf[i][j] = 1;
					count++;
				}
			}
		}
	}
	return wind;
}