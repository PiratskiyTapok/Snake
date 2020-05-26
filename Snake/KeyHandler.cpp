#include <iostream>
#include <conio.h>
#include "KeyHandler.hpp"
#include "Snake.hpp"

void KeyHandler::handler(Snake* snake)
{
	if (_kbhit()) // ��������� ������� �� �����
	{
		switch (_getch()) // ��� ������� �� ����� ��� Enter ����� �����
		{
		case 72: //�����
			snake->setMotionVector(UP);
			break;
		case 80: //����
			snake->setMotionVector(DOWN);
			break;
		case 75: //����� 
			snake->setMotionVector(LEFT);
			break;
		case 77: //������
			snake->setMotionVector(RIGHT);
			break;
		default:
			break;
		}
	}
}
