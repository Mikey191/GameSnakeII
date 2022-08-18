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
void setup()//������� ������� ����� ���������� ������� ��������� ��������
{
	gameOver = false;
	dir = STOP;
	snakeX = width / 2;
	snakeY = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}

void draw()//������� ������� ������ ���� ������
{
	system("CLS");
	
	for (size_t i = 0; i <= width; i++)//���� ��� ������� �������
	{
		cout << "#";
	}cout << endl;

	for (size_t i = 0; i <= width; i++)//���� ��� ������� ������ � �������� ������
	{
		for (size_t j = 0; j <= height; j++)
		{
			if (j == 0 || j == height)//���������� ������� ������
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
			else//���������� ����� ���������� ������������ ���������
			{
				cout << " ";
			}

		}cout << endl;
	}

	for (size_t i = 0; i <= width; i++)//���� ��� ������ �������
	{
		cout << '#';
	}cout << endl;

	cout << "Top score: " << score << endl;
}

void input()//������� ������������ ������� ������� ��������� � ������� ������ ��������� ����� ���������
{
	if (_kbhit())//������� ���������� ������� �� ���������� keyboard hit
	{
		switch (_getch())//������� ����������� ����� ������ ������ ����� ������������
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

void logic() //������� ��������� ������ ����� ����
{
	switch (dir)//������ �������� ������ ��� ��������� dir
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