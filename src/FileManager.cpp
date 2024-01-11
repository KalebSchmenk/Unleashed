//
// Player data file manager implementation

#include "FileManager.h"


// Data write and read
std::fstream f;

// Saves player data to .dat file
void DataManager::SaveData(PlayerData* playerData)
{
	// Write
	f.open("playerData.dat", std::ios::out);
	if (f)
	{
		f << playerData->playerName << std::endl;
		f << playerData->playerHealth << std::endl;
		f << playerData->playerLevel << std::endl;

		// Close
		f.close();
	}
	else
	{
		throw std::invalid_argument("Couldn't open a new file");	
	}
}

// Deletes player .dat data file
int DataManager::DeleteData()
{
	try
	{
		std::remove("playerData.dat");
		return 1;
	}
	catch (...)
	{
		return 0;
	}
}

// Loads data
PlayerData DataManager::LoadData()
{
	PlayerData readInData;
	readInData.playerHealth = -1;
	readInData.playerName = "empty";

	// Read
	f.open("playerData.dat", std::ios::in);
	if (f)
	{
		// Research into serialization was fruitless so far
		// The idea is that we iterate over every line and assign the data to the correct memory location-
		// -based on what iteration (line) we are on in the file
		// 
		// Hard coded for data formatted as follows:
		// Line 1: Player Name
		// Line 2: Player Health
		// Line 3: Player Level

		int i = 0;
		std::string s;
		while (f)
		{
			std::getline(f, s);

			if (s.compare("") == 0) break;

			switch (i)
			{
				case 0:
				{
					readInData.playerName = s;
					break;
				}
				case 1:
				{
					readInData.playerHealth = stoi(s);
					break;
				}
				case 2:
				{
					readInData.playerLevel = stoi(s);
					break;
				}
			}
			i++;
		}
		// Close
		f.close();
	}
	else
	{
		throw std::invalid_argument("No data file found");
	}

	// If the name or health are invalid arguments, default to these values.
	// Does it have to be a try catch? No, but it's interesting to have this be considered an exception
	try
	{
		if (readInData.playerName.compare("") == 0) throw std::invalid_argument("Name was empty");
	}
	catch (const std::invalid_argument& e)
	{
		readInData.playerName = "Phoenix";
	}
	
	try
	{
		if (readInData.playerHealth == -1) throw std::invalid_argument("Health was never overriden");
	}
	catch (const std::invalid_argument& e)
	{
		readInData.playerHealth = 15;
	}

	return readInData;
}


