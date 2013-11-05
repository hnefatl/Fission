#ifndef _CONTROL_H
#define _CONTROL_H

#include "Texture.h"
#include "Rect.h"
#include "Point.h"

#include "Resources.h"
#include "Settings.h"

class Control
{
public:
	Control();
	

	virtual bool Load(const std::string &ImagePath, SDL_Renderer *const Renderer);
	virtual bool Load(const std::string &FontPath, const std::string &Text, const unsigned int &PtSize, const Colour &Colour,
		SDL_Renderer *const Renderer);

	virtual bool HandleEvents(const SDL_Event &Event)=0;
	virtual void Update()=0;
	virtual void Draw(SDL_Renderer *const Renderer)=0;

	bool Contains(const Point &Location) const;

	Rect GetLocation() const;
	void SetLocation(const Point &Location);

	Colour GetColour() const;
	void SetColour(const Colour &Colour);

protected:
	Texture Image;
	Rect Position;

	Colour CurrentColour;
};

#endif