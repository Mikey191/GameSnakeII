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
	
	for (size_t i = 0; i < width; i++)//���� ��� ������� �������
	{
		cout << "#";
	}cout << endl;

	for (size_t i = 0; i <= width; i++)//���� ��� ������� ������ � �������� ������
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

	for (size_t i = 0; i < width; i++)//���� ��� ������ �������
	{
		cout << '#';
	}cout << endl;
}

void input();//������� ������������ ������� �������

void logic();//������� ��������� ������ ����� ����

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