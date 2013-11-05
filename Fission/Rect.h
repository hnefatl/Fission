#ifndef _RECT_H
#define _RECT_H

#include <SDL.h>

#include "Point.h"

class Rect
	: public SDL_Rect
{
public:
	Rect(const int &x=0, const int &y=0, const unsigned int &w=0, const unsigned int &h=0)
	{
		this->x=x;
		this->y=y;
		this->w=w;
		this->h=h;
	}
	Rect(const Point &Position, const unsigned int &w=0, const unsigned int &h=0)
	{
		this->x=Position.x;
		this->y=Position.y;
		this->w=w;
		this->h=h;
	}

	operator SDL_Rect ()
	{
		return (SDL_Rect)*this;
	}
	operator Point ()
	{
		return Point(x, y);
	}
};

#endif