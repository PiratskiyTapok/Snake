#pragma once
#include "GlobalStructures.h"

class Field
{
private:
	vect coordinates_;
	vect size_;
	HANDLE hConsole_;
	COORD cPosition_;

public:
	Field()
	{
		hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);
		coordinates_ = {39, 3};
		size_ = { 42, 18 };
	}
	
	void toRender();
	vect* getCoordinates()
	{
		return &coordinates_;
	}
	vect* getSize()
	{
		return &size_;
	}
};