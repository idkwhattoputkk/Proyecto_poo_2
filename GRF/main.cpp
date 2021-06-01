#define OLC_PGE_APPLICATION
//#include "Mazmorra.h"
#include "Base.h"
int main()
{
	
	//Mazmorra demo;
	//demo.run();
	
	Base game;
		if (game.Construct(192, 160, 4, 4)) //Construct(192, 160, 4, 4)
			game.Start();
	
	
	
		return 0;
	}

