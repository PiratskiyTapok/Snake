#include "Snake.hpp"
#include <iostream>
#include <windows.h>

void Snake::toRender()
{
	cPosition_ = { coordinates_[size_ - 1].x, coordinates_[size_ - 1].y };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << " " << std::endl;
	
	cPosition_ = { coordinates_->x, coordinates_->y };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << "*" << std::endl;

	cPosition_ = { 0, 0 };
	SetConsoleCursorPosition(hConsole_, cPosition_);
}

void Snake::toMotion()
{
	toRender();
	switch (motionVector_)
	{
	case UP: //вверх
		for (int i = size_ - 1; i > 0; i--)
		{
			coordinates_[i].x = coordinates_[i - 1].x;
			coordinates_[i].y = coordinates_[i - 1].y;
		}
		coordinates_->y--;
		break;
	case DOWN: //вниз
		for (int i = size_ - 1; i > 0; i--)
		{
			coordinates_[i].x = coordinates_[i - 1].x;
			coordinates_[i].y = coordinates_[i - 1].y;
		}
		coordinates_->y++;
		break;
	case LEFT: //влево 
		for (int i = size_ - 1; i > 0; i--)
		{
			coordinates_[i].x = coordinates_[i - 1].x;
			coordinates_[i].y = coordinates_[i - 1].y;
		}
		coordinates_->x--;
		break;
	case RIGHT: //вправо
		for (int i = size_ - 1; i > 0; i--)
		{
			coordinates_[i].x = coordinates_[i - 1].x;
			coordinates_[i].y = coordinates_[i - 1].y;
		}
		coordinates_->x++;
		break;
	default:
		break;
	}
}