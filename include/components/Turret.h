#pragma once

#include "entityx/Entity.h"
#include <SFML/System/Vector2.hpp>


struct Turret : public entityx::Component<Turret>
{
   Turret();
   
   Turret(const double rotation, 
	      int maxProjectiles, 
	      double shootTimer,
	      int const reloadTime,
          bool isFirePressed);

   double m_rotation;

   int m_maxProjectiles;

   double m_shootTimer;

   int const m_reloadTime;

   bool m_isFirePressed;

   static double s_rotationIncrement;
};

