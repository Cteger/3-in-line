#pragma once

#include "Header.h"

struct Window BonusInitialise(struct Window wind0);

struct Window BoombInitialise(struct Window wind0, int i, int j);

struct Window BonusCheck(struct Window wind0, int i, int j);

struct Window BoombBoom(struct Window wind0, int ipos, int jpos);

void BoombDraw(struct Window wind, int i, int j);

struct Window RacketLineInitialise(struct Window wind0, int i, int j);

struct Window RacketLineLaunch(struct Window wind0, int ipos, int jpos);

void RacketLineDraw(struct Window wind, int i, int j);

struct Window RacketColumInitialise(struct Window wind0, int i, int j);

struct Window RacketColumLaunch(struct Window wind0, int ipos, int jpos);

void RacketColumDraw(struct Window wind, int i, int j);
