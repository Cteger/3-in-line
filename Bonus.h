#pragma once

#include "Header.h"

struct Blok BoombInitialise(struct Blok blok0);

struct Blok* BonusCheck(struct Blok* bloks, int field_size, int i);

struct Blok* BoombBoom(struct Blok* bloks, int field_size, int pos);

void BoombDraw(struct Blok blok);

struct Blok RacketLineInitialise(struct Blok blok0);

struct Blok* RacketLineLaunch(struct Blok* bloks, int field_size, int pos);

void RacketLineDraw(struct Blok blok);

struct Blok RacketColumInitialise(struct Blok blok0);

struct Blok* RacketColumLaunch(struct Blok* bloks, int field_size, int pos);

void RacketColumDraw(struct Blok blok);
