#include "MazeEngine.h"
#include "PathLiner.h"

using namespace std;

PathLiner::PathLiner(vector<vector<MazeEngine::Cell>> maze, pair<int, int> startingPos) : maze(maze) { lineQueue.push_back({startingPos}); };

vector<pair<int, int>> PathLiner::getLineQueue() {
	return lineQueue;
}

void PathLiner::modifyQueue(int direction, std::pair<int, int> startingPos) {

	auto isVisitedOrWall = [&](const pair<int, int>& pos) {
		if (pos.first < 0 || pos.first >= maze.size() ||
			pos.second < 0 || pos.second >= maze[0].size()) {
			return true;
		}
		if (direction == 0 && !maze[pos.first][pos.second].southWall) return false;
		if (direction == 1 && !maze[pos.first][pos.second].westWall) return false;
		if (direction == 2 && !maze[pos.first][pos.second].northWall) return false;
		if (direction == 3 && !maze[pos.first][pos.second].eastWall) return false;
	};

	vector <pair<int, int>> viableAdjacentSquares = {
		{startingPos.first - 1, startingPos.second}, //N
		{startingPos.first, startingPos.second + 1}, //E
		{startingPos.first + 1, startingPos.second}, //S
		{startingPos.first, startingPos.second - 1}, //W
	};
	std::pair<int, int> desiredPos = viableAdjacentSquares[direction];
	viableAdjacentSquares.erase(remove_if
		(viableAdjacentSquares.begin(), viableAdjacentSquares.end(), isVisitedOrWall), 
		viableAdjacentSquares.end());
		
	if (std::find(viableAdjacentSquares.begin(), viableAdjacentSquares.end(), desiredPos) == viableAdjacentSquares.end()) {
		auto it = std::find(lineQueue.begin(), lineQueue.end(), startingPos);
		if (it != lineQueue.end()) {
			lineQueue.erase(it, lineQueue.end());
		}
		lineQueue.push_back(startingPos);
		return;
	}
	modifyQueue(direction, desiredPos);
}
