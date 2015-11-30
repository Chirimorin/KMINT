#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"
#include "Cow.h"
#include "Rabbit.h"
#include "Pill.h"
#include "Weapon.h"

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

	std::vector<Waypoint*> occupiedWaypoints;
	
	auto cow = new Cow(graph->getRandomWaypoint(occupiedWaypoints));
	occupiedWaypoints.push_back(cow->getWaypoint());

	auto rabbit = new Rabbit(graph->getRandomWaypoint(occupiedWaypoints));
	occupiedWaypoints.push_back(rabbit->getWaypoint());

	auto  pill = new Pill(graph->getRandomWaypoint(occupiedWaypoints));
	occupiedWaypoints.push_back(pill->getWaypoint());

	auto weapon = new Weapon(graph->getRandomWaypoint(occupiedWaypoints));
	occupiedWaypoints.push_back(pill->getWaypoint());
	
	graph->setShortestPath(cow->getWaypoint(), rabbit->getWaypoint());

	application->AddRenderable(cow);
	application->AddRenderable(rabbit);

	application->AddRenderable(pill);
	application->AddRenderable(weapon);

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
					cow->Move(graph->getFirstWaypointShortestPath()); // Verplaats koe naar het eerste volgende waypoint op het korste pad
					if (cow->getWaypoint() == rabbit->getWaypoint()) {
						
						std::vector<Waypoint*> occupiedWaypoints;
						occupiedWaypoints.push_back(cow->getWaypoint());
						occupiedWaypoints.push_back(rabbit->getWaypoint());
						occupiedWaypoints.push_back(pill->getWaypoint());
						occupiedWaypoints.push_back(weapon->getWaypoint());
						
						rabbit->Move(graph->getRandomWaypoint(occupiedWaypoints)); // Verplaats haas naar een random waypoint
						graph->setShortestPath(cow->getWaypoint(), rabbit->getWaypoint()); // Bepaal opnieuw het korste pad tussen koe en haas
					}
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