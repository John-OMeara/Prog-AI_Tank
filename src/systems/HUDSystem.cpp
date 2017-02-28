#include "systems/HUDSystem.h"

HUDSystem::HUDSystem(entityx::EntityManager& entities, sf::RenderWindow& window)
	: m_window(window)
{
	if (!m_font.loadFromFile("./resources/fonts/akashi.ttf"))
	{
		std::cout << "Problem loading font file" << std::endl;
	}

	m_lapCounter.setFont(m_font);
	m_lapCounter.setPosition(sf::Vector2f(0, 0));
}

void HUDSystem::configure(entityx::EventManager& events)
{
	//events.subscribe<EvReportPlayerId>(*this);
}

void HUDSystem::receive(const EvReportPlayerId & e)
{
	//m_playerId = e.m_playerId;
}

void HUDSystem::update(entityx::EntityManager & entities, entityx::EventManager & events, double dt)
{
	m_lapCounter.setString("Current Lap: ");

	m_window.draw(m_lapCounter); 
}
