#include "tool.h"

int main() {
    SetConsoleTitle(TEXT("이상윤 테트리스 개못함"));

    //system("mode con:cols=50 lines=20");
    //for (int i = 0; i < 50; i++) {
    //    printf("*");
    //}
    //for (int i = 0; i < 19; i++) {
    //    printf("\n*");
    //}
    //실제 이 정도 크기로 만들어짐

    setWindowSize(50, 30);
    gotoxy(20, 10);
    textColor(getColorBit(1, 1, 1, 1, 1) | getColorBit(0, 0, 0, 0, 0));
    printf("이상윤 테트리스 실력");
    Sleep(1000);
    clear();
    Sleep(1000);
    return 0;
}
