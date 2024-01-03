#pragma once

#ifndef DUNGEON_GENERATOR_H
#define DUNGEON_GENERATOR_H

#include "Player.h"
#include <stdexcept>

static enum DungeonDifficulty
{
	Easy,
	Medium,
	Hard
};

class Dungeon
{
public:	
	virtual DungeonDifficulty GetDifficulty();
	virtual void StartDungeon(PlayerObj *player);

	Dungeon(DungeonDifficulty difficulty);
	Dungeon();

private:
	DungeonDifficulty dungeonDifficulty;
};
#endif // DUNGEON_GENERATOR_H