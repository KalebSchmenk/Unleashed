//
// Base Item Implementation

#include "Item Headers/Item.h"


std::string Item::GetItemName()
{
	return itemName;
}

int Item::GetItemCount()
{
	return itemCount;
}

void Item::SetItemName(std::string newName)
{
	itemName = newName;
}

void Item::SetItemCount(int setTo)
{
	itemCount = setTo;

	if (itemCount < 0) itemCount = 0; // An "Item" count should never be negative
}

void Item::ChangeItemCount(int changeBy)
{
	itemCount += changeBy;

	if (itemCount < 0) itemCount = 0; // An "Item" count should never be negative
}

void Item::SaveData(std::fstream f)
{
	if (f)
	{
		f.write((char*)this, sizeof(this));
		f << std::endl;
	}
	else
	{
		std::cout << "Item failed to write to file";
	}
}
