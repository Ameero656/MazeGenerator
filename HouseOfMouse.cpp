#include "MazeEngine.h"

#include <iostream>

//void displayMaze(const std::vector<std::vector<MazeEngine::Cell>>& maze) {
//	for (int i = 0; i < maze.size(); i++) {
//		for (int j = 0; j < maze[0].size(); j++) {
//			const MazeEngine::Cell cell = maze[i][j];
//			int whitespace = 0;
//
//			if (cell.northWall) std::cout << "N";
//			else whitespace++;
//			if (cell.eastWall) std::cout << "E";
//			else whitespace++;
//			if (cell.southWall) std::cout << "S";
//			else whitespace++;
//			if (cell.westWall) std::cout << "W";
//			else whitespace++;
//
//			std::string space(" ", whitespace);
//			std::cout << space << "|";
//		}
//		std::cout << "\n--------------------\n";
//	}
//}



int main() {
	MazeEngine mazeEngine;
	while (true) {
		std::cout << "Generate Maze MazeX, MazeY, MazeProjectionSize, startX, startY, watcher, watchspeed(ms):";
		int mazeX, mazeY, projSize, startX, startY, watchspeed;
		bool watcher = false;
		std::cin >> mazeX >> mazeY >> projSize >> startX >> startY >> watcher >> watchspeed;
		std::vector<std::vector<MazeEngine::Cell>> maze(mazeY, std::vector<MazeEngine::Cell>(mazeX));
		std::pair<int, int> startingPos = { startY, startX};
		mazeEngine.generateMaze(maze, startingPos, watcher, watchspeed);
		int size = 3; // size > 1; size % 2 != 0 (odd numbers > 1)
		mazeEngine.displayMaze(maze, startingPos, size);
	}
	
}