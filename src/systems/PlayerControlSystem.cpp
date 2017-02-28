#include "systems/PlayerControlSystem.h"
#include <iostream>

using namespace entityx;

PlayerControlSystem::PlayerControlSystem(const KeyHandler& keyHandler)
: m_keyHandler(keyHandler)
{ 
}


void PlayerControlSystem::update(EntityManager &entities,
                                 EventManager &events,
                                 double dt)
{
  
   PlayerControl::Handle playerControl;
   Motion::Handle motion;   
   Position::Handle position;
 
   for (Entity entity : entities.entities_with_components(playerControl, motion, position))
   {
      if (m_keyHandler.isPressed(playerControl->m_right)
              || m_keyHandler.isPressed(playerControl->m_altRight))
      {		 
		  position->m_rotation += 1;
		  if (position->m_rotation == 360.0)
		  {
			  position->m_rotation = 0;
		  }
      }
      else if (m_keyHandler.isPressed(playerControl->m_left)
               || m_keyHandler.isPressed(playerControl->m_altLeft))
      {		
		  position->m_rotation -= 1;
		  if (position->m_rotation == 0.0)
		  {
			  position->m_rotation = 359.0;
		  }		  
      }
   
	  if (m_keyHandler.isPressed(playerControl->m_up)
	      || m_keyHandler.isPressed(playerControl->m_altUp))
	  {
		  if (motion->m_speed < 100)
		  {
			  motion->m_speed += 1;
		  }
	  }
	  else if (m_keyHandler.isPressed(playerControl->m_down)
	           || m_keyHandler.isPressed(playerControl->m_altDown))
	  {
		  if (motion->m_speed > -100)
		  {
			  motion->m_speed -= 1;
		  }
	
	  }

	  if (entity.has_component<Turret>())
	  {
		  Turret::Handle turret = entity.component<Turret>();
		  turret->m_isFirePressed = m_keyHandler.isPressed(playerControl->m_shoot);

		  if (m_keyHandler.isPressed(playerControl->m_turretLeft))
		  {
			  position->m_rotation += 1;
			  if (position->m_rotation == 360.0)
			  {
				  position->m_rotation = 0;
			  }
		  }
		  else if (m_keyHandler.isPressed(playerControl->m_turretRight))
		  {
			  position->m_rotation -= 1;
			  if (position->m_rotation == 0.0)
			  {
				  position->m_rotation = 359.0;
			  }
		  }		
	  }
   }
}
