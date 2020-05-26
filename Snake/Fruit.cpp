#include <windows.h>
#include <time.h>
#include "Fruit.hpp"
#include "Snake.hpp"
#include <iostream>

void Fruit::spawn(Snake* snake)
{
	srand(time(NULL));
	vect* snakeCoordinates = snake->getCoord();

	while(true)
	{
		coordinates_.x = rand() % (fieldSize_.x - 2) + fieldCoordinates_.x + 1;
		coordinates_.y = rand() % (fieldSize_.y - 2) + fieldCoordinates_.y + 1;
		
		for (int i = 0; i < snake->getSize(); i++)
		{
			if((snakeCoordinates[i].x != coordinates_.x) && (snakeCoordinates[i].y != coordinates_.y))
			{
				cPosition_ = { coordinates_.x, coordinates_.y };
				SetConsoleCursorPosition(hConsole_, cPosition_);
				std::cout << '&';
				return;
			}
		}
	}
}
