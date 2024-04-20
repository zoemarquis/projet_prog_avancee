#include "Wall.h"

#include <SDL2/SDL_image.h>

Wall::Wall(SDL_Renderer* renderer) : Cell(Color::Yellow) {
  // Chargez la texture du mur depuis un fichier
  SDL_Surface* wallSurface = IMG_Load("../img/wall_texture.jpg");
  if (!wallSurface) {
    // Gestion de l'erreur si le chargement de l'image échoue
    std::cerr << "Failed to load wall texture: " << IMG_GetError() << std::endl;
    return;
  }

  wall_texture_ = SDL_CreateTextureFromSurface(renderer, wallSurface);
  SDL_FreeSurface(wallSurface);
  if (!wall_texture_) {
    // Gestion de l'erreur si la création de la texture échoue
    std::cerr << "Failed to create wall texture: " << SDL_GetError()
              << std::endl;
    return;
  }
}

bool Wall::rebondir() const {
  return true;  // Les objets rebondissent sur les murs
}

bool Wall::traverse() const {
  return false;  // Les murs ne sont pas traversables
}

void Wall::renderCell(SDL_Renderer* renderer, int x, int y, int cellSize) {
  std::cout << "renderCell de Wall" << std::endl;

  int padding = 1;  // Espace entre chaque case
  int size = cellSize - 2 * padding;

  // Utilisez la texture du mur pour afficher le mur
  SDL_Rect rect = {x + padding, y + padding, size, size};
  SDL_RenderCopy(renderer, wall_texture_, NULL, &rect);
}
