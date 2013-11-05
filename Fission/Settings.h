#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <SDL.h>
#include <vector>
#include <string>

#include "Colour.h"

class Settings
{
public:
	static bool Initialise();

	static bool Load();
	static bool Save();
	
	static Colour SelectedColour;
	static Colour UnselectedColour;

	const static unsigned int WindowWidth;
	const static unsigned int WindowHeight;

protected:
	static std::string FilePath;

	static std::vector<std::string> Split(const std::string &Input, const std::string &Delimiters);
};

#endif