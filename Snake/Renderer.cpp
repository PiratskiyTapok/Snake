#include "Renderer.hpp"
#include "Snake.hpp"
#include <windows.h>
#include <iostream>

void Renderer::toRender(Snake *snake)
{
	for(int i = 0; i < snake->getSize(); i++)
	{
		SetCursorPos(snake->getCoord()[i].x, snake->getCoord()[i].y);
		std::cout << "*" << std::endl;
	}
}
