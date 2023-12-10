#pragma once

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <fstream>
#include "Player.h"

class DataManager
{
public:
	void SaveData(PlayerData* playerData);
	PlayerData LoadData();
};
#endif // FILEMANAGER_H
