#include <iostream>

#include "Game.hpp"

int main() {
	try {
		Game game;
		game.run();
	}
	catch (std::exception& e) {
		std::cerr << "\nEXCEPTION: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}