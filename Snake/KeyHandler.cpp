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
			snake->stateMachine(UP);
			break;
		case 80: //����
			snake->stateMachine(DOWN);
			break;
		case 75: //����� 
			snake->stateMachine(LEFT);
			break;
		case 77: //������
			snake->stateMachine(RIGHT);
			break;
		default:
			break;
		}
	}
}
