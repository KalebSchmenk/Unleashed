//
// Base Dungeon Implementation

#include "Dungeon.h"


DungeonDifficulty dungeonDifficulty; // Dungeon difficulty


// Constructor
Dungeon::Dungeon(DungeonDifficulty difficulty)
{
	dungeonDifficulty = difficulty;
}
Dungeon::Dungeon()
{
	//throw std::invalid_argument("Dungeon needs to be passed a difficulty");
}

DungeonDifficulty Dungeon::GetDifficulty() 
{
	return dungeonDifficulty;
}


void Dungeon::StartDungeon(PlayerObj *player)
{
	throw std::invalid_argument("Base class used instead of derivitive to generate dungeon");
}