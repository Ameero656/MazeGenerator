#pragma once
#include "MazeEngine.h"

using namespace std;

class PathLiner {
public:
	PathLiner(vector<vector<MazeEngine::Cell>> maze, pair<int, int> startingPos);
	vector<pair<int, int>> getLineQueue();
	void modifyQueue(int direction, std::pair<int, int> startingPos);

private:
	std::pair<int, int> startingPos;
	vector<vector<MazeEngine::Cell>> maze;
	vector<pair<int, int>> lineQueue;
};