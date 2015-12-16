#include "BaseState.h"
#include <SDL.h>

BaseState::BaseState(Uint8 r, Uint8 g, Uint8 b) : r_{r}, g_{g}, b_{b}
{
}

BaseState::~BaseState()
{
}

void BaseState::Move(Entity* obj, Graph* graph)
{
	
}

void BaseState::setColor(SDL_Texture* texture)
{
	SDL_SetTextureColorMod(texture, r_, g_, b_);
}