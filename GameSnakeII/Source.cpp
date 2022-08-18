#include <iostream>
#include<conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int snakeX;
int snakeY;
int fruitX;
int fruitY;
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
	
	for (size_t i = 0; i <= width; i++)//цикл для верхней границы
	{
		cout << "#";
	}cout << endl;

	for (size_t i = 0; i <= width; i++)//цикл для боковых границ и движения змейки
	{
		for (size_t j = 0; j <= height; j++)
		{
			if (j == 0 || j == height)//прорисовка боковых границ
			{
				cout << "#";
			}
			else if (i == snakeX && j == snakeY)
			{
				cout << "o";
			}
			else if (i == fruitX && j == fruitY)
			{
				cout << "0";
			}
			else//заполнение всего остального пространства пробелами
			{
				cout << " ";
			}

		}cout << endl;
	}

	for (size_t i = 0; i <= width; i++)//цикл для нижней границы
	{
		cout << '#';
	}cout << endl;

	cout << "Top score: " << score << endl;
}

void input()//функция отслеживания нажатия клавишь указываем в функции какими клавишами будем управлять
{
	if (_kbhit())//функция отслживает нажатие на клавиатуру keyboard hit
	{
		switch (_getch())//функция отслеживает какую именно кнопку нажал пользователь
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void logic() //функция описывает логику самой игры
{
	switch (dir)//логика движения змейки при изменении dir
	{
	case LEFT:
		snakeX--;
		break;
	case RIGHT:
		snakeX++;
		break;
	case UP:
		snakeY--;
		break;
	case DOWN:
		snakeY++;
		break;
	}

	if (snakeX == fruitX && snakeY == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}

int main()
{
	setup();
	while (!gameOver)
	{
		draw();
		input();
		logic();
	}

	return 0;
}