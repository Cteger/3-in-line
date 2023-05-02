#include "Header.h"
#include "Bloks.h"
#include "Bonus.h"

#include <glut.h>
#include <windows.h>
#include <iostream>

struct Window wind;

void SystemOpen(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
}

void SystemInitialise()
{
	wind.size.width = WINDOW_SIZEX + 1;
	wind.size.height = WINDOW_SIZEY + 1;
	wind.position.x = WINDOW_POSITIONX;
	wind.position.y = WINDOW_POSITIONY;

	wind.field_size = FIELD_SIZE;
	
	wind.destroy_flag = 0;
	wind.destroy_start_flag = 0;

	wind.bloks = BloksInitialise(wind);

	wind = StartFunc(wind);

	wind.destroy_flag = 0;

	SystemUpdate();
}

void SystemUpdate()
{
	glutInitWindowPosition(wind.position.x, wind.position.y);
	glutInitWindowSize(wind.size.width, wind.size.height);
	wind.glutNum = glutCreateWindow("LSD Game");

	gluOrtho2D(0, wind.size.width, wind.size.height, 0);
	glClearColor(1.0, 1.0, 1.0, 1.0);

	glutMouseFunc(MouseButton);

	glutDisplayFunc(RenderScene);
	glutIdleFunc(RenderScene);

	glutMainLoop();
}

void SystemRelease()
{
	exit(1);
}

void RenderScene()
{
	if (wind.plate_flag == 2)
	{
		if (((((wind.first_plate + wind.field_size) / wind.field_size) == (wind.second_plate / wind.field_size)
			|| ((wind.first_plate - wind.field_size) / wind.field_size) == (wind.second_plate / wind.field_size))
			&& (wind.first_plate % wind.field_size) == (wind.second_plate % wind.field_size))
			|| ((((wind.first_plate + 1) % wind.field_size) == (wind.second_plate % wind.field_size)
			|| ((wind.first_plate - 1) % wind.field_size) == (wind.second_plate % wind.field_size))
			&& (wind.first_plate / wind.field_size) == (wind.second_plate / wind.field_size)))
		{
			wind = SwapPlates(wind, wind.first_plate, wind.second_plate);

			Draw();
			Sleep(SLEEP);

			wind.bloks = BonusCheck(wind.bloks, wind.field_size, wind.first_plate);
			wind.bloks = BonusCheck(wind.bloks, wind.field_size, wind.second_plate);

			wind = CheckFildToDestroy(wind);
			Draw();

			if (wind.destroy_flag == 0)
			{
				wind = SwapPlates(wind, wind.second_plate, wind.first_plate);
				Draw();
			}
			else
			{
				wind.destroy_flag = 0;
			}
		}
		wind.plate_flag = 0;
	}

	wind = CheckFildToFill(wind);
	Sleep(SLEEP);
	Draw();

	wind = CheckFildToDestroy(wind);
	Sleep(SLEEP);
	Draw();

	std::cout << wind.score << std::endl;
}

void Draw()
{
	// очистка буфера цвета и глубины
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(1.0, 1.0, 1.0, 1.0);

	//BLOKS
	DrawBloks(wind.bloks, wind.field_size);

	glutSwapBuffers();
}

void MouseButton(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		if (wind.plate_flag == 0)
		{
			wind.first_plate = x / wind.bloks[0].size.width
				+ y / wind.bloks[0].size.height * wind.field_size;
			wind.plate_flag = 1;
		}
		else if (wind.plate_flag == 1)
		{
			wind.second_plate = x / wind.bloks[0].size.width
				+ y / wind.bloks[0].size.height * wind.field_size;
			wind.plate_flag = 2;
		}
		glutPostRedisplay();
	}
}

struct Window StartFunc(struct Window wind0)
{
	struct Window wind = wind0;

	wind.destroy_count = 1;

	wind = CheckFildToFill(wind);

	while (wind.destroy_count != 0)
	{
		wind = CheckFildToDestroy(wind);

		wind = CheckFildToFill(wind);
	}

	wind.destroy_start_flag = 1;

	return wind;
}