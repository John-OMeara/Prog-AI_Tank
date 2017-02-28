#include "systems/MovementSystem.h"

double MovementSystem::DEG_TO_RAD = thor::Pi / 180.0f;

MovementSystem::MovementSystem() 
{
}


void MovementSystem::update(entityx::EntityManager &entities,
							entityx::EventManager &events,
                            double dt)
{
   Motion::Handle motion;
   Position::Handle position;

   for (entityx::Entity entity : entities.entities_with_components(motion, position))
   {	 	  	 
	  
		sf::Vector2f newPos(position->m_position.x + std::cos(DEG_TO_RAD  * position->m_rotation) * motion->m_speed * (dt / 1000),
			   position->m_position.y + std::sin(DEG_TO_RAD  * position->m_rotation) * motion->m_speed * (dt / 1000));
	
		if (!isOnScreen(newPos, entity))		 
		{			  			
			motion->m_speed = 0;
			continue;
		}
		position->m_position.x = newPos.x;
		position->m_position.y = newPos.y;		
   }


   Parent::Handle parent;
   for (entityx::Entity entity : entities.entities_with_components(position, parent))
   {
	   // Retrieve the Position component from the parent entity
	   // Note the variable parent is a component, it has a member variable called m_parentEntity which is a 
	   //  reference to the tank entity (i.e. m_parentEntity).
	   Position::Handle parentPosition = parent->m_parentEntity.component<Position>();
	   position->m_position.x = parentPosition->m_position.x;
	   position->m_position.y = parentPosition->m_position.y;	   
   }
}

bool MovementSystem::isOnScreen(sf::Vector2f position, entityx::Entity& entity) const
{
    auto hitBox  = entity.component<Volume>()->m_box.getRect();

    return position.x - hitBox.width/2 > 0.f
    && position.x + hitBox.width/2 < ScreenSize().width()
    && position.y - hitBox.height/2 > 0.f
    && position.y + hitBox.height/2 < ScreenSize().height();
}



