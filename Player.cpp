//
//
// Player Implementation

#include "Player.h"

// Data
std::string name = "";
int health;
//--------------------


// Data struct
struct PlayerData playerData;


// Player constructor
PlayerObj::PlayerObj(std::string name, int health)
{
	this->name = name;
	this->health = health;

	playerData.playerHealth = health;
	playerData.playerName = name;
}

// Getters and Setters
int PlayerObj::GetHealth()
{
	return health;
}
std::string PlayerObj::GetName() 
{
	return name;
}
PlayerData PlayerObj::GetPlayerData()
{
	return playerData;
}

void PlayerObj::SetHealth(int newHealth)
{
	health = newHealth;
}
void PlayerObj::SetName(std::string newName)
{
	name = newName;
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


