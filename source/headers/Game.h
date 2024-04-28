#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Save.h"

using namespace std;

struct Game
{
	string name;
	string appPath;
	string savePath;
	string savesPath;
	vector<Save> saves;
};

Game newGame (string name, string appPath, string savePath, string savesPath, vector<Save> saves);

void outputGame (Game game);

int launchGame (Game game);
int launchGame (string path);