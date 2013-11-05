#include "Button.h"

Button::Button()
{
	Selected=false;
}

bool Button::HandleEvents(const SDL_Event &Event)
{
	if(Event.type==SDL_EventType::SDL_MOUSEBUTTONDOWN)
	{
		if(Event.button.button==SDL_BUTTON_LEFT)
		{
			if(Contains(Point(Event.button.x, Event.button.y)))
			{
				OnClick();
				Clicked=true;
			}
		}
	}
	else if(Event.type==SDL_EventType::SDL_MOUSEMOTION)
	{
		if(Contains(Point(Event.motion.x, Event.motion.y)))
		{
			Selected=true;
		}
		else
		{
			Selected=false;
		}
	}

	return true;
}
void Button::Update()
{
	Clicked=false;
	if(Selected)
	{
		// Transition to SelectedColour
		if(CurrentColour.r<Settings::SelectedColour.r)
		{
			int New=CurrentColour.r+(Settings::SelectedColour.r-Settings::UnselectedColour.r)/FramesToUpdate;
			if(New<0)
				New=0;
			else if(New>255)
				New=255;
			CurrentColour.r=New;
		}
		else if(CurrentColour.g<Settings::SelectedColour.g)
		{
			int New=CurrentColour.g+(Settings::SelectedColour.g-Settings::UnselectedColour.g)/FramesToUpdate;
			if(New<0)
				New=0;
			else if(New>255)
				New=255;
			CurrentColour.g=New;
		}
		else if(CurrentColour.b<Settings::SelectedColour.b)
		{
			int New=CurrentColour.b+(Settings::SelectedColour.b-Settings::UnselectedColour.b)/FramesToUpdate;
			if(New<0)
				New=0;
			else if(New>255)
				New=255;
			CurrentColour.b=New;
		}
	}
	else
	{
		// Transition to UnselectedColour
		if(CurrentColour.r<Settings::SelectedColour.r)
		{
			int New=CurrentColour.r+(Settings::UnselectedColour.r-Settings::SelectedColour.r)/FramesToUpdate;
			if(New<0)
				New=0;
			else if(New>255)
				New=255;
			CurrentColour.r=New;
		}
		else if(CurrentColour.g<Settings::SelectedColour.g)
		{
			int New=CurrentColour.g+(Settings::UnselectedColour.g-Settings::SelectedColour.g)/FramesToUpdate;
			if(New<0)
				New=0;
			else if(New>255)
				New=255;
			CurrentColour.g=New;
		}
		else if(CurrentColour.b<Settings::SelectedColour.b)
		{
			int New=CurrentColour.b+(Settings::UnselectedColour.b-Settings::SelectedColour.b)/FramesToUpdate;
			if(New<0)
				New=0;
			else if(New>255)
				New=255;
			CurrentColour.b=New;
		}
	}

	Image.SetColour(CurrentColour);
}
void Button::Draw(SDL_Renderer *const Renderer)
{
	Image.Render(Renderer, Position);
}

bool Button::IsSelected() const
{
	return Selected;
}
bool Button::IsClicked() const
{
	return Clicked;
}