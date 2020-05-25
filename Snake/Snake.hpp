#pragma once
typedef struct coord
{
	int x;
	int y;
}coord;

class Snake
{
private:
	int size;
	coord *coordinates;
public:
	Snake(int size)
	{
		coordinates = new coord();
		coordinates->x = 0;
		coordinates->y = 0;
		this->size = size;
	}

	coord* getCoord()
	{
		return coordinates;
	}

	void setCoord(coord *coordinates)
	{
		this->coordinates = coordinates;
	}

	int getSize()
	{
		return size;
	}
};