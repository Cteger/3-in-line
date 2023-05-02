#pragma once

#include "Header.h"

struct Blok* BloksInitialise(struct Window wind0);

void DrawBloks(struct Blok bloks[FIELD_SIZE], int field_size);

struct Window SwapPlates(struct Window wind0, int first_plate, int second_plate);

struct Window CheckFildToDestroy(struct Window wind0);

struct Window Destroy(struct Window wind0);

struct Window CheckFildToFill(struct Window wind0);