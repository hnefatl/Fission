#include "SimulationScreen.h"

SimulationScreen::SimulationScreen()
{

}

bool SimulationScreen::Load(SDL_Renderer *const Renderer)
{
	return true;
}

ScreenResult SimulationScreen::HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens)
{
	return ScreenResult::Success;
}
void SimulationScreen::Update()
{

}
void SimulationScreen::Draw(SDL_Renderer *const Renderer)
{

}