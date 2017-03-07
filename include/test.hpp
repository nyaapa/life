#pragma once

#include <array>
#include <cstring>
#include <SFML/Graphics.hpp>

template<int rows, int cols>
class Field {
public:
    const float GRID_LINE_WIDTH = .7f;

    Field(const sf::Vector2u&& windowSize) : cameraHeight{static_cast<float>(windowSize.x)}, cameraWidth{static_cast<float>(windowSize.y)}, cellHeight{cameraHeight/rows}, cellWidth{cameraWidth/cols} {
        int idx = 0;
        for (int i = 1; i < rows; ++i) {
            grid[idx].setPosition(0, i*cellHeight);
            grid[idx++].setSize({cameraHeight, GRID_LINE_WIDTH});
        }

        for (int i = 1; i < cols; ++i) {
            grid[idx].setPosition(i*cellWidth, 0);
            grid[idx++].setSize({GRID_LINE_WIDTH, cameraWidth});
        }

        for (bool& cell : lights)
            cell = false;
    }
    
    bool& at(int row, int col) {
        return lights[row*cols + col];
    }

    void draw(sf::RenderWindow& window) {
        for (auto& line : grid)
            window.draw(line);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (at(i, j)) {
                    sf::RectangleShape cell({cellWidth, cellHeight});
                    cell.setPosition(i * cellWidth, j * cellHeight);
                    window.draw(cell);
                }
    }

    void step() {
        bool newLights[cols*rows];
        int pos = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int neigh = 0;
                if (i > 0 && lights[pos - cols])
                    ++neigh;
                if (i < rows - 1 && lights[pos + cols])
                    ++neigh;
                if (j > 0 && lights[pos - 1])
                    ++neigh;
                if (j < cols - 1 && lights[pos + 1])
                    ++neigh;
                if (i > 0 && j > 0 && lights[pos - 1 - cols])
                    ++neigh;
                if (i > 0 && j < cols - 1 && lights[pos + 1 - cols])
                    ++neigh;
                if (i < rows - 1 && j > 0 && lights[pos + cols - 1])
                    ++neigh;
                if (i < rows - 1 && j < cols - 1 && lights[pos + cols + 1])
                    ++neigh;
                switch (neigh) {
                    case 0:
                    case 1: newLights[pos++] = false; break;
                    case 2: newLights[pos++] = at(i, j); break;
                    case 3: newLights[pos++] = true; break;
                    case 4: 
                    case 5:
                    case 6:
                    case 7:
                    case 8: newLights[pos++] = false; break;
                }
            }
        }
        std::memcpy(lights, newLights, sizeof(lights));
    }

private:
    sf::RectangleShape grid[cols + rows - 2];
    bool lights[cols*rows];
    float cameraHeight;
    float cameraWidth;

    float cellHeight;
    float cellWidth;
};