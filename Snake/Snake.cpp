#include "Snake.hpp"
#include "GlobalStructures.h"
#include <iostream>
#include <windows.h>

void Snake::toRender()
{
	cPosition_ = { coordinates_[size_ - 1].x, coordinates_[size_ - 1].y };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << " ";

	cPosition_ = { coordinates_->x, coordinates_->y };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << "*";

	cPosition_ = { 0, 0 };
	SetConsoleCursorPosition(hConsole_, cPosition_);
}

void Snake::stateMachine(int state)
{
	if ((motionVector_ == LEFT && state != RIGHT) || (motionVector_ == RIGHT && state != LEFT))
	{
		motionVector_ = (short)state;
	}
	if ((motionVector_ == UP && state != DOWN) || (motionVector_ == DOWN && state != UP))
	{
		motionVector_ = (short)state;
	}
}

void Snake::toGrow()
{
	coordinates_ = (vect*)realloc(coordinates_, ++size_ * sizeof(vect));
	switch (motionVector_)
	{
	case LEFT:
		coordinates_[size_ - 1].x = coordinates_[size_ - 2].x + 1;
		break;
	case RIGHT:
		coordinates_[size_ - 1].x = coordinates_[size_ - 2].x - 1;
		break;
	case UP:
		coordinates_[size_ - 1].y = coordinates_[size_ - 2].y - 1;
		break;
	case DOWN:
		coordinates_[size_ - 1].y = coordinates_[size_ - 2].y + 1;
		break;
	default:
		break;
	}
}

bool Snake::gameOver()
{
	for(int i = size_ - 1; i > 3; i--)
	{
		if((coordinates_->x == coordinates_[i].x) && (coordinates_->y == coordinates_[i].y))
		{
			return true;
		}
	}
	return false;
}


bool Snake::toMotion(vect* fruitCoordinates, bool *gameFlag)
{
	toRender();
	for (int i = size_ - 1; i > 0; i--)
	{
		coordinates_[i].x = coordinates_[i - 1].x;
		coordinates_[i].y = coordinates_[i - 1].y;
	}
	switch (motionVector_)
	{
	case UP: //вверх
		if (coordinates_->y == fieldCoordinates_.y + 1)
		{
			coordinates_->y = fieldCoordinates_.y + fieldSize_.y - 1;
		}
		else
		{
			coordinates_->y--;
		}
		break;
	case DOWN: //вниз
		if (coordinates_->y == fieldCoordinates_.y + fieldSize_.y - 1)
		{
			coordinates_->y = fieldCoordinates_.y + 1;
		}
		else
		{
			coordinates_->y++;
		}
		break;
	case LEFT: //влево
		if (coordinates_->x == fieldCoordinates_.x + 1)
		{
			coordinates_->x = fieldCoordinates_.x + fieldSize_.x - 1;
		}
		else
		{
			coordinates_->x--;
		}
		break;
	case RIGHT: //вправо
		if (coordinates_->x == fieldCoordinates_.x + fieldSize_.x - 1)
		{
			coordinates_->x = fieldCoordinates_.x + 1;
		}
		else
		{
			coordinates_->x++;
		}
		break;
	default:
		break;
	}

	if(gameOver())
	{
		*gameFlag = false;
	}
	
	if((coordinates_->x == fruitCoordinates->x) && (coordinates_->y == fruitCoordinates->y))
	{
		toGrow();
		return true;
	}
	else
	{
		return false;
	}
}