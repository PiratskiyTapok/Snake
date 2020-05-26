#include <iostream>
#include <conio.h>
#include "KeyHandler.hpp"
#include "Snake.hpp"

void KeyHandler::handler(Snake* snake)
{
	if (_kbhit()) // слушатель нажатия на клаву
	{
		switch (_getch()) // ждёт нажатия на клаву без Enter после этого
		{
		case 72: //вверх
			snake->stateMachine(UP);
			break;
		case 80: //вниз
			snake->stateMachine(DOWN);
			break;
		case 75: //влево 
			snake->stateMachine(LEFT);
			break;
		case 77: //вправо
			snake->stateMachine(RIGHT);
			break;
		default:
			break;
		}
	}
}
