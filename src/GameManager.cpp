#include "GameManager.h"

static const int NR_OF_LEVELS = 1;

/// <summary>
/// @brief Sets the initial game state to game running status.
/// </summary>
/// <param name="entityManager">A reference to an EntityX EntityManager</param>
/// <param name="eventManager">A reference to an EntityX EventManager</param>
GameManager::GameManager(entityx::EntityManager& entityManager,
	entityx::EventManager& eventManager)
	: m_entityManager(entityManager)
	, m_eventManager(eventManager)
	, m_gameState(GameState::StartMenu)
	, m_currentLevel(1)
	, m_isRunning(true)
{
}

/// <summary>
/// @brief
/// </summary>
void GameManager::init()
{
	// Note: Events are structs defined in header file Events.h
	m_eventManager.subscribe<EvStartGame>(*this);

}

GameState GameManager::getGameState() const
{
	return m_gameState;
}

bool GameManager::isRunning() const
{
	return m_isRunning;
}

/// <summary>
/// @brief
/// </summary>
void GameManager::receive(const EvStartGame& startGame)
{
	m_gameState = GameState::Playing;

	m_entityManager.reset();

	// Load the game level data.
	LevelData level;

	if (!LevelLoader::load(m_currentLevel, level))
	{
		return;
	}

	// Tell the LevelSystem to create the game Entities
	m_eventManager.emit<EvInit>(m_currentLevel, level);
}



