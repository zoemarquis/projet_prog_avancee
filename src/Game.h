#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include <chrono>
#include <memory>
#include <unordered_set>

#include "Ball.h"
#include "CollisionManager.h"
#include "Grid.h"
#include "Plateform.h"
#include "Shape.h"
#include "bonus_malus/BonusMalus.h"

class Ball;
template <typename SquareCell>
class Grid;
class BonusMalus;
class CollisionManager;
class Plateform;

class Game {
 public:
  Game(const std::string& nomFichierGrille);
  ~Game();
  int execute();

 private:
  const int screen_width_ = 400;
  const int screen_height_ = 800;

  bool quit_ = false;
  bool game_over_ = false;
  bool game_finished_ = false;
  bool left_key_down_ = false;
  bool right_key_down_ = false;
  bool paused_ = true;

  std::shared_ptr<SDL_Window> window_ = nullptr;
  std::shared_ptr<SDL_Renderer> renderer_ = nullptr;
  std::shared_ptr<Grid<SquareCell>> grid_;
  Plateform plateform_;
  std::unordered_set<std::shared_ptr<Ball>> balls_;

  void initSDL();
  void createWindowAndRenderer();
  void mainLoop();
  void cleanUp();
  void handleEvents(SDL_Event& event);
  void initGameComponents(const std::string& nomFichierGrille);
  void updateGame(float dt);
  void render();
  void togglePause();

  void generateBonusMalus();
  std::unordered_set<std::shared_ptr<BonusMalus>> bonus_maluses_;

  bool ball_accelerating_ = false;

 public:
  void setBallAccelerating();
  void setBallDecelerating();

  void shrinkPlateformWidth();
  void enlargePlateformWidth();

  void generateNewBalls();
};

#endif  // GAME_H
