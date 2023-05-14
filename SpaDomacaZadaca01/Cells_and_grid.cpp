//
// Created by Lorena Kovačić on 13.05.2023..
//

#include "Cells_and_grid.h"
#include <iostream>

Cells_and_grid::Cells_and_grid() {
    std::cout << "Random 1/0 :";
    bool f;
    std::cin >> f;
    if (f)
        for (int i = 0; i < nCell; i++)
            grid[i] = (double(rand()) / RAND_MAX < 0.1) ? 1 : 0;
}

//geteri
float Cells_and_grid::get_cellSize() {
    return cellSize;
}

int Cells_and_grid::get_gWidth() {
    return gWidth;
}

int Cells_and_grid::get_gHeight() {
    return gHeight;
}

int Cells_and_grid::get_nCell() {
    return nCell;
}

int *Cells_and_grid::get_grid() {
    return grid;
}

int *Cells_and_grid::get_nextGrid() {
    return nextGrid;
}

sf::Vector2<float> &Cells_and_grid::get_cells() {
    return const_cast<sf::Vector2<float> &>(cells);
}

int Cells_and_grid::get_delay() {
    return delay;
}
