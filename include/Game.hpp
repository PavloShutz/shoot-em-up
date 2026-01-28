#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "World.hpp"

/**
 * @brief Main game class managing the game loop and player
 *
 * The Game class handles initialization, the main game loop including
 * event processing, updates, and rendering. It manages the game window
 * and player sprite.
 */
class Game {
 public:
  /**
   * @brief Construct a new game instance
   *
   * Initializes the game window, loads textures, and sets up the player sprite.
   */
  Game();

  /**
   * @brief Run the main game loop
   *
   * Runs the game loop with fixed time step updates, processing events,
   * updating game logic, and rendering frames until the window is closed.
   */
  void run();

 private:
  /**
   * @brief Process all pending window events
   *
   * Handles window close events and keyboard input for player movement.
   */
  void processEvents();

  /**
   * @brief Update game state
   *
   * Updates player position based on current movement state.
   *
   * @param deltaTime Time elapsed since the last update
   */
  void update(sf::Time deltaTime);

  /**
   * @brief Render the current game state
   *
   * Clears the window, draws the player sprite, and displays the frame.
   */
  void render();

  /**
   * @brief Handle keyboard input for player movement
   *
   * Updates movement state flags based on WASD key presses/releases.
   *
   * @param scan Scancode of the key that was pressed or released
   * @param isPressed True if the key was pressed, false if released
   */
  void handlePlayerInput(sf::Keyboard::Scan scan, bool isPressed);

 private:
  sf::RenderWindow m_window;
  World            m_world;

  bool m_isMovingUp    = false;
  bool m_isMovingDown  = false;
  bool m_isMovingRight = false;
  bool m_isMovingLeft  = false;

  static const sf::Time TimePerFrame;
};