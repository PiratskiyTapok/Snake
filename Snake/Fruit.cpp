#include <windows.h>
#include <time.h>   
#include "Fruit.hpp"
#include "Field.hpp"

void Fruit::spawn()
{
	srand(time(NULL));
	// �������� �� ����� �� ������
	// �������� �� ����� � ����
	coordinates_.x = rand() % 10 + 1;
}
