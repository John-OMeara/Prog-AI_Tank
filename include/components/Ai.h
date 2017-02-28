#pragma once

#include "entityx/Entity.h"
#pragma once

#include "ai/TankAi.h"

struct Ai : public entityx::Component<Ai>
{  
   Ai();

   Ai(TankAi::AiType aiType, entityx::Entity::Id id);

   entityx::Entity::Id m_id;

   TankAi::AiType m_aiType;
};

