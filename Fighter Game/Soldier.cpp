#include <iostream>
#include <assert.h>
#include "Soldier.h"

Soldier::Soldier() :id(0)
{}

Soldier::Soldier(const std::string& name, const std::string& surname, const short& age,
	const float& fight_power, const std::string& weapon, const short& id)
	:Person(name, surname, age)
{
	Set_fight_power(fight_power);
	Set_weapon(weapon);
	Set_id(id);
}

void Soldier::Set_id(const short& id)
{
	assert(id > 0 && "ID must be more than 0!");
	this->id = id;
}

unsigned short Soldier::Get_id() const
{
	return id;
}

void Soldier::Show() const
{
	std::cout << "Soldier ID: " << Get_id() << "\n\n";
	Person::Show();
	Fighter::Show();
}