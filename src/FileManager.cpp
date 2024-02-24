//
// Player data file manager implementation

#include "FileManager.h"
#include <filesystem>


// Saves player data to .dat file
void DataManager::SaveData(PlayerData& data)
{
	data.playerSword.SaveItem();
	data.itemSlotOne.SaveItem();
	data.itemSlotTwo.SaveItem();
	data.itemSlotThree.SaveItem();
	data.itemSlotFour.SaveItem();
	data.itemSlotFive.SaveItem();
	data.itemSlotSix.SaveItem();



	const PlayerData newData = data;

	std::ofstream outputFile("PlayerDataFile.txt", std::ios::binary);

	if (!outputFile.is_open())
	{
		std::cerr << "Error opening file for writing: " << "PlayerDataFile.txt" << std::endl;
		return;
	}

	// Write the PlayerData struct to the file
	outputFile.write(reinterpret_cast<const char*>(&newData), sizeof(PlayerData));

	outputFile.close();

	



	//std::fstream f;

	//// If a file exists delete it, we are overriding it
	//if (std::filesystem::exists("PlayerDataFile.txt"))
	//{
	//	DeleteData();
	//}

	//f.open("PlayerDataFile.txt", std::ios::app);
	//
	//if (f)
	//{
	//	f.write((char*)playerData, sizeof(*playerData));

	//	f.close();
	//}
	//else
	//{
	//	throw std::invalid_argument("Couldn't open a new file");
	//}
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
void DataManager::LoadData(PlayerData& data)
{
	std::ifstream inputFile("PlayerDataFile.txt", std::ios::binary);

	if (!inputFile.is_open())
	{
		//std::cerr << "Error opening file for reading: " << "PlayerDataFile.txt" << std::endl;
		throw std::invalid_argument("No data file found");

		return;
	}

	// Read the PlayerData struct from the file
	inputFile.read(reinterpret_cast<char*>(&data), sizeof(PlayerData));

	inputFile.close();

	// wow
	Item* sword = data.playerSword.LoadItem();
	Sword* newSword = dynamic_cast<Sword*>(sword);
	data.playerSword = *newSword;

	data.itemSlotOne = *data.itemSlotOne.LoadItem();
	data.itemSlotTwo = *data.itemSlotTwo.LoadItem();
	data.itemSlotThree = *data.itemSlotThree.LoadItem();
	data.itemSlotFour = *data.itemSlotFour.LoadItem();
	data.itemSlotFive = *data.itemSlotFive.LoadItem();
	data.itemSlotSix = *data.itemSlotSix.LoadItem();






	//std::fstream f;

	/*f.open("PlayerDataFile.txt", std::ios::in);

	if(f)
	{
		f.seekg(0);
		f.read((char*)data, sizeof(*data));
		f.close();
	}
	else
	{
		throw std::invalid_argument("No data file found");
	}*/


	// If the name or health are invalid arguments, default to these values.
	// Does it have to be a try catch? No, but it's interesting to have this be considered an exception
	try
	{
		if (data.playerName.compare("") == 0) throw std::invalid_argument("Name was empty");
	}
	catch (const std::invalid_argument& e)
	{
		data.playerName = "Phoenix";
	}
	try
	{
		if (data.playerHealth == -1) throw std::invalid_argument("Health was never overriden");
	}
	catch (const std::invalid_argument& e)
	{
		data.playerHealth = 15;
	}
}


