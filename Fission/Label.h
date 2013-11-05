#ifndef _LABEL_H
#define _LABEL_H

#include "Control.h"

class Label
	: public Control
{
public:
	Label();

	virtual bool HandleEvents(const SDL_Event &Event);
	virtual void Update();
	virtual void Draw(SDL_Renderer *const Renderer);

protected:

};

#endif