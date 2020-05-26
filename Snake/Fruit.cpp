#include <windows.h>
#include <time.h>   
#include "Fruit.hpp"
#include "Field.hpp"

void Fruit::spawn()
{
	srand(time(NULL));
	// проверка на спавн на змейке
	// проверка на спавн в поле
	coordinates_.x = rand() % 10 + 1;
}
