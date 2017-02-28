#pragma once

#include "entityx/Entity.h"
#include <SFML/System/Vector2.hpp>


struct Motion : public entityx::Component<Motion>
{
   Motion();

   Motion(const float speed);

   float m_speed;

};

