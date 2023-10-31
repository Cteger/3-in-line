#pragma once
#include "physObjectClass.h"
#include "blokClass.h"
#include "bonusClass.h"

#include <vector>

class Window: public PhysObject
{
private:
	std::vector<Bonus*> bonus;
	std::vector<Blok*> bloks;

	int first_plate, second_plate;

	int plate_flag;
	int destroy_flag;
	int destroy_start_flag;
	int destroy_count;
	int bonus_count;
	int menu_size;
	int fieldSize;
	int score;

public:

	//Window();
	Window();

	void StartFunc();

	void CheckFildToDestroy();

	void CheckFildToFill();

	void Destroy();

	void DrawBloks();

	void CheckPlate(int x, int y);

	void CheckSwap();

	void SwapPlates();

	int getScore();

	int getFieldSize();

};
