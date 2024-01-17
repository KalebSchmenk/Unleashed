//
// Coin Implementation

#include "Item Headers/Coin.h"

Coin::Coin(int amount)
{
	SetItemName("Coin");
	ChangeItemCount(amount - 1); // An item's amount is defaulted to 1.
								 // We -1 to to make it exactly the paramater
}

// TODO
Item Coin::Buy()
{
	std::cout << "You bought something! TODO";
}