#pragma once
#define WINDOW_POSITIONX 200
#define WINDOW_POSITIONY 50
#define WINDOW_SIZEX 602
#define WINDOW_SIZEY 602
#define FIELD_SIZE 10
#define SLEEP 200

struct Color
{
	float red, green, blue;
};

struct Position
{
	int x;
	int y;
};

struct Size
{
	int height;
	int width;
};

struct Blok
{
	struct Position position;
	struct Size size;

	int type;
	int condition;
};

struct Window
{
	struct Size size;
	struct Position position;
	struct Color color;
	struct Blok bloks[FIELD_SIZE][FIELD_SIZE];
	struct Bonus* bonus;
	struct Position first_plate, second_plate;

	int plate_flag;
	int destroy_flag;
	int destroy_start_flag;
	int destroy_count;
	int bonus_count;
	int glutNum;
	int menu_size;
	int field_size;
	int score;
};


void SystemOpen(int argc, char** argv);

void SystemRelease();

void SystemInitialise();

void SystemUpdate();

void RenderScene();

void Draw();

void MouseButton(int button, int state, int x, int y);

struct Window StartFunc(struct Window wind0);