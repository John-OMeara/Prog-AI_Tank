#include "EntityCreator.h"


BackgroundCreator::BackgroundCreator(const std::string& fileName)
	: m_fileName(fileName)
{
}

void BackgroundCreator::create(entityx::Entity& entity)
{
	entity.assign<Position>();
	entity.assign<Background>();
}

TankBaseCreator::TankBaseCreator(sf::Vector2f position, bool isAi)
: m_position(position)
, m_isAi(isAi)
{
}

void TankBaseCreator::create(entityx::Entity& entity)
{
	auto volume = Volume();
	volume.m_box = CollisionBox(80, 43);	
	entity.assign<Tank>(entity.id());	
	entity.assign<Motion>(0);
	entity.assign<Position>(m_position, 0.0);
	entity.assign<Volume>(volume);		
	if (m_isAi)
	{
		// Add these...
		entity.assign<Display>(sf::IntRect(103, 43, 79, 43));
		entity.assign<Ai>(TankAi::AiType::AI_ID_SEEK_SHOOT_AT_PLAYER, entity.id());
	}
	else
	{
		entity.assign<PlayerControl>();
		entity.assign<Display>(sf::IntRect(2, 43, 79, 43));
	}
}

TurretCreator::TurretCreator(TankData const& tankData, 
	                         entityx::Entity& parentEntity,
	                         bool isAi)
: m_tankData(tankData)
, m_parentEntity(parentEntity)
, m_isAi(isAi)
{
}

void TurretCreator::create(entityx::Entity& entity)
{
	auto volume = Volume();
	volume.m_box = CollisionBox(81, 30);	

	entity.assign<Turret>(0.0, m_tankData.m_maxProjectiles, 0.0, m_tankData.m_reloadTime, false);
	entity.assign<Motion>(0);	
	entity.assign<Position>(sf::Vector2f(m_tankData.m_position.x, m_tankData.m_position.y), 0.0);
	entity.assign<Volume>(volume);
	
	entity.assign<Parent>(m_parentEntity);	
	// Solution for Turret problem here:
	// http://gamedev.stackexchange.com/questions/31888/in-an-entity-component-system-engine-how-do-i-deal-with-groups-of-dependent-ent
	if (m_isAi)
	{
		// Add these...
		entity.assign<Display>(sf::IntRect(122, 1, 83, 31));
		entity.assign<Ai>(TankAi::AiType::AI_ID_SEEK_SHOOT_AT_PLAYER, entity.id());
	}
	else
	{
		entity.assign<PlayerControl>();
		entity.assign<Display>(sf::IntRect(19, 1, 83, 31)); 	
	}
}

WallCreator::WallCreator(std::string type,
	sf::Vector2f position,
	double rotation)

	: m_type(type)
	, m_position(position)
	, m_rotation(rotation)
{
}

NodeCreator::NodeCreator(sf::Vector2f position) :
	m_position(position)
{
}

void WallCreator::create(entityx::Entity& entity)
{
	auto volume = Volume();
	volume.m_box = CollisionBox(33, 23);

	entity.assign<Volume>(volume);
	entity.assign<Display>(sf::IntRect(2, 129, 33, 23));
	entity.assign<Position>(m_position, m_rotation);
	entity.assign<Wall>();
}

void NodeCreator::create(entityx::Entity& entity)
{
	auto volume = Volume();
	volume.m_box = CollisionBox(60, 60);

	entity.assign<Volume>(volume);
	entity.assign<Display>(sf::IntRect(2, 129, 33, 23));
	entity.assign<Position>(m_position);
	entity.assign<Node>();
}