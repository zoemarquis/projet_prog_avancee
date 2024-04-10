#include "Plateform.h"

// Constructeur par défaut
Plateform::Plateform()
    : height_(20), width_(100), pos_x_(25), pos_y_(25), speed_(10) {}

Plateform::Plateform(float window_width, float window_height)
    : height_(20), width_(100), speed_(20) {
  pos_x_ = (window_width - width_) / 2;
  pos_y_ = window_height * (7.0 / 8.0) - height_ / 2;
}

// Get
int Plateform::getHeight() const { return height_; }
int Plateform::getWidth() const { return width_; }
int Plateform::getPosX() const { return pos_x_; }
int Plateform::getPosY() const { return pos_y_; }
float Plateform::getSpeed() const { return speed_; }

// Set
void Plateform::setHeight(int height) { height_ = height; }
void Plateform::setWidth(int width) { width_ = width; }
void Plateform::setPosX(int pos_x) { pos_x_ = pos_x; }
void Plateform::setPosY(int pos_y) { pos_y_ = pos_y; }
void Plateform::setSpeed(float speed) { speed_ = speed; }

// Fonction d'affichage
void Plateform::render(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  plateformRect = {pos_x_, pos_y_, width_, height_};

  SDL_RenderFillRect(renderer, &plateformRect);
}

// Fonction déplacement clavier
void Plateform::move_keyboard(SDL_Keycode keyCode, int screenWidth) {
  switch (keyCode) {
    case SDLK_LEFT:
      if (pos_x_ - speed_ >= 0) {
        pos_x_ -= speed_;
      } else {
        pos_x_ = 0;
      }
      break;
    case SDLK_RIGHT:
      if (pos_x_ + width_ + speed_ <= screenWidth) {
        pos_x_ += speed_;
      } else {
        pos_x_ = screenWidth - width_;
      }
      break;
    default:
      break;
  }
}

// Fonction déplacement souris
void Plateform::move_mouse(int mouseX, int mouseY, int screenWidth) {
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