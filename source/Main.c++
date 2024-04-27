#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>
#include <windows.h>

using namespace std;

namespace fs = filesystem;

struct Game;
struct Save;

void outputGame(Game game);
void outputSaves(vector<Save> saves, string prefix = "");

struct Game
{
	string name;
	string appPath;
	string savePath;
	string savesPath;
	vector<Save> saves;
};

struct Save
{
	string name;
	string path;
};

void outputGame (Game game)
{
	cout << game.name << ":\n";
	cout << "\tlaunch path: " << game.appPath << "\n";
	cout << "\tsaves path: " << game.savesPath << "\n";
	cout << "\tsaves:\n";

	outputSaves(game.saves, "\t\t");
}

void launchGame (string path)
{
	string str = "\"" + path + "\"";
	system(str.c_str());
}

void outputSaves (vector<Save> saves, string prefix)
{
	for (int i = 0; i < saves.size(); i++)
	{
		Save save = saves.at(i);
		cout << prefix << save.name << ": " << save.path << "\n";
	}
}

void createSave (string name, string path)
{
	fs::create_directories(path + "/" + name);
}

vector<Save> loadSaves (string path)
{
	vector<Save> list;

	for (const auto & entry : fs::directory_iterator(path))
	{
		if (!entry.is_directory())
		{
			continue;
		}
		
		fs::path p = entry.path();
		string name = p.stem().string();

		list.push_back( Save {
			name,
			p.string()
		} );
	}

	return list;
}

int main (int argc, char *argv[])
{
	createSave("save01", "./saves/");
	createSave("save02", "./saves/");

	Game game = { "game", "notepad.exe", "./", "./saves/", loadSaves("./saves/") };
	outputGame(game);
	launchGame(game.appPath);
	
	return 0;
}