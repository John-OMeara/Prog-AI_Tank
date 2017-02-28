#pragma once

#include <SFML/Graphics.hpp>

#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "entityx/System.h"

#include "KeyHandler.h"
#include "GameManager.h"
#include "ScreenSize.h"
#include "systems/LevelSystem.h"
#include "systems/RenderSystem.h"
#include "systems/MovementSystem.h"
#include "systems/PlayerControlSystem.h"
#include "systems/AiControlSystem.h"
#include "systems/HUDSystem.h"

/// <summary>
/// @Author Ross Palmer
/// @Version 1.0
/// @brief Top level class which manages game initialisation, rendering and updates.
///
/// </summary>

class Game : public entityx::Receiver<Game>
{
public:

	Game();	
	void init();
	void run();

private:

	void processInput();
	void update();
	void render(double ms);
	void createSystems();

	
	/// The SFML render window	
	sf::RenderWindow m_window;

	/// The EntityX event manager.
	entityx::EventManager m_eventManager;

	/// The EntityX entity manager.
	entityx::EntityManager m_entityManager;

	/// The EntityX system manager.
	entityx::SystemManager m_systemManager;

	/// An object to manage games states.
	GameManager m_gameManager;

	KeyHandler m_keyHandler;
};

