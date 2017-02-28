#pragma once

#include "entityx/Entity.h"
#include <SFML/System/Vector2.hpp>

/// <summary>
/// @Author Ross Palmer
/// @Version 1.0
/// @brief A component to represent a 2D position and a heading.
///
/// </summary>
struct Position : public entityx::Component<Position>
{
   Position();

   /// <summary>
   /// Construct this position from the specified argument.
   /// </summary>
   /// <param name="position">An SFML Vector2f</param>
   Position(const sf::Vector2f& position);

   /// <summary>
   /// Construct this position from the specified arguments.
   /// </summary>
   /// <param name="position">An SFML Vector2f</param>
   /// <param name="rotation">A rotation angle in degrees</param>
   Position(const sf::Vector2f& position, double rotation);

   /// <summary>
   /// The screen position.
   /// </summary>
   sf::Vector2f m_position;

   /// <summary>
   /// The rotation in degrees.
   /// </summary>
   double m_rotation;
};

