#pragma once

#include "entityx/System.h"
#include "entityx/Event.h"
#include "systems/Events.h"
#include "utils/LevelLoader.h"
#include "EntityCreator.h"
#include "ScreenSize.h"

/// <summary>
/// @Author Ross Palmer
/// @Version 1.0
/// @brief A system to manage loading the level data.
///
/// </summary>
class LevelSystem
      : public entityx::System<LevelSystem>
      , public entityx::Receiver<EvInit>
{
public:
   /// <summary>
   /// ...
   /// </summary>
   /// <param name="entities">The EntityX entity manager</param>
   /// <param name="eventManager">The EntityX event manager</param>
   LevelSystem(entityx::EntityManager& entities,
               entityx::EventManager& eventManager);

   /// <summary>
   /// Configures this level system by listening for game initialise events.
   /// </summary>
   /// <param name="eventManager">The EntityX event manager</param>
   void configure(entityx::EventManager& eventManager) override;

   void update(entityx::EntityManager& entities,
               entityx::EventManager& events,
               double dt) override;

   /// <summary>
   /// Loads level data and creates the game background entity.
   /// </summary>
   /// <param name="e">A game initialise event</param>
   void receive(const EvInit& e);

private:
 
   entityx::EntityManager& m_entityManager;

   entityx::EventManager& m_eventManager;

};
