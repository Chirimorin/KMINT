#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"
#include "Cow.h"
#include "Rabbit.h"

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	auto application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	
	auto graph = new Graph();
	application->AddRenderable(new Cow());
	application->AddRenderable(new Rabbit());

	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
				case SDLK_RETURN:
					// VERPLAATS KOE EN EVENTUEEL HAAS
					break;
				default:
					break;
				}
			}
		}
		
		//application->SetColor(Color(0, 0, 0, 255));
		//application->DrawText("Welcome to KMint", 800 / 2, 600 / 2);

		graph->DrawGraph(application);
		
		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
	}
		
	return EXIT_SUCCESS;
}