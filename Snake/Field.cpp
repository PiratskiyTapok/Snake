#include <windows.h>
#include <iostream>
#include "Field.hpp"

void Field::toRender()
{
	cPosition_ = { coordX, coordY };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)201; //������� ����� ������

	cPosition_ = { coordX, coordY + ySize};
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)200; //������ ����� ������
	
	cPosition_ = { coordX + xSize, coordY };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)187; //������� ������ ������

	cPosition_ = { coordX + xSize, coordY + ySize};
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)188; //������ ������ ������

	for(int i = 1; i < ySize; i++)
	{
		cPosition_ = { coordX, (short)(coordY + i) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)186; //����� ������

		cPosition_ = { (short)(coordX + xSize), (short)(coordY + i) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)186; //������ ������
	}

	for (int i = 1; i < xSize; i++)
	{
		cPosition_ = { (short)(coordX + i), (short)(coordY) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)205; //������� ������

		cPosition_ = { (short)(coordX + i), (short)(coordY + ySize) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)205; //������ ������
	}
}
