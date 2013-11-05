#include "MainMenuScreen.h"

#include "SimulationScreen.h"
#include "OptionsScreen.h"

MainMenuScreen::MainMenuScreen()
{

}

bool MainMenuScreen::Load(SDL_Renderer *const Renderer)
{
	if(!Title.Load(Resources::Fonts::Arial, "Nuclear Fission Simulation", 30, Settings::SelectedColour, Renderer))
		return false;

	if(!Start.Load(Resources::Fonts::Arial, "Start", 20, Settings::UnselectedColour, Renderer))
		return false;
	
	if(!Options.Load(Resources::Fonts::Arial, "Options", 20, Settings::UnselectedColour, Renderer))
		return false;

	if(!Exit.Load(Resources::Fonts::Arial, "Exit", 20, Settings::UnselectedColour, Renderer))
		return false;

	Title.SetLocation(Point((Settings::WindowWidth/2)-(Title.GetLocation().w/2), 10));
	Start.SetLocation(Point((Settings::WindowWidth/2)-(Start.GetLocation().w/2), Title.GetLocation().y+Title.GetLocation().h+20));
	Options.SetLocation(Point((Settings::WindowWidth/2)-(Options.GetLocation().w/2), Start.GetLocation().y+Start.GetLocation().h+20));
	Exit.SetLocation(Point((Settings::WindowWidth/2)-(Exit.GetLocation().w/2), Options.GetLocation().y+Options.GetLocation().h+20));

	return true;
}

ScreenResult MainMenuScreen::HandleEvents(const SDL_Event &Event, std::stack<Screen *> *const Screens)
{
	if(!Title.HandleEvents(Event))
		return ScreenResult::Error;
	if(!Start.HandleEvents(Event))
		return ScreenResult::Error;
	if(!Options.HandleEvents(Event))
		return ScreenResult::Error;
	if(!Exit.HandleEvents(Event))
		return ScreenResult::Error;

	if(Start.IsClicked())
	{
		Screens->push(new SimulationScreen());
		return ScreenResult::NewScreen; // New screen added
	}
	if(Options.IsClicked())
	{
		Screens->push(new OptionsScreen());
		return ScreenResult::NewScreen; // New screen added
	}
	if(Exit.IsClicked())
	{
		return ScreenResult::RemoveScreen; // Force exit
	}

	return ScreenResult::Success;
}
void MainMenuScreen::Update()
{
	Title.Update();
	Start.Update();
	Options.Update();
	Exit.Update();
}
void MainMenuScreen::Draw(SDL_Renderer *const Renderer)
{
	Title.Draw(Renderer);
	Start.Draw(Renderer);
	Options.Draw(Renderer);
	Exit.Draw(Renderer);
}