#include "Game.h"

#include <iostream>

Game::Game()
    : plateform_(screen_width_, screen_height_),
      ball_(10, 300, plateform_.getPosX(), plateform_.getPosY(),
            plateform_.getWidth(), 0.5, -0.5) {
  initSDL();
  createWindowAndRenderer();
  initGameComponents();
}

Game::~Game() { cleanUp(); }

void Game::initSDL() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    std::cerr << "Erreur lors de l'initialisation de la SDL2: "
              << SDL_GetError() << std::endl;
    exit(1);
  }
}

void Game::createWindowAndRenderer() {
  window_ = SDL_CreateWindow("Game Board", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, screen_width_,
                             screen_height_, SDL_WINDOW_SHOWN);
  if (!window_) {
    std::cerr << "Error creating windows_: " << SDL_GetError() << std::endl;
    SDL_Quit();
    exit(1);
  }

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  if (!renderer_) {
    std::cerr << "Error creating renderer_: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window_);
    SDL_Quit();
    exit(1);
  }
}

void Game::initGameComponents() {
  grid_ = new Grid("../grilles/grille2.txt", screen_width_, screen_height_,
                   renderer_);
}

int Game::execute() {
  mainLoop();
  return 0;
}

void Game::mainLoop() {
  Uint32 previousTime = SDL_GetTicks();
  SDL_Event event;
  while (!quit_ && !game_over_) {
    float dt = (SDL_GetTicks() - previousTime) / 1000.0f;
    previousTime = SDL_GetTicks();
    while (SDL_PollEvent(&event)) {
      handleEvents(event);
    }
    updateGame(dt);
    render();
  }
  if (game_over_) {
    std::cout << "Game Over !!" << std::endl;
  }
}

void Game::handleEvents(SDL_Event& event) {
  if (event.type == SDL_QUIT) {
    quit_ = true;
  }
  // Clavier
  else if (event.type == SDL_KEYDOWN) {
    if (event.key.keysym.sym == SDLK_LEFT) {
      left_key_down_ = true;
    } else if (event.key.keysym.sym == SDLK_RIGHT) {
      right_key_down_ = true;
    }
  } else if (event.type == SDL_KEYUP) {
    if (event.key.keysym.sym == SDLK_LEFT) {
      left_key_down_ = false;
    } else if (event.key.keysym.sym == SDLK_RIGHT) {
      right_key_down_ = false;
    }
  }

  // Souris
  else if (event.type == SDL_MOUSEMOTION) {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    plateform_.move_mouse(mouseX, mouseY, screen_width_);
  }
}

void Game::updateGame(float dt) {
  // Mise à jour position balle
  game_over_ = ball_.updatePosition(dt, screen_width_, screen_height_);
  CollisionManager::checkCollisions(plateform_, ball_, *grid_);
}

void Game::render() {
  // Mise à jour affichage
  SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
  SDL_RenderClear(renderer_);

  grid_->renderGrid(renderer_, screen_width_, screen_height_);
  plateform_.render(renderer_);
  ball_.render(renderer_);

  SDL_RenderPresent(renderer_);
}

void Game::cleanUp() {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}
