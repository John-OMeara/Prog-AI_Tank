#pragma once

#include "entityx/System.h"
#include "entityx/Event.h"
#include "systems/Events.h"

class HUDSystem
	: public entityx::System<HUDSystem>
	, public entityx::Receiver<HUDSystem>
{
public:
	HUDSystem();

private:

};