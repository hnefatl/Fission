#include <SDL.h>
#ifdef _DEBUG
#include <iostream>
#endif

#include "Settings.h"
#include "Simulation.h"

int main(int argc, char *argv[])
{
	if(!InitialisePrint())
	{
		return -1;
	}
	if(!Settings::Initialise())
	{
		return -2;
	}
	if(!Settings::Load())
	{
		return -3;
	}

	Simulation Sim;
	if(!Sim.Load())
	{
		return -4;
	}

	Sim.Run();

	return 0;
}