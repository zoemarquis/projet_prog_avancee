#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include <chrono>
#include <memory>
#include <unordered_set>

#include "Ball.h"
#include "Grid.h"
#include "HexagonCell.h"
#include "Plateform.h"
#include "SquareCell.h"
#include "TriangleCell.h"

// Doit être sous les includes des classes Ball, Grid, BonusMalus et Plateform
#include "CollisionManager.h"

class Ball;
template <typename Shape>
class Grid;
template <typename Shape>
class BonusMalus;
template <typename Shape>
class CollisionManager;
class Plateform;

/**
 * @brief Classe représentant le jeu.
 *
 * Cette classe gère l'exécution du jeu et ses composants.
 */
template <typename Shape>
class Game {
 public:
  /**
   * @brief Constructeur de la classe Game.
   * @param nomFichierGrille Le nom du fichier de la grille de jeu.
   */
  Game(const std::string& nomFichierGrille);

  /**
   * @brief Destructeur de la classe Game.
   */
  ~Game();

  /**
   * @brief Méthode pour exécuter le jeu.
   * @return Le code de sortie de l'exécution.
   */
  int execute();

 private:
  const int screen_width_ = 400;  /**< Largeur de l'écran. */
  const int screen_height_ = 800; /**< Hauteur de l'écran. */

  bool quit_ = false;          /**< Indicateur pour quitter le jeu. */
  bool game_over_ = false;     /**< Indicateur de fin de jeu. */
  bool game_finished_ = false; /**< Indicateur de fin de partie. */
  bool paused_ = true;         /**< Indicateur de pause du jeu. */

  std::shared_ptr<SDL_Window> window_ = nullptr; /**< Fenêtre SDL du jeu. */
  std::shared_ptr<SDL_Renderer> renderer_ = nullptr; /**< Rendu SDL du jeu. */

  std::shared_ptr<Grid<Shape>> grid_; /**< Grille du jeu. */

  Plateform plateform_; /**< Plateforme du jeu. */
  std::unordered_set<std::shared_ptr<Ball>>
      balls_; /**< Ensemble de balles du jeu. */

  /**
   * @brief Initialise SDL.
   */

  void initSDL();

  /**
   * @brief Crée la fenêtre et le rendu.
   */
  void createWindowAndRenderer();

  /**
   * @brief Boucle principale du jeu.
   */
  void mainLoop();

  /**
   * @brief Nettoie les ressources utilisées par le jeu.
   */
  void cleanUp();

  /**
   * @brief Gère les événements SDL.
   * @param event L'événement SDL à gérer.
   * @param dt Le temps écoulé depuis la dernière mise à jour.
   */
  void handleEvents(SDL_Event& event, float dt);

  /**
   * @brief Initialise les composants du jeu.
   * @param nomFichierGrille Le nom du fichier de la grille de jeu.
   */
  void initGameComponents(const std::string& nomFichierGrille);

  /**
   * @brief Met à jour le jeu.
   * @param dt Le temps écoulé depuis la dernière mise à jour.
   */
  void updateGame(float dt);

  /**
   * @brief Effectue le rendu, ll'affichge du jeu.
   */
  void render();

  /**
   * @brief Active/désactive la pause du jeu.
   */
  void togglePause();

  /**
   * @brief Génère des bonus/malus dans le jeu aléatoirement.
   */
  void generateBonusMalus();

  std::unordered_set<std::shared_ptr<BonusMalus<Shape>>> bonus_maluses_;
  /**< Ensemble de bonus/malus du jeu. */

 public:
  /**
   * @brief Accélère les balles (si elles ne sont pas déjà rapides).
   */
  void setBallAccelerating();

  /**
   * @brief Décélère les balles (si elles ne sont pas déjà lentes).
   */
  void setBallDecelerating();

  /**
   * @brief Réduit la largeur de la plateforme (si elle n'est pas déjà à la
   * taille minimale).
   */
  void shrinkPlateformWidth();

  /**
   * @brief Augmente la largeur de la plateform (si elle n'est pas déjà à la
   * taille maximale).
   */
  void enlargePlateformWidth();

  /**
   * @brief Génère de nouvelles balles dans le jeu.
   */
  void generateNewBalls();
};

#include "Game.hpp"

#endif  // GAME_H
