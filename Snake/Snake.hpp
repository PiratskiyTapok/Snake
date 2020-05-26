#pragma once
#include <windows.h>
#include <iostream>
#include "GlobalStructures.h"
#include "Field.hpp"

enum direction
{
	RIGHT,
	LEFT,
	UP,
	DOWN
};

class Snake
{
private:
	short size_;
	short motionVector_;
	vect fieldCoordinates_;
	vect fieldSize_;
	vect* coordinates_;
	HANDLE hConsole_;
	COORD cPosition_;

	bool gameOver();
	void toGrow();
	void toRender();
public:
	Snake(Field* field)
	{
		size_ = 4;
		hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);
		motionVector_ = RIGHT;
		coordinates_ = new vect[size_];
		fieldCoordinates_ = *(field->getCoordinates());
		fieldSize_ = *(field->getSize());

		for (int i = size_ - 1; i >= 0; i--)
		{
			coordinates_[i].x = (short)((size_ - 1) - i + fieldCoordinates_.x + 1);
			coordinates_[i].y = fieldCoordinates_.y + 1;
		}
	}

	void stateMachine(int state);
	bool toMotion(vect* fruitCoordinates, bool *gameFlag);

	vect* getCoord()
	{
		return coordinates_;
	}

	void setCoord(vect* coordinates)
	{
		this->coordinates_ = coordinates;
	}

	void setMotionVector(short motionVector)
	{
		motionVector_ = motionVector;
	}

	int getSize()
	{
		return size_;
	}
};