#include "KeyHandler.hpp"
#include "Snake.hpp"
#include "Field.hpp"
#include "Fruit.hpp"

void main()
{
	
	Field field;
	Snake snake(&field);
	Fruit fruit(&field);

	field.toRender();
	fruit.spawn(&snake);
	
	while (true)
	{
		KeyHandler::handler(&snake);
		if(snake.toMotion(fruit.getCoordinates()))
		{
			fruit.spawn(&snake);
		}
		Sleep(200);
	}
}
