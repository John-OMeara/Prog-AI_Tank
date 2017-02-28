#pragma once

#include "entityx/Entity.h"

enum class WallType
{
	WT_Small,
};

struct Wall : public entityx::Component<Wall>
{
   Wall(WallType type = WallType::WT_Small);

   WallType m_type;
};

