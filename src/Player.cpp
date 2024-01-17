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
PlayerData* PlayerObj::GetPlayerData()
{
	return &playerData;
}
int PlayerObj::GetLevel()
{
	return playerData.playerLevel;
}
std::vector<Item>* PlayerObj::GetItems()
{
	return playerData.ItemList;
}

void PlayerObj::SetHealth(int newHealth)
{
	playerData.playerHealth = newHealth;
}
void PlayerObj::SetName(std::string newName)
{
	playerData.playerName = newName;
}
void PlayerObj::AddItem(Item newItem)
{
	auto itemList = playerData.ItemList;
	itemList->push_back(newItem);
}
void PlayerObj::PrintItems()
{
	// i love c++ <3
	std::vector<Item> itemList = *(playerData.ItemList);
	int size = itemList.size();

	std::cout << "\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << itemList[i].GetItemName() << " : " << itemList[i].GetItemCount() << "\n";
	}
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


