#pragma once

#include "entityx/System.h"
#include "systems/Events.h"
#include "components/PlayerControl.h"
#include "components/Motion.h"
#include "components/Position.h"
#include "components/Turret.h"
#include "KeyHandler.h"
#include <SFML/System/Vector2.hpp>

class KeyHandler;

class PlayerControlSystem : public entityx::System<PlayerControlSystem>
{
public:

   PlayerControlSystem(const KeyHandler& keyHandler);

   void update(entityx::EntityManager &entities,
               entityx::EventManager &events,
               double dt);

private:

   const KeyHandler& m_keyHandler;
};

