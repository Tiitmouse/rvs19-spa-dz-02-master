//
// Created by Lorena Kovačić on 13.05.2023..
//

#ifndef SPA_ZADACA2_CELLS_AND_GRID_H
#define SPA_ZADACA2_CELLS_AND_GRID_H

#include <SFML/Graphics.hpp>

class Cells_and_grid {
private:
    const float cellSize = 20;
    const sf::Vector2f cells{cellSize,cellSize};
    static const int gWidth = 50;
    static const int gHeight = 50;
    static const int nCell = gWidth * gHeight;
    int grid[nCell] = {  };
    int nextGrid[nCell];
    int delay = 100;
public:
    Cells_and_grid();
    sf::Vector2<float>& get_cells();
    float get_cellSize();
    int get_gWidth();
    int get_gHeight();
    int get_nCell();
    int* get_grid();
    int* get_nextGrid();
    int get_delay();




};


#endif //SPA_ZADACA2_CELLS_AND_GRID_H
