#include "tool.h"

extern int COLS = 50;
extern int LOWS = 20;

void setWindowSize(int cols, int lows) {
	char buffer[128];

	COLS = cols;
	LOWS = lows;

	sprintf(buffer, "mode con:cols=%d lines=%d", cols, lows);

	system(buffer);
}

void gotoxy(int x, int y) {
	// ������ ���α׷��� �⺻ ��� ��ġ (console�� �ڵ��� ������ �� ��)
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };

	// Ŀ�� ��ġ �ٲٱ�
	SetConsoleCursorPosition(hOut, pos);
}

void clear() {
	unsigned long dw;
	COORD pos = { 0, 0 };

	FillConsoleOutputCharacter(
		GetStdHandle(STD_OUTPUT_HANDLE), ' ', COLS * LOWS, pos, &dw
	);
	FillConsoleOutputAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE), getColorBit(0, 1, 1, 1, 1), COLS * LOWS, pos, &dw
	);
	gotoxy(0, 0);
	textColor(getColorBit(0, 1, 1, 1, 1));
}

void textColor(int colorCode) {
	SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		colorCode
		// �� �� ��Ʈ�� ������� ����, �۾��� ��Ʈ��
	);
}

int getColorBit(int background, int bright, int red, int green, int blue) {
	return (
		bright << 3 |
		red << 2 |
		green << 1 |
		blue
	) << background * 4;
}
