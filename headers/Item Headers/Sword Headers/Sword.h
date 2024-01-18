#pragma once

#include "Item Headers/Item.h"

// TODO 
class Sword : public Item
{
public:
	virtual void Attack(); 

	void SaveData(std::fstream f) override;

	Sword();
};