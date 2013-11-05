#ifndef _TEXTURE_H
#define _TEXTURE_H

#include "Print.h"

#include "Point.h"
#include "Rect.h"
#include "Colour.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include <string>

class Texture
{
public:
	Texture();
	~Texture();

	bool Load(const std::string &Path, SDL_Renderer *const Renderer);
	bool Load(const std::string &Text, const std::string &FontFile, const unsigned int &Size, const Colour &TextColour, SDL_Renderer *const Renderer);

	static Texture *Create(const std::string &Path, SDL_Renderer *const Renderer);
	static Texture *Create(const std::string &Text, const std::string &FontFile, const unsigned int &Size, const Colour &TextColour, SDL_Renderer *const Renderer);

	void Render(SDL_Renderer *const Renderer, const Point &Position);
	void Render(SDL_Renderer *const Renderer, const Point &Position, const SDL_RendererFlip &Flip);
	void Render(SDL_Renderer *const Renderer, const Point &Position, const double &Angle, Point *const Centre);
	void Render(SDL_Renderer *const Renderer, const Point &Position, const double &Angle, Point *const Centre, const SDL_RendererFlip &Flip);
	void Render(SDL_Renderer *const Renderer, const Point &Position, Rect *const Clip);
	void Render(SDL_Renderer *const Renderer, const Point &Position, Rect *const Clip, const double &Angle, Point *const Centre);
	void Render(SDL_Renderer *const Renderer, const Point &Position, Rect *const Clip, const double &Angle, Point *const Centre, const SDL_RendererFlip &Flip);

	void SetColour(const Colour &Colour);
	void SetBlendMode(const SDL_BlendMode &Mode);

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

protected:
	void Free();

	SDL_Texture *Image;

	unsigned int Width, Height;
};

#endif