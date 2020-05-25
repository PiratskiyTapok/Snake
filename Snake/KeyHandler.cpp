#include <iostream>
#include <conio.h>
#include "KeyHandler.hpp"
#include "Snake.hpp"

bool KeyHandler::handler(Snake* snake)
{
	if (_kbhit()) // слушатель нажатия на клаву
	{
		switch (_getch()) // ждёт нажатия на клаву без Enter после этого
		{
		case 72: //вверх
			for (int i = 0; i < snake->getSize(); i++)
			{
				snake->getCoord()[i].y--;
			}
			return true;
		case 80: //вниз
			for (int i = 0; i < snake->getSize(); i++)
			{
				snake->getCoord()[i].y++;
			}
			return true;
		case 75: //влево 
			for (int i = 0; i < snake->getSize(); i++)
			{
				snake->getCoord()[i].x--;
			}
			return true;
		case 77: //вправо
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
