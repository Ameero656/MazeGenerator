#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>

using namespace std;

class MazeEngine {
public:
	MazeEngine();

    struct Cell {
        bool northWall;
        bool southWall;
        bool eastWall;
        bool westWall;
        int type;

        // Constructor to initialize walls
        Cell(bool north=true, bool south=true, bool east=true, bool west=true, int type=-1);
    };

    void displayMaze(const vector<vector<MazeEngine::Cell>>& maze, int size = 3, vector<pair<int, int>> lineQueue = {});

	void generateMaze(vector<vector<Cell>>& maze, pair<int, int> currentPos, bool watcher = false, int watcherSpeed = 100);
    
    
private:
};