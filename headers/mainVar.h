#ifndef MAINVAR_H
#define MAINVAR_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

extern SDL_Renderer *renderer;
extern SDL_Window *window;
extern const int N;
extern int arr[];
extern const int delay;
extern bool isSorted;
extern SDL_Texture* tex;
extern SDL_Rect mouse;

void renderArray(int key=-1, int swapped=-1, int pivot=-1);
#endif