#pragma once

#include "entityx/Entity.h"
#include <SFML/System/Vector2.hpp>

struct Parent : public entityx::Component<Parent>
{
	// Note: Passing the Entity here by reference will break the MovementSystem (where the parent is retrieved).
	Parent(entityx::Entity parentEntity);

	/// <summary>
	/// A reference to the parent of this entity.
	/// </summary>
	entityx::Entity m_parentEntity;
};

