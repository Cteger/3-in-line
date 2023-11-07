#pragma once
#include "physObjectClass.h"

class Blok : public PhysObject
{
protected:
	int blokColor;
	int bonus_i;
	bool isExist;

public:

	Blok() {};
	Blok(int blok_i, int fieldSize, int windSizex, int windSizey);

	void setBlokColor(int color_i);
	void ResetBlokColor();

	void DrawLine();
	void DrawBlok();

	void setBlokColor(enum BlokColor blokColor) { this->blokColor = blokColor; }
	int getBlokColor() { return blokColor; }

	void setIsExist(bool isExist) { this->isExist = isExist; }
	int getIsExist() { return isExist; }

	void setBonus_i(int bonus_i) { this->bonus_i = bonus_i; }
	int getBonus_i() { return bonus_i; }
};

enum BlokColor
{
	Empty = 0,
	Red = 1,
	Green = 2,
	Blue = 3,
	Yellow = 4,
	RB = 5,
	GB = 6,
	LGreen = 7,
	LRed = 8,
	Gray = 9,
	CBonus = 10
};