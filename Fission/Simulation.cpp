#include "Simulation.h"

#include "Settings.h"

#include "MainMenuScreen.h"

Simulation::Simulation()
{
}

bool Simulation::Load()
{
	if(!Window.Create(Settings::WindowWidth, Settings::WindowHeight, "Nuclear Fission"))
	{
		return false;
	}
	Window.SetBackgroundColour(Colour());

	return true;
}

void Simulation::Run()
{
	Screens.push(new MainMenuScreen());
	if(!Screens.top()->Load(Window.GetRenderer()))
	{
		Print("Failed to load MenuScreen.");
		return;
	}

	while(Update())
	{
		Draw();
	}
}

bool Simulation::Update()
{
	SDL_Event Event;
	if(SDL_PollEvent(&Event))
	{
		if(Event.type==SDL_QUIT)
			return false;

		ScreenResult Result=Screens.top()->HandleEvents(Event, &Screens);
		if(Result==ScreenResult::Error)
		{
			Print("Error occurred updating screen.");
			return false;
		}
		else if(Result==ScreenResult::NewScreen)
		{
			if(!Screens.top()->Load(Window.GetRenderer()))
			{
				Print("Failed to load new screen.");
				return false;
			}
		}
		else if(Result==ScreenResult::RemoveScreen)
		{
			delete Screens.top();
			Screens.top()=NULL;
			Screens.pop();

			if(Screens.empty())
			{
				Print("No more screens. Game finished.");
				return false;
			}
		}
	}

	Screens.top()->Update();

	return true;
}
void Simulation::Draw()
{
	Window.BeginScene();

	Screens.top()->Draw(Window.GetRenderer());

	Window.EndScene();
}