#include <iostream>
#include <cstdlib>

#include "Game.h"

// Updates per milliseconds
static sf::Int32 MS_PER_UPDATE = 10.0;

/// <summary>
/// @brief Creates the render window and various manager objects.
/// </summary>
Game::Game()
	: m_window()
	, m_eventManager()
	, m_entityManager(m_eventManager)
	, m_systemManager(m_entityManager, m_eventManager)
	, m_gameManager(m_entityManager, m_eventManager)
{
}

/// <summary>
/// @brief Sets the render window resolution, enables vertical sync and initialises various game systems.
/// </summary>
void Game::init()
{
	// Display the list of all the video modes available for fullscreen
	std::vector<sf::VideoMode> modes = sf::VideoMode::getFullscreenModes();
	
	ScreenSize::setWidth(1440);
	ScreenSize::setHeight(900);
	
	// To run full screen, add a fourth parameter sf::Style::Fullscreen below.	
	m_window.create(sf::VideoMode(ScreenSize::width(), ScreenSize::height()), "BattleTanks");

	m_window.setVerticalSyncEnabled(true);

	m_gameManager.init();

	createSystems();

	m_eventManager.emit<EvStartGame>();
}


/// <summary>
/// @brief Implements the main game loop: handle input, then update and render everything.
/// 
/// The update loop runs at a different FPS than the draw loop, with the priority for the update loop, thus if the PC is too slow, 
/// we keep the updates but draw less frames.
/// </summary>
void Game::run()
{
	sf::Clock clock;
	sf::Int32 lag = 0;
	while (m_window.isOpen() && m_gameManager.isRunning())
	{
		sf::Time dt = clock.restart();
		lag += dt.asMilliseconds();
		processInput();	
		while (lag > MS_PER_UPDATE)
		{
			update();
			lag -= MS_PER_UPDATE;
		}
		update();
		render(dt.asMilliseconds());
	}
}


/// <summary>
/// @brief Handles main key events.
/// 
/// Handles key pressed, key released and window close events.
/// </summary>
void Game::processInput()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();			
			break;
		case sf::Event::KeyPressed:
			m_eventManager.emit<EvKeyboard>(event.key.code, true);
			m_keyHandler.updateKey(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			m_eventManager.emit<EvKeyboard>(event.key.code, false);
			m_keyHandler.updateKey(event.key.code, false);
			break;
		default:
			break;
		}
	}
}


/// <summary>
/// @brief top level game update.
/// 
/// Reads the current game state and updates all relevant game systems.
/// </summary>
void Game::update()
{
	GameState state(m_gameManager.getGameState());

	if (state == GameState::Playing)
	{		
		m_systemManager.update<MovementSystem>(MS_PER_UPDATE);	
		m_systemManager.update<PlayerControlSystem>(MS_PER_UPDATE);
		m_systemManager.update<AiControlSystem>(MS_PER_UPDATE);
		m_systemManager.update<HUDSystem>(MS_PER_UPDATE);
	}
}

/// <summary>
/// @brief top level game render function.
/// 
/// Updates all game systems that perform rendering operations.
/// </summary>
void Game::render(double ms)
{
	m_systemManager.update<RenderSystem>(0.0);
	m_window.display();
}

/// <summary>
/// @brief Helper function to create the various game systems.
/// </summary>
void Game::createSystems()
{
	auto spTexture = std::make_shared<sf::Texture>();
	spTexture->loadFromFile(resourcePath() + "images/SpriteSheet.png");
	spTexture->setSmooth(true);

	m_systemManager.add<LevelSystem>(m_entityManager, m_eventManager);
	m_systemManager.add<RenderSystem>(m_window, spTexture);	
	m_systemManager.add<MovementSystem>();	
	m_systemManager.add<PlayerControlSystem>(m_keyHandler);
	m_systemManager.add<AiControlSystem>();
	m_systemManager.add<HUDSystem>(m_entityManager, m_window);
	m_systemManager.configure();
}

