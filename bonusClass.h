#pragma once

#include "Header.h"
#include "physObjectClass.h"
#include "blokClass.h"

#include <array>

class Bonus : public PhysObject
{
public:
	Bonus() {};
	Bonus(int posx, int posy, int sizex, int sizey, int blok_i);
	virtual~Bonus() {};

	virtual void BonusInitialize(int fieldSize, std::array<Blok, FIELD_SIZE* FIELD_SIZE>& bloks, int pos) {};

	virtual void DrawBonus(int blokPosx, int blokPosy) {};
};

class Boomb : public Bonus
{
public:
	Boomb() {};
	Boomb(int posx, int posy, int sizex, int sizey, int blok_i) : Bonus(posx, posy, sizex, sizey, blok_i) {};
	~Boomb() {};

	void BonusInitialize(int fieldSize, std::array<Blok, FIELD_SIZE* FIELD_SIZE>& bloks, int pos) override;

	void DrawBonus(int blokPosx, int blokPosy) override;
};

class LineRacket : public Bonus
{
public:
	LineRacket() {};
	LineRacket(int posx, int posy, int sizex, int sizey, int blok_i) : Bonus(posx, posy, sizex, sizey, blok_i) {};
	~LineRacket() {};

	void BonusInitialize(int fieldSize, std::array<Blok, FIELD_SIZE* FIELD_SIZE>& bloks, int pos) override;

	void DrawBonus(int blokPosx, int blokPosy) override;
};

class ColumRacket : public Bonus
{
public:
	ColumRacket() {};
	ColumRacket(int posx, int posy, int sizex, int sizey, int blok_i) : Bonus(posx, posy, sizex, sizey, blok_i) {};
	~ColumRacket() {};

	void BonusInitialize(int fieldSize, std::array<Blok, FIELD_SIZE* FIELD_SIZE>& bloks, int pos) override;

	void DrawBonus(int blokPosx, int blokPosy) override;
};