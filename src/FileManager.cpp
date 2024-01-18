//
// Player data file manager implementation

#include "FileManager.h"


// Saves player data to .dat file
void DataManager::SaveData(PlayerData* playerData)
{
	std::fstream f;
	std::vector<Item> items = *playerData->ItemList;

	f.open("Items.txt", std::ios::app);

	if (f)
	{
		for (auto item : items)
		{
			f.write((char*)&item, sizeof(item));
			f << std::endl;
		}
		f.close();
	}
	else
	{
		std::cout << "Die. SaveData failed for items";
	}


	f.open("PlayerDataFile.txt", std::ios::app);
	
	if (f)
	{
		playerData->ItemList = new std::vector<Item>;

		f.write((char*)playerData, sizeof(*playerData));

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
		std::remove("PlayerDataFile.txt");
		return 1;
	}
	catch (...)
	{
		return 0;
	}
}

// Loads data
void DataManager::LoadData(PlayerData* data)
{
	std::fstream f;

	f.open("PlayerDataFile.txt", std::ios::in);

	if(f)
	{
		f.seekg(0);
		f.read((char*)data, sizeof(*data));
		f.close();
	}
	else
	{
		throw std::invalid_argument("No data file found");
	}

	f.open("Items.txt", std::ios::in);

	if (f)
	{
		f.seekg(0);
		std::string line;
		while (std::getline(f, line))
		{
			std::fstream noShot;

			noShot.open("temp.txt", std::ios::app);

			if (f)
			{
				noShot << line.c_str();
			}

			Item* item = new Item;

			noShot.read((char*)item, sizeof(*item));
			noShot.close();

			data->ItemList->push_back(*item);

			delete item;
		}
	}
	else
	{
		throw std::invalid_argument("No items file found");
	}


	// If the name or health are invalid arguments, default to these values.
	// Does it have to be a try catch? No, but it's interesting to have this be considered an exception
	try
	{
		if (data->playerName.compare("") == 0) throw std::invalid_argument("Name was empty");
	}
	catch (const std::invalid_argument& e)
	{
		data->playerName = "Phoenix";
	}
	try
	{
		if (data->playerHealth == -1) throw std::invalid_argument("Health was never overriden");
	}
	catch (const std::invalid_argument& e)
	{
		data->playerHealth = 15;
	}
}


