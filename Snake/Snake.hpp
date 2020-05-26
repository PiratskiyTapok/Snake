#pragma once
#include <windows.h>
#include <iostream>

typedef struct coord
{
	short x;
	short y;
}coord;

enum vect
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
	coord *coordinates_;
	HANDLE hConsole_; 
	COORD cPosition_; 

	void toRender();
public:
	Snake()
	{
		size_ = 4;
		hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);
		motionVector_ = RIGHT;
		coordinates_ = new coord[size_];

		for(int i = 0; i < size_; i++)
		{
			coordinates_[i].x = (short)(size_ - (i + 1) + 40);
			coordinates_[i].y = 4;
		}
				
		cPosition_ = { coordinates_->x, coordinates_->y };
	}

	void stateMachine(int state);
	void toMotion();

	coord* getCoord()
	{
		return coordinates_;
	}

	void setCoord(coord *coordinates)
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