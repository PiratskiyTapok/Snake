#include "KeyHandler.hpp"
#include "Snake.hpp"
#include "Field.hpp"

void main()
{
	Snake snake;
	Field field;

	field.toRender();
	
	while (true)
	{
		KeyHandler::handler(&snake);
		snake.toMotion();
		Sleep(200);
	}
}
