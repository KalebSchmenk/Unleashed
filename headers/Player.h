#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

struct PlayerData
{
	std::string playerName = "                               ";
	int playerHealth = 5;
	int playerLevel = 1;

	~PlayerData()
	{
		playerName = "";
	}
};

class PlayerObj
{
public:
	std::string GetName();
	int GetHealth();
	int GetLevel();
	PlayerData GetPlayerData();
	
	int SetPlayerData(PlayerData newData);
	void SetName(std::string nameToSet);
	void SetHealth(int newHealth);
	void LevelUp();

	PlayerObj(std::string name, int startHealth);
	PlayerObj();

private:
	PlayerData playerData; // Player's current data as a struct
};
#endif // PLAYER_H