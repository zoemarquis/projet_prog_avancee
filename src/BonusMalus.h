#ifndef BONUS_MALUS_H
#define BONUS_MALUS_H

#include <SDL2/SDL.h>

#include <iostream>

#include "Colors.h"

class Game;

class BonusMalus {
 public:
  BonusMalus(Game* game, int x, int y) : game_(game), x_(x), y_(y) {}

  int getX() const { return x_; }
  int getY() const { return y_; }
  int getWidth() const { return width_; }
  int getHeight() const { return height_; }

  void update() {
    // Déplacer vers le bas pour simuler la chute
    y_ += fall_speed_;
  }
  Color getColor() { return color_; }
  // virtual void applyEffect() = 0;
  void applyEffect() { std::cout << "apply effect bonus malus " << std::endl; }
  void render(SDL_Renderer* renderer);

 protected:
  Color color_{Color::DEFAULT_COLOR};
  Game* game_;

 private:
  int x_;
  int y_;
  int width_{10};
  int height_{10};
  static constexpr int fall_speed_ = 1;  // Vitesse de chute
};

#endif  // BONUS_MALUS_H