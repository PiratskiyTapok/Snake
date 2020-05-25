#include "KeyHandler.hpp"
#include "Snake.hpp"
#include "Renderer.hpp"

void main()
{
    Snake snake(1);
	
    while (true)
    {
        if(KeyHandler::handler(&snake))
        {
            Renderer::toRender(&snake);
        }
    }
}
