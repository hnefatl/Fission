#include "Control.h"

#include "Settings.h"

Control::Control()
{
	CurrentColour=Settings::UnselectedColour;
}

bool Control::Load(const std::string &ImagePath, SDL_Renderer *const Renderer)
{
	if(!Image.Load(ImagePath, Renderer))
	{
		return false;
	}

	Position.w=Image.GetWidth();
	Position.h=Image.GetHeight();

	return true;
}
bool Control::Load(const std::string &FontPath, const std::string &Text, const unsigned int &PtSize, const Colour &Colour,
		SDL_Renderer *const Renderer)
{
	if(!Image.Load(Text, FontPath, PtSize, Colour, Renderer))
	{
		return false;
	}

	Position.w=Image.GetWidth();
	Position.h=Image.GetHeight();

	return true;
}

bool Control::Contains(const Point &Location) const
{
	return (Position.x<=Location.x &&
		Position.x+Position.w>=Location.x &&
		Position.y<=Location.y &&
		Position.y+Position.h>=Location.y);
}

Rect Control::GetLocation() const
{
	return Position;
}
void Control::SetLocation(const Point &Location)
{
	Position=Location;
}

Colour Control::GetColour() const
{
	return CurrentColour;
}
void Control::SetColour(const Colour &Colour)
{
	this->CurrentColour=Colour;
}