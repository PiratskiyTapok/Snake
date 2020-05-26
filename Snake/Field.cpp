#include <windows.h>
#include <iostream>
#include "Field.hpp"

void Field::toRender()
{
	cPosition_ = { coordX, coordY };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)201; //верхний левый уголок

	cPosition_ = { coordX, coordY + ySize};
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)200; //нижний левый уголок
	
	cPosition_ = { coordX + xSize, coordY };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)187; //верхний правый уголок

	cPosition_ = { coordX + xSize, coordY + ySize};
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)188; //нижний правый уголок

	for(int i = 1; i < ySize; i++)
	{
		cPosition_ = { coordX, (short)(coordY + i) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)186; //левая стенка

		cPosition_ = { (short)(coordX + xSize), (short)(coordY + i) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)186; //правая стенка
	}

	for (int i = 1; i < xSize; i++)
	{
		cPosition_ = { (short)(coordX + i), (short)(coordY) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)205; //верхняя стенка

		cPosition_ = { (short)(coordX + i), (short)(coordY + ySize) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)205; //нижняя стенка
	}
}
