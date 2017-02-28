#pragma once

#include "entityx/System.h"
#include "systems/Events.h"
#include <SFML/System/Vector2.hpp>
#include "components/Motion.h"
#include "components/Position.h"
#include "components/Parent.h"
#include <Thor/Math.hpp>
#include "components/Volume.h"
#include "ScreenSize.h"


class MovementSystem : public entityx::System<MovementSystem>
{
public:

   MovementSystem();

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:   
    
	bool isOnScreen(sf::Vector2f newPos, entityx::Entity &entity) const;
	
	static double DEG_TO_RAD;		
};

