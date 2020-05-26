#pragma once
#include "GlobalStructures.h"
#include "Field.hpp"
#include "Snake.hpp"

class Fruit
{
private:
	vect fieldCoordinates_;
	vect fieldSize_;
	vect coordinates_;
	HANDLE hConsole_;
	COORD cPosition_;


public:
	Fruit(Field* field)
	{
		hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);
		fieldCoordinates_ = *(field->getCoordinates());
		fieldSize_ = *(field->getSize());
	}

	void spawn(Snake* snake);

	vect* getCoordinates()
	{
		return &coordinates_;
	}
};