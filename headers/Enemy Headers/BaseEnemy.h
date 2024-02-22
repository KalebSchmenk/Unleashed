#pragma once

#ifndef BASE_ENEMY_H
#define BASE_ENEMY_H

#include "Player.h"
#include "Item Headers/Items.h"
#include <stdlib.h>
#include <iostream>

class BaseEnemy
{
public:
	virtual void Attack(PlayerObj *player);
	virtual void TakeDamage(int damage);
	virtual Item Die();

protected:
	int health;
	int damageOutput;
	Item itemToDrop;

};
#endif // BASE_ENEMY_H