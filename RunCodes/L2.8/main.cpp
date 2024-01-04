#include <iostream>
#include <cstddef>
#include <vector>

std::vector<std::vector<int>> createMaze(std::istream& entrada, int size){
    std::vector<std::vector<int>> maze;
    for(int i = 0; i < size; ++i){
        std::vector<int> vec;
        for(int j = 0; j < size; ++j){
            int algarism;
            entrada >> algarism;
            vec.insert(vec.end(), algarism);
        }
    maze.insert(maze.end(), vec);
    }
    return maze;
}

bool algorithm(std::vector<std::vector<int>>& maze, int size, int x0, int y0, int x1, int y1){
    if(x0 == 0 and y0 == 0){
        std::cout << x0 << ' ' << y0 << '\n';
        return true;
    }
    if((x0 - 1) >= 0 and (x0 - 1) != x1 and maze[x0 - 1][y0] == 0){
        if(algorithm(maze, size, x0 - 1, y0, x0, y0)){
            std::cout << x0 << ' ' << y0 << '\n';
            return true;
        }
    }
    if((x0 + 1) < size and (x0 + 1) != x1 and maze[x0 + 1][y0] == 0){
        if(algorithm(maze, size, x0 + 1, y0, x0, y0)){
            std::cout << x0 << ' ' << y0 << '\n';
            return true;
        }
    }
    if((y0 - 1) >= 0 and (y0 - 1) != y1 and maze[x0][y0 - 1] == 0){
        if(algorithm(maze, size, x0, y0 - 1, x0, y0)){
            std::cout << x0 << ' ' << y0 << '\n';
            return true;
        }
    }
    if((y0 + 1) < size and (y0 + 1) != y1 and maze[x0][y0 + 1] == 0){
        if(algorithm(maze, size, x0, y0 + 1, x0, y0)){
            std::cout << x0 << ' ' << y0 << '\n';
            return true;
        }
    }
    return false;
}


int main(){
    int size;
    std::cin >> size;
    std::vector<std::vector<int>> maze = createMaze(std::cin, size);
    algorithm(maze, size, size-1, size-1, size-1, size-1);
}