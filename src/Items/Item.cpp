//
// Base Item Implementation

#include "Item Headers/Item.h"


std::string Item::GetItemName()
{
	return itemName;
}

std::string Item::GetItemDescription()
{
	return itemDescription;
}

int Item::GetItemCount()
{
	return itemCount;
}

void Item::SetItemName(std::string newName)
{
	itemName = newName;
	validItem = true; // If we've set the name, consider the object no longer pseudo
}

void Item::SetItemDescription(std::string newDescription)
{
	itemDescription = newDescription;
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

bool Item::IsValid()
{
	return validItem ? true : false;
}