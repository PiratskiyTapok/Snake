#pragma once
class Field
{
private:
	short coordX;
	short coordY;
	short xSize;
	short ySize;
	HANDLE hConsole_;
	COORD cPosition_;

public:
	Field()
	{
		hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);
		coordX = 39;
		xSize = 42;
		coordY = 3;
		ySize = 18;
	}
	
	void toRender();
};