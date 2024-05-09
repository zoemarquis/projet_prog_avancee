#ifndef BONUS_BRICK_H
#define BONUS_BRICK_H

#include "MalusBonusBrick.h"

class BonusBrick : public MalusBonusBrick<BonusBrick> {
 public:
  BonusBrick(Game* game, SDL_Renderer* renderer);

  // Méthode pour obtenir la texture du malus
  static SDL_Texture* getTexture() {
    // Implémentation pour obtenir la texture spécifique à MalusBrick
    return bonus_texture_;
  }

 private:
  static SDL_Texture* bonus_texture_;  // Attribut pour la texture du malus
};

#endif  // BONUS_BRICK_H
