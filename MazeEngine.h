#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>


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

    void displayMaze(const std::vector<std::vector<MazeEngine::Cell>>& maze, std::pair<int, int> currentPos = { -1, -1 }, int size = 3);

	void generateMaze(std::vector<std::vector<Cell>>& maze, std::pair<int, int> currentPos, bool watcher = false, int watcherSpeed = 100);
    
    
private:
};