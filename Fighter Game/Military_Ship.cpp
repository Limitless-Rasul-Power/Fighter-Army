#include <iostream>
#include <assert.h>
#include "Military_Ship.h"

MilitaryShip::MilitaryShip():military_ship_name(""), soldiers(nullptr)
{}

MilitaryShip::MilitaryShip(const float& fight_power, const std::string& weapon,
	const std::string& military_ship_name, Stack<Soldier>* const& soldiers)
	: Fighter(fight_power, weapon)
{
	Set_name(military_ship_name);
	Set_soldier(soldiers);
	Calculate_soldiers_power();
}

void MilitaryShip::Set_name(const std::string& military_ship_name)
{
	assert(!military_ship_name.empty() && "Military Ship Name is Empty!");
	this->military_ship_name = military_ship_name;
}

std::string MilitaryShip::Get_name() const
{
	return military_ship_name;
}

void MilitaryShip::Set_soldier(Stack<Soldier>* const& soldiers)
{
	assert(soldiers && "Soldiers is nullptr!");
	this->soldiers = soldiers;
}

Stack<Soldier>* MilitaryShip::Get_soldiers() const
{
	return soldiers;
}

float MilitaryShip::Calculate_soldiers_power()
{
	float max_soldier_power = 0.0f;

	for (unsigned short i = 0; i < this->soldiers->Get_number(); i++)
		max_soldier_power += this->soldiers->Take(i)->Fighter::Get_fight_power();

	Fighter::Set_fight_power(max_soldier_power + Get_fight_power());

	return max_soldier_power;
}

void MilitaryShip::Show() const
{
	Fighter::Show();
	std::cout << "Military Ship Name: " << Get_name() << '\n';
	std::cout << "Military Ship Soldiers\n\n";

	for (unsigned short i = 0; i < soldiers->Get_number(); i++)
		soldiers->Take(i)->Soldier::Show();
}

MilitaryShip::~MilitaryShip()
{
	delete soldiers;
}