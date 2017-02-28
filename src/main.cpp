
#include "Game.h"

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#pragma comment(lib,"entityx-d.lib") 
#pragma comment(lib,"libyaml-cppmdd") 
#pragma comment(lib,"thor-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#pragma comment(lib,"entityx.lib") 
#pragma comment(lib,"libyaml-cppmdd") 
#pragma comment(lib,"thor.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 



/// <summary>
/// @mainpage Battletanks - A top down tank shooter.
/// @Author Ross Palmer
/// @Version 1.0
/// @brief A top down tank shooter.
///
/// A demo where you control a tank and turret..
/// an AI tank will avoid obstacles and seek your
/// position. Gameplay to be decided...
/// </summary>


int main(int argc, char* args[])
{
	Game game;
	game.init();
	game.run();
	return 0;
}