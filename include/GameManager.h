#pragma once

#include "entityx/Event.h"
#include "entityx/Entity.h"
#include "systems/Events.h"
#include "EntityCreator.h"


/// <summary>
/// The six modes planned for this game (currently supports Playing only).
/// </summary>
enum class GameState
{
	StartMenu,
	Playing,
	Paused,
	GameOver,
	LevelCompleted,
	GameCompleted,
};


/// <summary>
/// @Author Ross Palmer
/// @Version 1.0
/// @brief An entityX Receiver class that manages game states.
///
/// </summary>

class GameManager : public entityx::Receiver<GameManager>
{
public:
	
	GameManager(entityx::EntityManager& entityManager,
		entityx::EventManager& eventManager);
	
	void init();

	GameState getGameState() const;

	bool isRunning() const;

	// For each call to subscribe in GameManager::init(), there must be a corresponding receive
	//  for that event type
	void receive(const EvStartGame& startGame);


private:

	entityx::EntityManager& m_entityManager;

	entityx::EventManager& m_eventManager;

	/// <summary>
	/// The current game state.
	/// </summary>
	GameState m_gameState;

	/// <summary>
	/// The current game level.
	/// </summary>
	int m_currentLevel;

	/// <summary>
	/// The game running status - true if the game is running.
	/// </summary>
	bool m_isRunning;
};
