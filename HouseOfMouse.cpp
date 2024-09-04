#include "MazeEngine.h"
#include "PathLiner.h"

#include <iostream>

using namespace std;

vector<vector<MazeEngine::Cell>> generateMaze(MazeEngine& mazeEngine, pair<int, int> mazeDimensions = {16, 16}, int mapProjectionSize = 3, bool watcher = false, int watchspeed = 50) {
	
	vector<vector<MazeEngine::Cell>> maze(mazeDimensions.first, vector<MazeEngine::Cell>(mazeDimensions.second));
	pair<int, int> startingPos = {0, 0};
	PathLiner pathLiner(maze, startingPos);
	mazeEngine.generateMaze(maze, startingPos, watcher, watchspeed);
	int size = 3; // size > 1; size % 2 != 0 (odd numbers > 1)
	mazeEngine.displayMaze(maze, mapProjectionSize);
	return maze;
}

int main() {
	MazeEngine mazeEngine;
	
	vector<vector<MazeEngine::Cell>> maze = generateMaze(mazeEngine);
	pair<int, int> currentPos = { 0, 0 };	
	PathLiner pathLiner(maze, currentPos);

	//while (true) {
	//	int direction;
	//	cout << "path direction:";
	//	cin >> direction;
	//	pathLiner.modifyQueue(direction, pathLiner.getLineQueue().back());
	//	system("cls");
	//	mazeEngine.displayMaze(maze, 3, pathLiner.getLineQueue());
	//	/*for (const auto& line : pathLiner.getLineQueue()) {
	//		std::cout << "{" << line.first << ", " << line.second << "}\n";
	//	}*/
	//}



}