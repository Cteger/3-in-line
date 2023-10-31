#pragma once

#include "Header.h"
#include "physObjectClass.h"

class Bonus
{
private:
	int type;
	int condition;

public:

	void BoombInitialise();

	void BonusCheck(int condition, int fieldSize, int i);

	struct Blok* BoombBoom(struct Blok* bloks, int fieldSize, int pos);

	void BoombDraw(struct Blok blok);

	struct Blok RacketLineInitialise(struct Blok blok0);

	struct Blok* RacketLineLaunch(struct Blok* bloks, int fieldSize, int pos);

	void RacketLineDraw(struct Blok blok);

	struct Blok RacketColumInitialise(struct Blok blok0);

	struct Blok* RacketColumLaunch(struct Blok* bloks, int fieldSize, int pos);

	void RacketColumDraw(struct Blok blok);

};