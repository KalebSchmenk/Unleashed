#pragma once

#ifndef CAVE_DUNGEON_H
#define CAVE_DUNGEON_H

#include "Player.h"
#include "Dungeon.h"
#include <stdlib.h>
#include <iostream>

class CaveDungeon : public Dungeon
{
public:
	DungeonDifficulty GetDifficulty() override;
	void StartDungeon(PlayerObj *player) override;

	CaveDungeon(DungeonDifficulty difficulty);

private:
	DungeonDifficulty dungeonDifficulty;
};
#endif // CAVE_DUNGEON_H