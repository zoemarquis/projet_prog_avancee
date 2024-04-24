#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>

#include "Grid.h"
#include "Plateform.h"

class Ball {
 private:
  int radius_;
  int speed_;
  float pos_x_;
  float pos_y_;
  float velocity_x_;
  float velocity_y_;

  SDL_Rect plateformRect;

 public:
  Ball();
  Ball(int radius, int speed, float platformPosX, float platformPosY,
       int platformLength, float velocity_x, float velocity_y);

  void render(SDL_Renderer* renderer);
  bool updatePosition(float dt, int screenWidth, int screenHeight);
  // void checkCollide(const Plateform& p, const Grid& grid);

  float getPosX() const { return pos_x_; }
  float getPosY() const { return pos_y_; }
  int getRadius() const { return radius_; }

  // Méthodes pour inverser les vitesses de la balle
  void reverseVelocityX() { velocity_x_ = -velocity_x_; }
  void reverseVelocityY() { velocity_y_ = -velocity_y_; }
};

#endif  // BALL_H