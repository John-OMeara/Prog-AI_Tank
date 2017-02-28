#include "components/Ai.h"

Ai::Ai()
: m_aiType(TankAi::AiType::AI_ID_NONE)
{
}

Ai::Ai(TankAi::AiType aiType, entityx::Entity::Id id)
 : m_aiType(aiType)
 , m_id(id)
{
}
