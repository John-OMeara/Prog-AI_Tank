#pragma once

#include <SFML/Graphics.hpp>
#include "entityx/System.h"
#include "systems/Events.h"
#include "components/Position.h"
#include "components/Background.h"
#include "components/Display.h"
#include "components/Turret.h"
#include "ScreenSize.h"
#include "ResourcePath.hpp"


/// <summary>
/// @Author Ross Palmer
/// @Version 1.0
/// @brief A system to load the background image and handle the rendering of all game images.
///
/// </summary>
class RenderSystem : public entityx::System<RenderSystem>
{
public:
   /// <summary>
   /// Loads the background image, creates the sprites for the background and main sprite sheet.
   /// </summary>
   /// <param name="window">The SFML render window.</param>
   /// <param name="spSSTexture">The sprite sheet texture.</param>
   RenderSystem(sf::RenderWindow& window,
                const std::shared_ptr<sf::Texture>& spSSTexture);

   /// <summary>
   /// Clears the render window to black and draws the game background.
   /// </summary>
   /// <param name="entities">The EntityX entity manager</param>
   /// <param name="events">The EntityX event manager</param>
   /// <param name="dt">The time between frames</param>
   void update(entityx::EntityManager& entities,
               entityx::EventManager& events,
               double dt);
  

private:
   bool isOutsideScreen(const sf::Vector2f& position,
		int width,
		int height);

   /// <summary>
   /// A reference to the SFML render window.
   /// </summary>
   sf::RenderWindow& m_window;

   /// <summary>
   /// The main sprite sheet for the game.
   /// </summary>
   std::shared_ptr<sf::Texture> m_spSSTexture;

   /// <summary>
   /// A texture for the game background.
   /// </summary>
   sf::Texture m_bgTexture;

   /// <summary>
   /// A sprite for the game background.
   /// </summary>
   sf::Sprite m_bgSprite;

   /// <summary>
   /// A sprite for the main sprite sheet.
   /// </summary>
   sf::Sprite m_sprite;
};
