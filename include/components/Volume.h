#pragma once

#include "entityx/Entity.h"
#include "utils/CollisionBox.h"

struct Volume : public entityx::Component<Volume>
{
   Volume();

   CollisionBox m_box;
};

