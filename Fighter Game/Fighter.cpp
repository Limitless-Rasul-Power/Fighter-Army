#include <iostream>
#include <assert.h>
#include "Fighter.h"

Fighter::Fighter():fight_power(0.0f), weapon("")
{}

Fighter::Fighter(const float& fight_power, const std::string& weapon)
{
	Set_fight_power(fight_power);
	Set_weapon(weapon);
}

void Fighter::Set_fight_power(const float& fight_power)
{
	assert(fight_power > 0 && "Fight Power must be more than 0!");
	this->fight_power = fight_power;
}

float Fighter::Get_fight_power() const
{
	return fight_power;
}

void Fighter::Set_weapon(const std::string& weapon)
{
	assert(!weapon.empty() && "Weapon is Empty!");
	this->weapon = weapon;
}

std::string Fighter::Get_weapon() const
{
	return weapon;
}

void Fighter::Attack()
{
	std::cout << "Fighter Attacks with " << Get_weapon() << '\n';
}

void Fighter::Show() const
{
	std::cout << "Fight Power: " << Get_fight_power() << '\n';
	std::cout << "Fighter Weapon: " << Get_weapon() << "\n\n";
}