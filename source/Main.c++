#include <iostream>

#include "headers/Save.h"
#include "headers/Game.h"

using namespace std;

int main (int argc, char *argv[])
{
	createSave("save01", "./saves/");
	createSave("save02", "./saves/");

	Game game = newGame(
		"Notepad",
		"notepad.exe",
		"./",
		"./saves/",
		loadSaves("./saves/")
	);
	outputGame(game);
	launchGame(game);
	
	return 0;
}