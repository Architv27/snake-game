#include"snake game.h"

int main() {
	Snake snake;
	char op = 'l';
	do{
		if (_kbhit()) {
			op = _getch();
		}
		switch (op) {
			case 'w':
			case 'W':
				snake.turnUP();
				break;
			case 's':
			case 'S':
				snake.turnDW();
				break;
			case 'a':
			case 'A':
				snake.turnL();
				break;
			case 'd':
			case 'D':
				snake.turnR();
				break;
		}
		snake.Move();
	} while (op != 'e');
	system("pause");
	return 0;
}