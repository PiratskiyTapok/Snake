#include "KeyHandler.hpp"
#include "Snake.hpp"
#include "Field.hpp"
#include "Fruit.hpp"
#include <conio.h>

int main()
{
	bool gameFlag = true;
	Field field;
	Snake snake(&field);
	Fruit fruit(&field);

	field.toRender();
	fruit.spawn(&snake);
	
	while (gameFlag)
	{
		if(KeyHandler::handler(&snake))
		{
			return 0;
		}
		if(snake.toMotion(fruit.getCoordinates(), &gameFlag))
		{
			field.toCount();
			fruit.spawn(&snake);
		}
		Sleep(150);
	}
	system("cls");
	std::cout << "You lose... Press any key";
	_getch();
	return 0;
}
