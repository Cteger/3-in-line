#include "windowClass.h"

#include <windows.h>
#include <iostream>
#include <glut.h>


//Window::Window()
//{
//
//}

Window::Window()
{
	setSize(WINDOW_SIZEX + 1, WINDOW_SIZEY + 1);
	setPosition(WINDOW_POSITIONX, WINDOW_POSITIONY);

	fieldSize = FIELD_SIZE;

	destroy_flag = 0;
	destroy_start_flag = 0;

	for (int i = 0; i < fieldSize * fieldSize; i++)
	{
		auto new_blok = new Blok(i, fieldSize, getSize(0), getSize(1));
		bloks.push_back(new_blok);
	}

	StartFunc();

	destroy_flag = 0;
}

void Window::StartFunc()
{
	destroy_count = 1;

	CheckFildToFill();

	while (destroy_count != 0)
	{
		CheckFildToDestroy();

		CheckFildToFill();
	}

	destroy_start_flag = 1;
}

void Window::CheckFildToDestroy()
{
	destroy_count = 0;
	bonus_count = 0;

	for (int i = 0; i < fieldSize * fieldSize; i++)
	{
		if (i % fieldSize < fieldSize - 2)
		{
			if (bloks[i].type == bloks[i + 1].type
				&& bloks[i].type == bloks[i + 2].type
				&& bloks[i].type != 0)
			{
				bloks[i].condition = 0;

				for (int k = i; k % fieldSize < fieldSize - 1; k++)
				{
					if (bloks[k].type == bloks[k + 1].type)
					{
						if (bloks[k + 1].condition == 1)
						{
							bloks[k + 1].condition = 0;
						}
						bonus_count++;
					}
					else
					{
						if (bonus_count == 3 && destroy_start_flag == 1)
						{
							bloks[i] = RacketLineInitialise(bloks[i]);
						}
						else if (bonus_count > 5 && destroy_start_flag == 1)
						{
							bloks[i] = BoombInitialise(bloks[i]);
						}
						else
						{
							bonus_count = 0;
						}
					}
				}
			}
		}
		if (i / fieldSize < fieldSize - 2)
		{
			if (bloks[i].type == bloks[i + fieldSize].type
				&& bloks[i].type == bloks[i + 2 * fieldSize].type
				&& bloks[i].type != 0)
			{
				bloks[i].condition = 0;

				for (int k = i; k < fieldSize * fieldSize - 1; k += fieldSize)
				{
					if (bloks[k].type == bloks[k + fieldSize].type)
					{
						if (bloks[k + fieldSize].condition == 1)
						{
							bloks[k + fieldSize].condition = 0;
						}
						bonus_count++;
					}
					else
					{
						if (bonus_count == 3 && destroy_start_flag == 1)
						{
							bloks[i] = RacketColumInitialise(bloks[i]);
						}
						else if (bonus_count > 5 && destroy_start_flag == 1)
						{
							bloks[i] = BoombInitialise(bloks[i]);
						}
						else
						{
							bonus_count = 0;
						}
					}
				}
			}
		}
	}

	Destroy();
}

void Window::CheckFildToFill()
{
	srand(time(0));
	int count = 1;

	while (count != 0)
	{
		count = 0;

		for (int i = 0; i < fieldSize * fieldSize; i++)
		{
			if (bloks[i]->getType() == 0 && i / fieldSize == 0)
			{
				bloks[i]->setType(rand() % 5);
				bloks[i]->setCondition(1);
				count++;
			}

			if (bloks[i + fieldSize]->getType() == 0)
			{
				bloks[i + fieldSize]->setType(bloks[i]->getType());
				bloks[i]->setType(0);

				bloks[i + fieldSize]->setCondition(bloks[i].condition);
				bloks[i]->setCondition(1);
				count++;
			}
		}
	}
}

void Window::Destroy()
{
	destroy_flag = 0;

	for (int i = 0; i < fieldSize * fieldSize; i++)
	{
		if (bloks[i]->getCondition() == 0)
		{
			destroy_count = 1;
			destroy_flag = 1;
			bloks[i]->setType(0);
			bloks[i]->setCondition(1);
			if (destroy_start_flag == 1)
			{
				score++;
			}
		}
	}
}

void Window::DrawBloks()
{
	for (int i = 0; i < fieldSize * fieldSize; i++)
	{
		bloks[i]->DrawBlok();
	}
}

void Window::CheckPlate(int x, int y)
{
	if (plate_flag == 0)
	{
		first_plate = x / bloks[0]->getSize(0) + y / bloks[0]->getSize(1) * fieldSize;
		plate_flag = 1;
	}
	else if (plate_flag == 1)
	{
		second_plate = x / bloks[0]->getSize(0) + y / bloks[0]->getSize(1) * fieldSize;
		plate_flag = 2;
	}

}

void Window::CheckSwap()
{
	if (plate_flag == 2)
	{
		if (((first_plate / fieldSize + 1) == (second_plate / fieldSize)
			|| ((first_plate / fieldSize - 1) == (second_plate / fieldSize))
			&& (first_plate % fieldSize) == (second_plate % fieldSize))
			|| ((((first_plate + 1) % fieldSize) == (second_plate % fieldSize)
			|| ((first_plate - 1) % fieldSize) == (second_plate % fieldSize))
			&& (first_plate / fieldSize) == (second_plate / fieldSize)))
		{
			SwapPlates();

			Draw();
			Sleep(SLEEP);

			bloks[first_plate]->BonusCheck(bloks[first_plate]->getCondition(), fieldSize, first_plate);
			bloks[second_plate]->BonusCheck(bloks[second_plate]->getCondition(), fieldSize, second_plate);

			CheckFildToDestroy();
			Draw();

			if (destroy_flag == 0)
			{
				SwapPlates();
				Draw();
			}
			else
			{
				destroy_flag = 0;
			}
		}
		plate_flag = 0;
	}
}

void Window::SwapPlates()
{
	int type_buf;
	int condition_buf;

	condition_buf = bloks[first_plate]->getCondition();
	bloks[first_plate]->setCondition(bloks[second_plate]->getCondition());
	bloks[second_plate]->setCondition(condition_buf);

	type_buf = bloks[first_plate]->getType();
	bloks[first_plate]->setType(bloks[second_plate]->getType());
	bloks[second_plate]->setType(type_buf);
}


int Window::getScore()
{
	return score;
}

int Window::getFieldSize()
{
	return fieldSize;
}