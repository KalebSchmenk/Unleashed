//
// Base Sword Implementation

#include "Item Headers/Sword Headers/Sword.h"
#include "Enemy Headers/BaseEnemy.h"

Sword::Sword()
{
	SetItemName("Wooden Sword");
}

int Sword::Attack(BaseEnemy* enemy)
{
	enemy->TakeDamage(damageOutput);
	return damageOutput;
}
