#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Ball.h"
#include "Grid.h"
#include "Plateform.h"

class CollisionManager {
 public:
  // Méthode principale pour vérifier les collisions
  static void checkCollisions(Plateform& platform, Ball& ball, Grid& grid) {
    checkPlatformBallCollision(platform, ball);
    // checkWindowBallCollision(bounds, ball);
    checkGridBallCollision(grid, ball);
  }

 private:
  // Méthode pour vérifier la collision entre la plateforme et la balle
  static void checkPlatformBallCollision(Plateform& platform, Ball& ball);
  // Méthode pour vérifier la collision entre la balle et la grille
  static void checkGridBallCollision(Grid& grid, Ball& ball);
};

#endif