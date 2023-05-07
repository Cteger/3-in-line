#include "Bloks.h"
#include "Bonus.h"

#include <glut.h>
#include <iostream>

struct Blok* BloksInitialise(struct Window wind0)
{
	struct Window wind = wind0;

	wind.bloks = new struct Blok[wind.field_size * wind.field_size];

	srand(time(0));

	for (int i = 0; i < wind.field_size * wind.field_size; i++)
	{
		wind.bloks[i].size.height = wind.size.height / wind.field_size;
		wind.bloks[i].size.width = wind.size.width / wind.field_size;

		wind.bloks[i].position.x = (i % wind.field_size)
			* wind.bloks[i].size.width + 2;
		wind.bloks[i].position.y = (i / wind.field_size)
			* wind.bloks[i].size.height + 2;

		wind.bloks[i].type = rand() % 5;
		wind.bloks[i].condition = 1;		
	}
	return wind.bloks;
}

void DrawBloks(struct Blok bloks[FIELD_SIZE], int field_size)
{
	glBegin(GL_QUADS);
	for (int i = 0; i < field_size * field_size; i++)
	{
		if (bloks[i].type == 10)
		{
			BoombDraw(bloks[i]);
		}
		else if (bloks[i].type == 11)
		{
			RacketLineDraw(bloks[i]);
		}
		else if (bloks[i].type == 12)
		{
			RacketColumDraw(bloks[i]);
		}
		else
		{
			if (bloks[i].type == 0)
			{
				glColor3f(1.0, 1.0, 1.0);
			}
			else if (bloks[i].type == 1)
			{
				glColor3f(1.0, 0.0, 0.0);
			}
			else if (bloks[i].type == 2)
			{
				glColor3f(0.0, 1.0, 0.0);
			}
			else if (bloks[i].type == 3)
			{
				glColor3f(0.0, 0.0, 1.0);
			}
			else if (bloks[i].type == 4)
			{
				glColor3f(1.0, 1.0, 0.0);
			}
			else if (bloks[i].type == 5)
			{
				glColor3f(1.0, 0.0, 1.0);
			}
			else if (bloks[i].type == 6)
			{
				glColor3f(0.0, 1.0, 1.0);
			}
			else if (bloks[i].type == 7)
			{
				glColor3f(0.5, 1.0, 0.5);
			}
			else if (bloks[i].type == 8)
			{
				glColor3f(1.0, 0.5, 0.5);
			}
			else if (bloks[i].type == 9)
			{
				glColor3f(0.2, 0.5, 0.5);
			}
			else if (bloks[i].type == 10)
			{
				glColor3f(0.0, 0.0, 0.0);
			}

			glVertex2d(bloks[i].position.x + bloks[i].size.width,
				bloks[i].position.y + bloks[i].size.height);
			glVertex2d(bloks[i].position.x + bloks[i].size.width,
				bloks[i].position.y);
			glVertex2d(bloks[i].position.x, bloks[i].position.y);

			glVertex2d(bloks[i].position.x,
				bloks[i].position.y + bloks[i].size.height);
		}
	}
	glEnd();

	for (int i = 0; i < field_size * field_size; i++)
	{
			glColor3f(0, 0, 0);

			glBegin(GL_LINE_LOOP);

			glVertex2d(bloks[i].position.x + bloks[i].size.width,
				bloks[i].position.y + bloks[i].size.height);
			glVertex2d(bloks[i].position.x + bloks[i].size.width,
				bloks[i].position.y);
			glVertex2d(bloks[i].position.x, bloks[i].position.y);

			glVertex2d(bloks[i].position.x,
				bloks[i].position.y + bloks[i].size.height);

			glEnd();
	}
}

struct Window SwapPlates(struct Window wind0, int first_plate, int second_plate)
{
	struct Window wind = wind0;

	int type_buf;
	int condition_buf;

	condition_buf = wind.bloks[first_plate].condition;
	wind.bloks[first_plate].condition = wind.bloks[second_plate].condition;
	wind.bloks[second_plate].condition = condition_buf;

	type_buf = wind.bloks[first_plate].type;
	wind.bloks[first_plate].type = wind.bloks[second_plate].type;
	wind.bloks[second_plate].type = type_buf;

	return wind;
}

struct Window CheckFildToDestroy(struct Window wind0)
{
	struct Window wind = wind0;
	wind.destroy_count = 0;

	wind.bonus_count = 0;

	for (int i = 0; i < wind.field_size * wind.field_size; i++)
	{
		if (i % wind.field_size < wind.field_size - 2)
		{
			if (wind.bloks[i].type == wind.bloks[i + 1].type
				&& wind.bloks[i].type == wind.bloks[i + 2].type
				&& wind.bloks[i].type != 0)
			{
				wind.bloks[i].condition = 0;

				for (int k = i; k % wind.field_size < wind.field_size - 1; k++)
				{
					if (wind.bloks[k].type == wind.bloks[k + 1].type)
					{
						if (wind.bloks[k + 1].condition == 1)
						{
							wind.bloks[k + 1].condition = 0;
						}
						wind.bonus_count++;
					}
					else
					{
						if (wind.bonus_count == 3 && wind.destroy_start_flag == 1)
						{
							wind.bloks[i] = RacketLineInitialise(wind.bloks[i]);
						}
						else if (wind.bonus_count > 5 && wind.destroy_start_flag == 1)
						{
							wind.bloks[i] = BoombInitialise(wind.bloks[i]);
						}
						else
						{
							wind.bonus_count = 0;
						}
					}
				}
			}
		}
		if (i / wind.field_size < wind.field_size - 2)
		{
			if (wind.bloks[i].type == wind.bloks[i + wind.field_size].type
				&& wind.bloks[i].type == wind.bloks[i + 2 * wind.field_size].type
				&& wind.bloks[i].type != 0)
			{
				wind.bloks[i].condition = 0;

				for (int k = i; k < wind.field_size * wind.field_size - 1; k += wind.field_size)
				{
					if (wind.bloks[k].type == wind.bloks[k + wind.field_size].type)
					{
						if (wind.bloks[k + wind.field_size].condition == 1)
						{
							wind.bloks[k + wind.field_size].condition = 0;
						}
						wind.bonus_count++;
					}
					else
					{
						if (wind.bonus_count == 3 && wind.destroy_start_flag == 1)
						{
							wind.bloks[i] = RacketColumInitialise(wind.bloks[i]);
						}
						else if (wind.bonus_count > 5 && wind.destroy_start_flag == 1)
						{
							wind.bloks[i] = BoombInitialise(wind.bloks[i]);
						}
						else
						{
							wind.bonus_count = 0;
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

	for (int i = 0; i < wind.field_size * wind.field_size; i++)
	{
		if (wind.bloks[i].condition == 0)
		{
			wind.destroy_count = 1;
			wind.destroy_flag = 1;
			wind.bloks[i].type = 0;
			wind.bloks[i].condition = 1;
			if (wind.destroy_start_flag == 1)
			{
				wind.score++;
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

		for (int i = 0; i < wind.field_size * wind.field_size; i++)
		{
			if (wind.bloks[i].type == 0 && i / wind.field_size == 0)
			{
				wind.bloks[i].type = rand() % 5;
				wind.bloks[i].condition = 1;
				count++;
			}

			if (wind.bloks[i + wind.field_size].type == 0)
			{
				wind.bloks[i + wind.field_size].type = wind.bloks[i].type;
				wind.bloks[i].type = 0;

				wind.bloks[i + wind.field_size].condition = wind.bloks[i].condition;
				wind.bloks[i].condition = 1;
				count++;
			}
		}
	}
	return wind;
}