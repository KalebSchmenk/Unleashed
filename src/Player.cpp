//
// Player Implementation

#include "Player.h"

// Data struct
struct PlayerData playerData;


// Player constructor
PlayerObj::PlayerObj(std::string name, int health)
{
	playerData.playerHealth = health;
	playerData.playerName = name;
}

PlayerObj::PlayerObj()
{
	playerData.playerName = "Phoenix";
	playerData.playerHealth = -1;
}

// Getters and Setters
int PlayerObj::GetHealth()
{
	return playerData.playerHealth;
}
std::string PlayerObj::GetName() 
{
	return playerData.playerName;
}
PlayerData PlayerObj::GetPlayerData()
{
	return playerData;
}
int PlayerObj::GetLevel()
{
	return playerData.playerLevel;
}

void PlayerObj::SetHealth(int newHealth)
{
	playerData.playerHealth = newHealth;
}
void PlayerObj::SetName(std::string newName)
{
	playerData.playerName = newName;
}
int PlayerObj::SetPlayerData(PlayerData newData)
{
	try
	{
		playerData = newData;
		return 1;
	}
	catch(...) 
	{
		return 0;
	}
}

// Levels up player by 1. No paramater to ensure linear progression
void PlayerObj::LevelUp()
{
	playerData.playerLevel++;
}


