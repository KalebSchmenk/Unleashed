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


void PlayerObj::SetHealth(int newHealth)
{
	playerData.playerHealth = newHealth;
}

void PlayerObj::SetName(std::string newName)
{
	playerData.playerName = newName;
}

int PlayerObj::AddItem(Item newItem)
{
	// I love the lengths I have to go to keep the ability
	// To save and load files
	if (!playerData.itemSlotOne.IsValid())
	{
		playerData.itemSlotOne = newItem;
		return 1;
	}
	else if (!playerData.itemSlotTwo.IsValid())
	{
		playerData.itemSlotTwo = newItem;
		return 1;
	}
	else if (!playerData.itemSlotThree.IsValid())
	{
		playerData.itemSlotThree = newItem;
		return 1;
	}
	else if (!playerData.itemSlotFour.IsValid())
	{
		playerData.itemSlotFour = newItem;
		return 1;
	}
	else if (!playerData.itemSlotFive.IsValid())
	{
		playerData.itemSlotFive = newItem;
		return 1;
	}
	else if (!playerData.itemSlotSix.IsValid())
	{
		playerData.itemSlotSix = newItem;
		return 1;
	}
	else
	{
		return 0; // No slot available
	}
}

int PlayerObj::RemoveItem(int index)
{
	Item item;

	switch (index)
	{
		case 1:
		{
			playerData.itemSlotOne = item;
			return 1;
		}
		case 2:
		{
			playerData.itemSlotTwo = item;
			return 1;
		}
		case 3:
		{
			playerData.itemSlotThree = item;
			return 1;
		}
		case 4:
		{
			playerData.itemSlotFour = item;
			return 1;
		}
		case 5:
		{
			playerData.itemSlotFive = item;
			return 1;
		}
		case 6:
		{
			playerData.itemSlotSix = item;
			return 1;
		}
		default:
		{
			return 0; // No slot deleted
		}
	}
	return 0; // No slot deleted
}

void PlayerObj::PrintItems()
{
	std::cout << "Current Sword : " << playerData.playerSword.GetItemName() << "\n";
	std::cout << "Gold Count : " << playerData.coins.GetItemCount() << "\n\n";

	std::cout << "Current Items" << "\n";
	bool foundAtLeastOneItem = false;
	if (playerData.itemSlotOne.IsValid())
	{
		foundAtLeastOneItem = true;
		std::cout << playerData.itemSlotOne.GetItemName() << " : " << playerData.itemSlotOne.GetItemCount() << "\n";
	}
	if (playerData.itemSlotTwo.IsValid())
	{
		foundAtLeastOneItem = true;
		std::cout << playerData.itemSlotTwo.GetItemName() << " : " << playerData.itemSlotTwo.GetItemCount() << "\n";
	}
	if (playerData.itemSlotThree.IsValid())
	{
		foundAtLeastOneItem = true;
		std::cout << playerData.itemSlotThree.GetItemName() << " : " << playerData.itemSlotThree.GetItemCount() << "\n";
	}
	if (playerData.itemSlotFour.IsValid())
	{
		foundAtLeastOneItem = true;
		std::cout << playerData.itemSlotFour.GetItemName() << " : " << playerData.itemSlotFour.GetItemCount() << "\n";
	}
	if (playerData.itemSlotFive.IsValid())
	{
		foundAtLeastOneItem = true;
		std::cout << playerData.itemSlotFive.GetItemName() << " : " << playerData.itemSlotFive.GetItemCount() << "\n";
	}
	if (playerData.itemSlotSix.IsValid())
	{
		foundAtLeastOneItem = true;
		std::cout << playerData.itemSlotSix.GetItemName() << " : " << playerData.itemSlotSix.GetItemCount() << "\n";
	}

	if (!foundAtLeastOneItem) std::cout << "\nYou have not found any items yet!\n";
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

// When the player dies
void PlayerObj::PlayerDied()
{
	PlayerData newPlayerData;
	playerData = newPlayerData;
}