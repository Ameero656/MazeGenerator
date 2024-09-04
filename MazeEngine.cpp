#include "MazeEngine.h"
#include "PathLiner.h"

using namespace std;

MazeEngine::MazeEngine() {
	srand(time(0));
}

MazeEngine::Cell::Cell(bool north, bool south, bool east, bool west, int type) : northWall(north), southWall(south), eastWall(east), westWall(west), type(type) {};

void MazeEngine::displayMaze(const vector<vector<MazeEngine::Cell>>& maze, int size, vector<pair<int, int>> lineQueue) {
	string mazeStr = "";
	for (int i = 0; i < maze.size(); i++) {
		string yAxisString = "*" + string(size, '-');
		string whiteSpace = "*" + string(size, ' ');
		int wallHeight = floor(size / 2);
		for (int j = 0; j < maze[0].size(); j++) {
			const MazeEngine::Cell cell = maze[i][j];
			
			if (cell.northWall) mazeStr += yAxisString;
			else mazeStr += whiteSpace;
		}
		mazeStr += "*\n";
		for (int k = 0; k < wallHeight; k++) {
			for (int j = 0; j < maze[0].size(); j++) {
				const MazeEngine::Cell cell = maze[i][j];
				if (cell.westWall) mazeStr += "|";
				else if (j == 0) mazeStr += " ";

				//string gap = i == currentPos.first && j == currentPos.second ? "\033[1;31m " + to_string(cell.type + 1) + " \033[0m" : "   ";
				string gap;

				if (find(lineQueue.begin(), lineQueue.end(), make_pair(i, j)) != lineQueue.end()) {
					string spaceStr = string((size - 1) / 2, ' ');
					gap = spaceStr + "\033[1;32m+\033[0m" + spaceStr;
				}
				else {
					string spaceStr = string(size, ' ');
					gap = spaceStr;
				}
				mazeStr += gap;

				if (j + 1 < maze[0].size()) { //if next cell exists
					const MazeEngine::Cell nextCell = maze[i][j + 1];
					if (!nextCell.westWall) {

						if (cell.eastWall) mazeStr += "|";
						else mazeStr += " ";
					}
				}
				else if (cell.eastWall) mazeStr += "|";
			}
			mazeStr += "\n";
		}

		if (i == maze.size() - 1) {
			for (int j = 0; j < maze[0].size(); j++) {
				const MazeEngine::Cell cell = maze[i][j];

				if (cell.southWall) mazeStr += yAxisString;
				else mazeStr += whiteSpace;
			}
			mazeStr += "*\n";
		}	
	}
	cout << mazeStr;
}

void MazeEngine::generateMaze(vector<vector<Cell>>& maze, pair<int, int> currentPos, bool watcher, int watcherSpeed) {
	auto isVisitedOrWall = [&](const pair<int, int>& pos) {
		return pos.first < 0 || pos.first >= maze.size() ||
			pos.second < 0 || pos.second >= maze[0].size() ||
			maze[pos.first][pos.second].type != -1;
		};
	vector <pair<int, int>> viableAdjacentSquares = {
			{1 + currentPos.first, currentPos.second},
			{currentPos.first, currentPos.second + 1},
			{currentPos.first - 1, currentPos.second},
			{currentPos.first, currentPos.second - 1},
	};
	
	random_shuffle(viableAdjacentSquares.begin(), viableAdjacentSquares.end());

	for (pair<int, int>& newPos : viableAdjacentSquares) {
		if (isVisitedOrWall(newPos)) continue;
		int yChange = currentPos.first - newPos.first;
		int xChange = currentPos.second - newPos.second;
		int direction = -1;
		if (yChange == 1) direction = 0; //N
		if (xChange == -1) direction = 1; //E
		if (yChange == -1) direction = 2; //S
		if (xChange == 1) direction = 3; //W

		Cell& currentCell = maze[currentPos.first][currentPos.second];
		Cell& newCell = maze[newPos.first][newPos.second];

		if (direction == 0) {
			currentCell.northWall = false;
			newCell.southWall = false;
		}
		else if (direction == 1) {
			currentCell.eastWall = false;
			newCell.westWall = false;
		}
		else if (direction == 2) {
			currentCell.southWall = false;
			newCell.northWall = false;
		}
		else if (direction == 3) {
			currentCell.westWall = false;
			newCell.eastWall = false;
		} 

		currentCell.type = 0; //set current pos to visited
		newCell.type = 0;
		if (watcher) {
			system("cls");
			//pathLiner.modifyQueue(direction, pathLiner.getLineQueue().back());
			//displayMaze(maze, 3, pathLiner.getLineQueue());
			this_thread::sleep_for(chrono::milliseconds(watcherSpeed));
		}
		generateMaze(maze, newPos, watcher, watcherSpeed);
	} 

}