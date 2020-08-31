#pragma once
#include<iostream>
#include<Windows.h>
#include<dos.h>
#include<time.h>
#include<conio.h>
using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

constexpr auto msize=100;

void gotoxy(int x, int y) {
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
class Point {
private:
	int x;
	int y;
public:
	Point() {
		x = 10;
		y = 10;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;

	}
	bool operator==(Point* p) {
		if (this->x == p->x || this->y==p->y) {
			return true;
		}
		return false;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void setPoint(int x, int y) {
		this->x = x;
		this->y = y;
	}
	void Up() {
		y--;
	}
	void Down() {
		y++;
	}
	void Right() {
		x++;
	}
	void Left() {
		x--;
	}
	void Draw() {
		gotoxy(x, y);
		cout << "*";
	}
	void Erase() {
		gotoxy(x, y);
		cout << " ";
	}
	void CopyPos(Point* p) {
		p->x = x;
		p->y = y;
	}
	void print() {
		cout << "(" << x << "," << y << ")";
	}


};

class Snake {
private:
	
	int size; // size of snake
	char dir;
	Point fruit;
public:
	Point* cell[msize];
	Snake() {

		size = 1;
		cell[0] = new Point(20, 20);
		for (int i = 1; i < msize; i++) {
			cell[i] = NULL;
		}
		srand(time(NULL));
		fruit.setPoint(rand()%50 , rand() % 25);
	}

	void AddCell(int x, int y) {
		cell[size++] = new Point(x, y);
	}
	void turnUP() {
		dir = 'w';
	}
	void turnDW() {
		dir = 's';
	}
	void turnL() {
		dir = 'a';
	}
	void turnR() {
		dir = 'd';
	}
	void Move() {
		system("cls");
		for (int i = size - 1; i > 0; i--) {
			cell[i-1]->CopyPos(cell[i]);
		}
		switch (dir) {
		case 'w':
			cell[0]->Up();
			break;
		case 's':
			cell[0]->Down();
			break;
		case 'a':
			cell[0]->Left();
			break;
		case 'd':
			cell[0]->Right();
			break;
		}
		if (fruit.getX() == cell[0]->getX() && fruit.getY() == cell[0]->getY()){
			AddCell(0, 0);
			fruit.setPoint(rand() % 50, rand() % 25);
		}

		for (int i = 0; i < size; i++) {
			cell[i]->Draw();
		}

		fruit.Draw();
		Sleep(100);
	}
	void Print() {
		for (int i = 0; i < size; i++) {
			cell[i]->print();
		}
	}
	int getSize() {
		return size;
	}
};