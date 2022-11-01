#pragma warning(disable:4996)

#include <Windows.h>
#include <stdio.h>

extern int COLS;
extern int LOWS;

void setWindowSize(int cols, int lows);
void gotoxy(int x, int y);
void clear();

void textColor(int colorCode);

int getColorBit(int background, int bright, int red, int green, int blue);