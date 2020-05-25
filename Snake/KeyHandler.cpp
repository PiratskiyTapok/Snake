#include <iostream>
#include <conio.h>
#include "KeyHandler.hpp"
#include "Snake.hpp"

bool KeyHandler::handler(Snake* snake)
{
	if (_kbhit()) // ��������� ������� �� �����
	{
		switch (_getch()) // ��� ������� �� ����� ��� Enter ����� �����
		{
		case 72: //�����
			for (int i = 0; i < snake->getSize(); i++)
			{
				snake->getCoord()[i].y--;
			}
			return true;
		case 80: //����
			for (int i = 0; i < snake->getSize(); i++)
			{
				snake->getCoord()[i].y++;
			}
			return true;
		case 75: //����� 
			for (int i = 0; i < snake->getSize(); i++)
			{
				snake->getCoord()[i].x--;
			}
			return true;
		case 77: //������
			for (int i = 0; i < snake->getSize(); i++)
			{
				snake->getCoord()[i].x++;
			}
			return true;
		default:
			return true;
		}
	}
	return false;
}
