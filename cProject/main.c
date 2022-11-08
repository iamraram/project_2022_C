#include "tool.h"

int processInput();
void update();

int input = 0;
int frameCount;
int n;

int main() {
	setWindowSize(50, 20);
	int exit;
	int startTimer = clock();
	int frameRate = 1000 / 10;

	while (1) {
		startTimer = clock();
		exit = processInput();
		update();
		if (exit == 1) {
			break;
		}
		int tmp = startTimer + frameCount - clock();
		if (tmp > 0) {
			Sleep(tmp);
		}
	}
}	

int processInput() {
	if (kbhit()) {
		char c = getch();
		if (c == 'a') {
			input--;
		}
		if (c == 'd') {
			input++;
		}
		if (c == ' ') {
			return 1; 
		}
	}
	return 0;
}

void update() {
	frameCount++;

	if (frameCount > n || input != 0) {
		n += input;
		input = 0;
		frameCount = 0;
		if (n < 2) {
			n = 2;
		}
		else if (n > 20) {
			n = 20;
		}
		clear();
		return;
	}

	int x = n - frameCount;
	int y = frameCount - 1;
	gotoxy(x, y);
	for (int i = 0; i < 2 * frameCount - 1; i++) {
		printf("*");
	}
}