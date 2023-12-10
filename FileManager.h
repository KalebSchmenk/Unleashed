#pragma once

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include "Player.h"

class DataManager
{
public:
	void SaveData(PlayerData* playerData);
	PlayerData LoadData();
};
#endif // FILEMANAGER_H
