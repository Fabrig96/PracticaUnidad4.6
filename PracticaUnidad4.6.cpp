//MAVI - Unidad 4 - Ejercicio 6

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "PlayGame.h"
using namespace sf;

int main() {
	
	unsigned int seed = static_cast<unsigned int>(std::time(0));
	std::srand(seed);

	PlayGame game;
	game.gameLoop();
	

	return 0;

}
