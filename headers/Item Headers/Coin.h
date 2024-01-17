#pragma once

#include "Item Headers/Item.h"

// TODO 
class Coin : public Item
{
public:
	virtual Item Buy(); // I like this function signature

	Coin(int amount); // Ensure to override item vars in Coin instructor
};