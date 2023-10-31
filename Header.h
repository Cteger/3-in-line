#pragma once
#define WINDOW_POSITIONX 200
#define WINDOW_POSITIONY 50
#define WINDOW_SIZEX 602
#define WINDOW_SIZEY 602
#define FIELD_SIZE 10
#define SLEEP 200

void SystemOpen(int argc, char** argv);
void SystemRelease();
void SystemInitialise();
void SystemUpdate();
void RenderScene();
void Draw();
void MouseButton(int button, int state, int x, int y);