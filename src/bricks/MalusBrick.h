#ifndef MALUS_BRICK_H
#define MALUS_BRICK_H

#include "SpecialBrick.h"

template <typename Shape>
class MalusBrick : public SpecialBrick<MalusBrick<Shape>, Shape> {
 public:
  MalusBrick(Game* game, std::shared_ptr<SDL_Renderer>& renderer);
  MalusBrick(Game* game, std::shared_ptr<SDL_Renderer>& renderer,
             TriangleCell::Orientation orientation);

  // Méthode pour obtenir la texture du malus
  static std::shared_ptr<SDL_Texture>& getTexture() {
    // Implémentation pour obtenir la texture spécifique à MalusBrick
    return malus_texture_;
  }

  void renderCell(std::shared_ptr<SDL_Renderer>& renderer, int x, int y,
                  int cellWidth, int cellHeight);

  inline Color getColor() const override { return Color::DarkRed; };

 private:
  static std::shared_ptr<SDL_Texture> malus_texture_;  // Attribut pour la
                                                       // texture du malus
};

#include "MalusBrick.hpp"

#endif  // MALUS_BRICK_H