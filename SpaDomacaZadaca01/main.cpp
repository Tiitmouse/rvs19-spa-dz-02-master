#include <SFML/Graphics.hpp>
#include <iostream>
#include "Cells_and_grid.h"

int wrapValue(int v, int vMax);

int main() {
    std::cout << "Press Space To Start/Stop" << std::endl << "Press on the cell to Kill Or Revive" << std::endl;
    Cells_and_grid cg;
    bool isPlaying = false;

    sf::RenderWindow window(sf::VideoMode(cg.get_cellSize() * cg.get_gWidth(),
                                          cg.get_cellSize() * cg.get_gHeight()), "GameOfLife");


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Space)
                        isPlaying = !isPlaying;

                case sf::Event::MouseButtonPressed:
                    if (!isPlaying && event.mouseButton.button == sf::Mouse::Left) {
                        int x = double(event.mouseButton.x) / cg.get_cellSize();
                        int y = double(event.mouseButton.y) / cg.get_cellSize();
                        if (x >= 0 && x < cg.get_gWidth() && y >= 0 && y < cg.get_gHeight())
                            cg.get_grid()[x + y * cg.get_gWidth()] = !cg.get_grid()[x + y * cg.get_gWidth()];
                    }
                    break;
            }
        }

        window.clear(sf::Color::White);
        for (int x = 0; x < cg.get_gWidth(); x++) {
            for (int y = 0; y < cg.get_gHeight(); y++) {
                sf::RectangleShape cell;
                cell.setPosition(x * cg.get_cellSize(), y * cg.get_cellSize());
                cell.setSize(cg.get_cells());
                cell.setOutlineThickness(1);
                cell.setOutlineColor(sf::Color(153, 153, 153));
                if (cg.get_grid()[x + y * cg.get_gWidth()] == 1)
                    cell.setFillColor(sf::Color::Black);
                else
                    cell.setFillColor(sf::Color::White);
                window.draw(cell);

                if (isPlaying) {
                    int neighborSum = 0;
                    for (int i = -1; i < 2; i++)
                        for (int j = -1; j < 2; j++) {
                            int xi = wrapValue(x + i, cg.get_gWidth());
                            int yj = wrapValue(y + j, cg.get_gHeight());
                            neighborSum += cg.get_grid()[xi + yj * cg.get_gWidth()];
                        }

                    int current = x + y * cg.get_gWidth();
                    neighborSum -= cg.get_grid()[current];
                    cg.get_nextGrid()[current] = cg.get_grid()[current];
                    if (cg.get_grid()[current] == 1 && (neighborSum < 2 || neighborSum > 3))
                        cg.get_nextGrid()[current] = 0;
                    else if (neighborSum == 3)
                        cg.get_nextGrid()[current] = 1;
                }
            }
        }

        if (isPlaying)
            for (int i = 0; i < cg.get_nCell(); i++)
                cg.get_grid()[i] = cg.get_nextGrid()[i];

        window.display();
        sf::sleep(sf::milliseconds(cg.get_delay()));
    }
}

int wrapValue(int v, int vMax) {
    if (v == -1) return vMax - 1;
    if (v == vMax) return 0;
    return v;
}
