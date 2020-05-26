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
	if((motionVector_ == LEFT && state != RIGHT) || (motionVector_ == RIGHT && state != LEFT))
	{
		motionVector_ = (short)state;
	}
	if ((motionVector_ == UP && state != DOWN) || (motionVector_ == DOWN && state != UP))
	{
		motionVector_ = (short)state;
	}
}


void Snake::toMotion()
{
	toRender();
	for (int i = size_ - 1; i > 0; i--)
	{
		coordinates_[i].x = coordinates_[i - 1].x;
		coordinates_[i].y = coordinates_[i - 1].y;
	}
	switch (motionVector_)
	{
	case UP: //�����
		if(coordinates_->y == fieldCoordinates_.y + 1)
		{
			coordinates_->y = fieldCoordinates_.y + fieldSize_.y - 1;
		}
		else
		{
			coordinates_->y--;
		}
		break;
	case DOWN: //����
		if (coordinates_->y == fieldCoordinates_.y + fieldSize_.y - 1)
		{
			coordinates_->y = fieldCoordinates_.y + 1;
		}
		else
		{
			coordinates_->y++;
		}
		break;
	case LEFT: //�����
		if (coordinates_->x == fieldCoordinates_.x + 1)
		{
			coordinates_->x = fieldCoordinates_.x + fieldSize_.x - 1;
		}
		else
		{
			coordinates_->x--;
		}
		break;
	case RIGHT: //������
		if (coordinates_->x == fieldCoordinates_.x + fieldSize_.x - 1)
		{
			coordinates_->x = fieldCoordinates_.x + 1;
		}
		else
		{
			coordinates_->x++;
		}
		break;
	case 27:  //esc
		break;
	default:
		break;
	}
}