#pragma once
#include "GlobalStructures.h"

class Fruit
{
private:
	vect coordinates_;
	
	void spawn();
public:
	vect *getCoordinates()
	{
		return &coordinates_;
	}
};