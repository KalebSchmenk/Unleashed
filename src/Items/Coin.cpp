//
// Coin Implementation

#include "Item Headers/Coin.h"

Coin::Coin(int amount)
{
	SetItemName("Coin");
	SetItemCount(amount);
}

// TODO
Item Coin::Buy()
{
	std::cout << "You bought something! TODO";
	Coin coin(10);
	return coin;
}