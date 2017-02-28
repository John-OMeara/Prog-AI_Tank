#include "components/Turret.h"

double Turret::s_rotationIncrement = 0.1;

Turret::Turret()
: m_rotation(0.0)
, m_maxProjectiles(0)
, m_shootTimer(0)
, m_reloadTime(0)
, m_isFirePressed(false)
{
}

Turret::Turret(const double rotation, 
	           int maxProjectiles, 
	           double shootTimer,
	           int const reloadTime,
	           bool isFirePressed)
: m_rotation(rotation)
, m_maxProjectiles(maxProjectiles)
, m_shootTimer(shootTimer)
, m_reloadTime(reloadTime)
, m_isFirePressed(false)
{
}
