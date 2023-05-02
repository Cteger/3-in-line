#pragma once

#include "Header.h"

struct Blok BoombInitialise(struct Blok blok0);

struct Window BonusCheck(struct Window wind0, int i, int j);

struct Window BoombBoom(struct Window wind0, int ipos, int jpos);

void BoombDraw(struct Blok blok);

struct Blok RacketLineInitialise(struct Blok blok0);

struct Window RacketLineLaunch(struct Window wind0, int ipos, int jpos);

void RacketLineDraw(struct Blok blok);

struct Blok RacketColumInitialise(struct Blok blok0);

struct Window RacketColumLaunch(struct Window wind0, int ipos, int jpos);

void RacketColumDraw(struct Blok blok);
