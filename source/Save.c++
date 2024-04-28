#include "headers/Save.h"

using namespace std;

namespace fs = filesystem;

// struct Save
// {
// 	string name;
// 	string path;
// };

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
	if (saveExists(name, path))
	{
		return;
	}
	
	fs::create_directories(path + "/" + name);
}

bool saveExists (string name, string path)
{
	return fs::exists(path + "/" + name);
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