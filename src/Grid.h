#ifndef GRID_H
#define GRID_H

#include <string>
#include <vector>

#include "Cell.h"
// #include "Game.h"
#include "InputParser.h"
#include "bricks/BasicBrick.h"
#include "bricks/Empty.h"
// #include "bricks/BasicBrick.h"
// #include "bricks/Empty.h"
//  #include "bricks/EnlargeBrick.h"
//  #include "bricks/MalusBrick.h"
//  #include "bricks/ShrinkBrick.h"
//  #include "bricks/SlowedDownBrick.h"
//  #include "bricks/SpedUpBrick.h"
#include "bricks/Wall.h"

template <typename Shape>
class Game;

template <typename Shape>
class Grid {
 public:
  Grid(const std::string& filename, int width, int height,
       std::shared_ptr<SDL_Renderer>& renderer, Game<Shape>* game);

  ~Grid() {
    for (auto& row : grid_) {
      for (auto& cell : row) {
        delete cell;
      }
    }
  }

  void renderGrid(std::shared_ptr<SDL_Renderer>& renderer, int screenWidth,
                  int screenHeight) const;

  inline int getRows() const { return rows_; }
  inline int getCols() const { return cols_; }
  inline int getCellSize() const {
    return std::min(width_ / getCols(), height_ / getRows());
  }
  Cell<Shape>* getCell(int row, int col) const {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
      return nullptr;
    }
    return grid_[row][col];
  }

  void hitCell(int x, int y) {
    Cell<Shape>* c = getCell(x, y);
    BasicBrick<Shape>* basicBrick =
        dynamic_cast<BasicBrick<Shape>*>(c);  // Vérifie si c est un BasicBrick

    bool detruit = c->hit();
    if (detruit) {
      delete grid_[x][y];
      grid_[x][y] = new Empty<Shape>();
      if (basicBrick) remainingBricks_--;
    }
  }

  inline bool hasRemainingBricks() const { return remainingBricks_ > 0; }

 private:
  int rows_;
  int cols_;
  int width_;
  int height_;
  Game<Shape>* game_;
  std::vector<std::vector<Cell<Shape>*>> grid_;
  std::shared_ptr<SDL_Renderer>& renderer_;
  int remainingBricks_;  // Nouvel attribut pour su
};

// #include "Grid.hpp"

// Definir que Shape est un SquareCell
// typedef Grid<SquareCell> SquareGrid;

#endif  // GRID_H
