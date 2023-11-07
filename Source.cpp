#include "Header.h"
#include "bonusClass.h"
#include "windowClass.h"

#include <glut.h>
#include <windows.h>
#include <iostream>

Window wind;

void SystemOpen(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
}

void SystemInitialise()
{
	wind = Window(FIELD_SIZE, WINDOW_SIZEX, WINDOW_SIZEY, WINDOW_POSITIONX, WINDOW_POSITIONY);
	wind.BloksInitialize();

	wind.StartFunc();
	wind.setScore(0);
	SystemUpdate();
}

void SystemUpdate()
{
	glutInitWindowPosition(wind.getPosition(0), wind.getPosition(1));
	glutInitWindowSize(wind.getSize(0), wind.getSize(1));
	glutCreateWindow("3line Game");

	gluOrtho2D(0, wind.getSize(0), wind.getSize(1), 0);
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
	wind.CheckSwap();

	wind.CheckFildToFill();
	Sleep(SLEEP);
	Draw();

	wind.CheckFildToDestroy();
	Sleep(SLEEP);
	Draw();

	std::cout << wind.getScore() << std::endl;
}

void Draw()
{
	// очистка буфера цвета и глубины
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glClearColor(1.0, 1.0, 1.0, 1.0);

	//BLOKS
	wind.DrawBloks();

	glutSwapBuffers();
}

void MouseButton(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN))
	{
		wind.CheckPlate(x, y);
		glutPostRedisplay();
	}
}