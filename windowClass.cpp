#include "windowClass.h"

#include <windows.h>
#include <iostream>
#include <glut.h>


Window::Window(int fieldSize, int windSizex, int windSizey, int windPosx, int windPosy)
{
	setSize(windSizex + 1, windSizey + 1);
	setPosition(windPosx, windPosy);
	firstPlate_i = 0;
	secondPlate_i = 0;

	plateChooseCount = 0;
	startFlag = 0;
	score = 0;
	this->fieldSize = fieldSize;
}

void Window::StartFunc()
{
	CheckFildToFill();

	while (CheckFildToDestroy())
	{
		CheckFildToFill();
	}

	startFlag = 1;
}

void Window::BloksInitialize()
{
	for (int i = 0; i < fieldSize * fieldSize; i++)
	{
		bloks[i] = Blok(i, fieldSize, getSize(0), getSize(1));
	}
}

bool Window::CheckFildToDestroy()
{
	int destroyLineCount;
	int destroyColumCount;
	for (int i = 0; i < fieldSize * fieldSize; i++)
	{
		destroyLineCount = LineCheck(i);
		destroyColumCount = ColumCheck(i);
		if (destroyLineCount >= 3)
		{
			for (int j = i; j < i + destroyLineCount; j++)
			{
				bloks[j].setIsExist(false);
			}
		}
		if (destroyColumCount >= 3)
		{
			for (int j = i; j < i + destroyColumCount * fieldSize; j += fieldSize)
			{
				bloks[j].setIsExist(false);
			}
		}
		if (destroyLineCount == 4 && startFlag == 1)
		{
			bonuses.push_back(new LineRacket(bloks[i].getPosition(0), bloks[i].getPosition(1), bloks[i].getSize(0), bloks[i].getSize(1), i));
			bloks[i].setBonus_i(bonuses.size() - 1);
			bloks[i].setBlokColor(CBonus);
			bloks[i].setIsExist(true);
		}
		if (destroyColumCount == 4 && startFlag == 1)
		{
			bonuses.push_back(new ColumRacket(bloks[i].getPosition(0), bloks[i].getPosition(1), bloks[i].getSize(0), bloks[i].getSize(1), i));
			bloks[i].setBonus_i(bonuses.size() - 1);
			bloks[i].setBlokColor(CBonus);
			bloks[i].setIsExist(true);
		}
		if ((destroyLineCount == 5 || destroyColumCount == 5) && startFlag == 1)
		{
			bonuses.push_back(new Boomb(bloks[i].getPosition(0), bloks[i].getPosition(1), bloks[i].getSize(0), bloks[i].getSize(1), i));
			bloks[i].setBonus_i(bonuses.size() - 1);
			bloks[i].setBlokColor(CBonus);
			bloks[i].setIsExist(true);
		}
	}
	return Destroy();
}

int Window::LineCheck(int blok_i)
{
	int count = 1;

	if (blok_i % fieldSize < fieldSize - 1)
	{
		if (bloks[blok_i].getBlokColor() == bloks[blok_i + 1].getBlokColor())
		{
			count += LineCheck(blok_i + 1);
		}
	}
	return count;
}

int Window::ColumCheck(int blok_i)
{
	int count = 1;

	if (blok_i / fieldSize < fieldSize - 1)
	{
		if (bloks[blok_i].getBlokColor() == bloks[blok_i + fieldSize].getBlokColor())
		{
			count += ColumCheck(blok_i + fieldSize);
		}
	}
	return count;
}

void Window::CheckFildToFill()
{
	srand(time(0));
	int count = 1;

	while (count != 0)
	{
		count = 0;

		for (int i = 0; i < fieldSize * (fieldSize - 1); i++)
		{
			if (bloks[i].getBlokColor() == 0 && i / fieldSize == 0)
			{
				bloks[i].setBlokColor(rand() % 5);
				bloks[i].setIsExist(1);
			}

			if (bloks[i].getBlokColor() != 0 && bloks[i + fieldSize].getBlokColor() == 0)
			{
				int fall_count = ColumCheck(i + fieldSize);

				bloks[i + fall_count * fieldSize].setBlokColor(bloks[i].getBlokColor());
				bloks[i + fall_count * fieldSize].setBonus_i(bloks[i].getBonus_i());
				bloks[i].setBonus_i(-1);
				bloks[i].setBlokColor(0);
				bloks[i + fall_count * fieldSize].setIsExist(1);
				bloks[i].setBlokColor(0);
				count++;
			}
		}
	}
}

bool Window::Destroy()
{
	bool destroy_flag = 0;

	for (int i = 0; i < fieldSize * fieldSize; i++)
	{
		if (bloks[i].getIsExist() == false)
		{
			destroy_flag = 1;
			bloks[i].setBlokColor(0);
			bloks[i].setIsExist(1);

			score++;
		}
	}

	return destroy_flag;
}

void Window::DrawBloks()
{
	int bonus_i;
	for (int i = 0; i < fieldSize * fieldSize; i++)
	{
		bonus_i = bloks[i].getBonus_i();
		if (bonus_i >= 0)
		{
			bonuses[bonus_i]->DrawBonus(bloks[i].getPosition(0), bloks[i].getPosition(1));
		}
		else
		{
			bloks[i].ResetBlokColor();
			bloks[i].DrawBlok();
		}
	}
}

void Window::CheckPlate(int x, int y)
{
	if (plateChooseCount == 0)
	{
		firstPlate_i = x / bloks[0].getSize(0) + y / bloks[0].getSize(1) * fieldSize;
		plateChooseCount = 1;
	}
	else if (plateChooseCount == 1)
	{
		secondPlate_i = x / bloks[0].getSize(0) + y / bloks[0].getSize(1) * fieldSize;
		plateChooseCount = 2;
	}

}

void Window::CheckSwap()
{
	if (plateChooseCount == 2)
	{
		if (IsNeighbour())
		{
			SwapPlates();

			Draw();
			Sleep(SLEEP);

			BonusCheck(bloks[firstPlate_i].getBonus_i(), firstPlate_i);
			BonusCheck(bloks[secondPlate_i].getBonus_i(), secondPlate_i);

			if (!CheckFildToDestroy())
			{
				SwapPlates();
				Sleep(SLEEP);
			}
			Draw();
		}
		plateChooseCount = 0;
	}
}

bool Window::IsNeighbour()
{
	bool xNeighbour = 0, yNeighbour = 0;

	if (((firstPlate_i / fieldSize + 1) == (secondPlate_i / fieldSize) || (firstPlate_i / fieldSize - 1) == (secondPlate_i / fieldSize))
		&& (firstPlate_i % fieldSize) == (secondPlate_i % fieldSize))
	{
		xNeighbour = 1;
	}

	if ((((firstPlate_i + 1) % fieldSize) == (secondPlate_i % fieldSize) || ((firstPlate_i - 1) % fieldSize) == (secondPlate_i % fieldSize))
		&& (firstPlate_i / fieldSize) == (secondPlate_i / fieldSize))
	{
		yNeighbour = 1;
	}

	return (xNeighbour || yNeighbour);
}

void Window::SwapPlates()
{
	int blokColor_buf;

	blokColor_buf = bloks[firstPlate_i].getBlokColor();
	bloks[firstPlate_i].setBlokColor(bloks[secondPlate_i].getBlokColor());
	bloks[secondPlate_i].setBlokColor(blokColor_buf);

	if (bloks[firstPlate_i].getBonus_i() >= 0 || bloks[secondPlate_i].getBonus_i() >= 0)
	{
		int bonus_i_buf;
		bonus_i_buf = bloks[firstPlate_i].getBonus_i();
		bloks[firstPlate_i].setBonus_i(bloks[secondPlate_i].getBonus_i());
		bloks[secondPlate_i].setBonus_i(bonus_i_buf);
	}
}

void Window::BonusCheck(int bonus_i, int i)
{
	if (bonus_i >= 0)
	{
		bonuses[bonus_i]->BonusInitialize(fieldSize, bloks, i);
		bloks[i].setBonus_i(-1);
		bloks[i].setBlokColor(Empty);
		delete bonuses[bonus_i];

		for (int j = 0; j < fieldSize * fieldSize; j++)
		{
			if (bloks[j].getBonus_i() > bonus_i)
			{
				bloks[j].setBonus_i(bloks[j].getBonus_i() - 1);
			}
		}
		bonuses.erase(bonuses.begin() + bonus_i);
	}
}