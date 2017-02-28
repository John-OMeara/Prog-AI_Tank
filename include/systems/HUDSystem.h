#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "entityx/System.h"
#include "entityx/Event.h"
#include "systems/Events.h"

class HUDSystem
	: public entityx::System<HUDSystem>
	, public entityx::Receiver<HUDSystem>
{
public:
	HUDSystem(entityx::EntityManager& entities, sf::RenderWindow& window);

	void configure(entityx::EventManager& events);
	void receive(const EvReportPlayerId& e);
	void update(entityx::EntityManager& entities,
				entityx::EventManager& events,
				double dt);

private:
	//entityx::Entity::Id m_playerId;

	sf::Font m_font;

	sf::RenderWindow& m_window;

	sf::Text m_lapCounter;
};