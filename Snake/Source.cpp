#include "KeyHandler.hpp"
#include "Snake.hpp"
#include "Field.hpp"

void main()
{
	
	Field field;
	Snake snake(&field);

	field.toRender();
	
	while (true)
	{
		KeyHandler::handler(&snake);
		snake.toMotion();
		Sleep(200);
	}
}
