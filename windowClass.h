#pragma once
#include "physObjectClass.h"
#include "blokClass.h"
#include "bonusClass.h"

#include <vector>
#include <array>

class Window : public PhysObject
{
private:
	std::array<Blok, FIELD_SIZE* FIELD_SIZE> bloks;
	std::vector<Bonus*> bonuses;

	int firstPlate_i, secondPlate_i;

	int plateChooseCount;
	bool startFlag;
	int fieldSize;
	int score;

public:

	Window() {};
	Window(int fieldSize, int windSizex, int windSizey, int windPosx, int windPosy);

	void StartFunc();
	void BloksInitialize();

	bool CheckFildToDestroy();
	int LineCheck(int blok_i);
	int ColumCheck(int blok_i);

	void CheckFildToFill();
	bool Destroy();

	void DrawBloks();

	void CheckPlate(int x, int y);
	void CheckSwap();
	bool IsNeighbour();
	void SwapPlates();

	void BonusCheck(int bonus_i, int i);

	void setScore(int score) { this->score = score; }
	int getScore() { return score; }

	int getFieldSize() { return fieldSize; }
};