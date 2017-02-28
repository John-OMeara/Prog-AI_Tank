#pragma once

#include "entityx/Entity.h"
#include "utils/CollisionBox.h"

struct Tank : public entityx::Component<Tank>
{
   Tank(entityx::Entity::Id id);

   entityx::Entity::Id m_id;
};


