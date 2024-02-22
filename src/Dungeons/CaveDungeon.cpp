//
// Cave Dungeon Implementation

#include "Dungeon Headers/CaveDungeon.h"
#include "Item Headers/Items.h"
#include "Enemy Headers/Enemies.h"
#include "Duel.h"
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


bool CaveDungeon::StartDungeon(PlayerObj *player)
{
	system("CLS"); // Clear console (Slow)
	std::cout << "Welcome to the CAVE DUNGEON!\n\n";
	Sleep(2500);

	this->player = player;
	Duel* duel;

	switch(dungeonDifficulty)
	{
		case Easy:
		{
			Item coins = Coin(3);
			SkeletonEnemy* enemy = new SkeletonEnemy("Skeleton",10, 1, coins);

			duel = new Duel(player, enemy);
			duel->StartDuel();

			if (duel->playerWon == false && duel->enemyWon == false)
			{
				EndDungeon();
			}
			else if (duel->playerWon == true && duel->enemyWon == false)
			{
				player->AddItem(enemy->Die());
				EndDungeon();
			}
			else // Assume enemy won
			{
				player->PlayerDied();
				EndDungeon();
				return false;
			}
			break;
		}
		case Medium:
		{
			Item coins = Coin(5);
			SkeletonEnemy* enemy = new SkeletonEnemy("Skeleton", 15, 2, coins);

			duel = new Duel(player, enemy);
			duel->StartDuel();

			if (duel->playerWon)
			{
				player->AddItem(enemy->Die());
				EndDungeon();
			}
			else // Assume enemy won
			{
				player->PlayerDied();
				return false;
			}
			break;
		}	
		case Hard:
		{
			Item coins = Coin(10);
			SkeletonEnemy* enemy = new SkeletonEnemy("Skeleton", 20, 4, coins);

			duel = new Duel(player, enemy);
			duel->StartDuel();

			if (duel->playerWon)
			{
				player->AddItem(enemy->Die());
				EndDungeon();
			}
			else // Assume enemy won
			{
				player->PlayerDied();
				return false;
			}
			break;
		}
		default:
			break;
	}

	Sleep(2500);
	return true; // Player survived
}

bool CaveDungeon::EndDungeon()
{
	return (player->GetHealth() <= 0) ? true : false;
}
