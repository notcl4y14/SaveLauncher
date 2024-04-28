#include "headers/Game.h"

using namespace std;

// struct Game
// {
// 	string name;
// 	string appPath;
// 	string savePath;
// 	string savesPath;
// 	vector<Save> saves;
// };

Game newGame (string name, string appPath, string savePath, string savesPath, vector<Save> saves)
{
	Game game;
	game.name = name;
	game.appPath = appPath;
	game.savePath = savePath;
	game.savesPath = savesPath;
	game.saves = saves;
	return game;
}

void outputGame (Game game)
{
	cout << game.name << ":\n";
	cout << "\tlaunch path: " << game.appPath << "\n";
	cout << "\tsaves path: " << game.savesPath << "\n";
	cout << "\tsaves:\n";

	outputSaves(game.saves, "\t\t");
}

int launchGame (Game game)
{
	return launchGame(game.appPath);
}

int launchGame (string path)
{
	// https://stackoverflow.com/a/9209212/22146374

	FILE *handle = popen(path.c_str(), "r");

	if (handle == NULL) {
			return 1;
	}

	char buf[64];
	size_t readn;
	while ((readn = fread(buf, 1, sizeof(buf), handle)) > 0) {
		fwrite(buf, 1, readn, stdout);
	}

	pclose(handle);
	return 0;
}