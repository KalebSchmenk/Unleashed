//
// Cave Dungeon Implementation

#include "Dungeon Headers/CaveDungeon.h"
#include <windows.h>


// Constructor
CaveDungeon::CaveDungeon(DungeonDifficulty difficulty)
{
	dungeonDifficulty = difficulty;
}

DungeonDifficulty CaveDungeon::GetDifficulty()
{
	return dungeonDifficulty;
}


void CaveDungeon::StartDungeon(PlayerObj *player)
{
	system("CLS"); // Clear console (Slow)
	std::cout << "\n\nWelcome to the CAVE DUNGEON!\n\n";

	// lol
	switch(dungeonDifficulty)
	{
		case Easy:
			std::cout << "\n\nYou're difficulty level is: EASY\n\n";
			std::cout << "YOU TOOK 1 DAMAGE!\n\n";
			player->SetHealth(player->GetHealth() - 11);
			break;
		case Medium:
			std::cout << "\n\nYou're difficulty level is: MEDIUM\n\n";
			std::cout << "YOU TOOK 5 DAMAGE!\n\n";
			player->SetHealth(player->GetHealth() - 5);
			break;
		case Hard:
			std::cout << "\n\nYou're difficulty level is: HARD\n\n";
			std::cout << "YOU TOOK 10 DAMAGE!\n\n";
			player->SetHealth(player->GetHealth() - 10);
			break;
		default:
			break;
	}

	Sleep(5000);
}
