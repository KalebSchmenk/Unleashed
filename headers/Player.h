#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

struct PlayerData
{
	std::string playerName;
	int playerHealth = 5;
};

class PlayerObj
{
public:
	std::string GetName();
	int GetHealth();
	PlayerData GetPlayerData();
	
	int SetPlayerData(PlayerData newData);
	void SetName(std::string nameToSet);
	void SetHealth(int newHealth);

	PlayerObj(std::string name, int startHealth);
	PlayerObj();

private:
	PlayerData playerData; // Player's current data as a struct
};
#endif // PLAYER_H