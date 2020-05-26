#include "KeyHandler.hpp"
#include "Snake.hpp"

void main()
{
	Snake snake;

	while (true)
	{
		KeyHandler::handler(&snake);
		snake.toMotion();
		Sleep(200);
	}
}
