#include "Plateform.h"

// Constructeur par défaut
Plateform::Plateform()
    : height_(20), width_(100), pos_x_(25), pos_y_(25), speed_(20) {}

Plateform::Plateform(const float window_width, const float window_height)
    : height_(20), width_(100), speed_(20) {
  pos_x_ = (window_width - width_) / 2;
  pos_y_ = window_height * (7.0 / 8.0) - height_ / 2;
}

// Fonction d'affichage
void Plateform::render(const std::shared_ptr<SDL_Renderer>& renderer) {
  SDL_SetRenderDrawColor(renderer.get(), 255, 255, 255, 255);
  plateformRect = {pos_x_, pos_y_, width_, height_};

  SDL_RenderFillRect(renderer.get(), &plateformRect);
}

// Fonction déplacement clavier
void Plateform::move_keyboard(const SDL_Keycode keyCode, const int screenWidth,
                              const float dt) {
  float speed_factor = 100.0;
  float movement = speed_ * dt * speed_factor;
  switch (keyCode) {
    case SDLK_LEFT:
      if (pos_x_ - movement >= 0) {
        pos_x_ -= movement;
      } else {
        pos_x_ = 0;
      }
      break;
    case SDLK_RIGHT:
      if (pos_x_ + width_ + movement <= screenWidth) {
        pos_x_ += movement;
      } else {
        pos_x_ = screenWidth - width_;
      }
      break;
    default:
      break;
  }
}

// Fonction déplacement souris
void Plateform::move_mouse(const int mouseX, const int mouseY,
                           const int screenWidth) {
  if (mouseX - width_ / 2 >= 0) {
    if (mouseX + width_ / 2 <= screenWidth) {
      pos_x_ = mouseX - width_ / 2;
    } else {
      pos_x_ = screenWidth - width_;
    }
  } else {
    pos_x_ = 0;
  }
}