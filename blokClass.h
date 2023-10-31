#pragma once
#include "physObjectClass.h"
#include "bonusClass.h"

class Blok: public PhysObject, public Bonus
{
private:
	

public:

	Blok();

	Blok(int i, int fieldSize, int windSizex, int windSizey);

	void ResetBlokColor();

	void DrawBlok();


	void setType(int type);
	int getType();

	void setCondition(int condition);
	int getCondition();
};