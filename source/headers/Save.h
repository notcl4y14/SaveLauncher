#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

struct Save
{
	string name;
	string path;
};

void outputSaves (vector<Save> saves, string prefix);

void createSave (string name, string path);

bool saveExists (string name, string path);

vector<Save> loadSaves (string path);