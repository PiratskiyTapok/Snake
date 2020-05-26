#include <windows.h>
#include <iostream>
#include "Field.hpp"

void Field::toRender()
{
	cPosition_ = { coordinates_.x, coordinates_.y };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)201; //������� ����� ������

	cPosition_ = { coordinates_.x, coordinates_.y + size_ .y};
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)200; //������ ����� ������
	
	cPosition_ = { coordinates_.x + size_.x, coordinates_.y };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)187; //������� ������ ������

	cPosition_ = { coordinates_.x + size_.x, coordinates_.y + size_.y };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << (char)188; //������ ������ ������

	for(int i = 1; i < size_.y; i++)
	{
		cPosition_ = { coordinates_.x, (short)(coordinates_.y + i) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)186; //����� ������

		cPosition_ = { (short)(coordinates_.x + size_.x), (short)(coordinates_.y + i) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)186; //������ ������
	}

	for (int i = 1; i < size_.x; i++)
	{
		cPosition_ = { (short)(coordinates_.x + i), (short)(coordinates_.y) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)205; //������� ������

		cPosition_ = { (short)(coordinates_.x + i), (short)(coordinates_.y + size_.y) };
		SetConsoleCursorPosition(hConsole_, cPosition_);
		std::cout << (char)205; //������ ������
	}

	cPosition_ = { (short)(coordinates_.x + size_.x / 2 - 4), (short)(coordinates_.y + size_.y + 2) };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << "Score:  " << score << std::endl;
	cPosition_ = { (short)(coordinates_.x + size_.x / 2 - 8), (short)(coordinates_.y + size_.y + 3) };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << "Press esc to exit";
}
void Field::toCount()
{
	score += 10;
	cPosition_ = { (short)(coordinates_.x + size_.x / 2 - 2), (short)(coordinates_.y + size_.y + 2) };
	SetConsoleCursorPosition(hConsole_, cPosition_);
	std::cout << "Score: " << score;
}
