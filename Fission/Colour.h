#ifndef _COLOUR_H
#define _COLOUR_H

#include <SDL.h>

class Colour
	: public SDL_Colour
{
public:
	Colour(const Uint8 &r=0x00, const Uint8 &g=0x00, const Uint8 &b=0x00, const Uint8 &a=0xFF)
	{
		this->r=r;
		this->g=g;
		this->b=b;
		this->a=a;
	}

	operator SDL_Colour ()
	{
		return (SDL_Colour)*this;
	}
};

#endif