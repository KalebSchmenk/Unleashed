//
// Base Dungeon Implementation

#include "Dungeon Headers/Dungeon.h"


DungeonDifficulty Dungeon::GetDifficulty() 
{
	return dungeonDifficulty;
}

bool Dungeon::StartDungeon(PlayerObj *player)
{
	throw std::invalid_argument("Base class used instead of derivitive to generate dungeon");
}

bool Dungeon::EndDungeon()
{
	return true;
}

void Dungeon::SelectDifficulty()
{
	std::cout << "What difficulty do you want this dungeon?\n\n";

	std::cout << "Options:\n";
	std::cout << "1. Easy\n";
	std::cout << "2. Medium\n";
	std::cout << "3. Hard\n\n";

	int selection;

	std::cin >> selection;

	this->dungeonDifficulty = (DungeonDifficulty)selection;
}