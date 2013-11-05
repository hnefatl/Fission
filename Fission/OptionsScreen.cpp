#include "OptionsScreen.h"

OptionsScreen::OptionsScreen()
{

}

bool OptionsScreen::Load(SDL_Renderer *const Renderer)
{
	return true;
}

ScreenResult OptionsScreen::HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens)
{
	return ScreenResult::Success;
}
void OptionsScreen::Update()
{

}
void OptionsScreen::Draw(SDL_Renderer *const Renderer)
{

}