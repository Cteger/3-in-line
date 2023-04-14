#pragma once

#include "Header.h"

struct Window BloksInitialise(struct Window wind0);

void DrawBloks(struct Window wind);

struct Window SwapPlates(struct Window wind0, struct Position first_plate, struct Position second_plate);

struct Window CheckFildToDestroy(struct Window wind0);

struct Window Destroy(struct Window wind0);

struct Window CheckFildToFill(struct Window wind0);