#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Item Headers/Items.h"

struct PlayerData
{
	std::string playerName = "default";
	int playerHealth = -1;
	int playerLevel = -1;
	std::vector<Item>* ItemList = new std::vector<Item>;
};

class PlayerObj
{
public:
	std::string GetName();
	int GetHealth();
	int GetLevel();
	std::vector<Item>* GetItems();
	PlayerData* GetPlayerData();
	
	int SetPlayerData(PlayerData newData);
	void SetName(std::string nameToSet);
	void SetHealth(int newHealth);
	void AddItem(Item newItem);
	void PrintItems();
	void LevelUp();

	PlayerObj(std::string name, int startHealth);
	PlayerObj();

private:
	PlayerData playerData; // Player's current data as a struct
};
#endif // PLAYER_H