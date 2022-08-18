#include <iostream>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int snakeX = width / 2;
int snakeY = height / 2;
int fruitX = rand() % width;
int fruitY = rand() % height;
int score;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
void setup()//функция которая нашим параметрам предает начальные значения
{
	gameOver = false;
	dir = STOP;
	snakeX = width / 2;
	snakeY = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void draw()//функция которая рисует поле змейки
{
	system("CLS");
	
	for (size_t i = 0; i < width; i++)//цикл для верхней границы
	{
		cout << "#";
	}cout << endl;

	for (size_t i = 0; i <= width; i++)//цикл для боковых границ и движения змейки
	{
		for (size_t j = 0; j <= height; j++)
		{
			if (j == 0 || j == height)
			{
				cout << "#";
			}
			else
			{
				cout << " ";
			}
		}cout << endl;
	}

	for (size_t i = 0; i < width; i++)//цикл для нижней границы
	{
		cout << '#';
	}cout << endl;
}

void input();//функция отслеживания нажатия клавишь

void logic();//функция описывает логику самой игры

int main()
{
	setup();
	while (!gameOver)
	{
		draw();
		//input();
		//logic();
	}

	return 0;
}