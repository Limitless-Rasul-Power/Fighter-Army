#include <iostream>
#include <assert.h>
#include "Tank.h"

Tank::Tank():tank_name(""), soldiers(nullptr)
{}

Tank::Tank(const float& fight_power, const std::string& weapon, const std::string& tank_name, Stack<Soldier>* const& soldiers)
	:Fighter(fight_power, weapon)
{
	Set_name(tank_name);
	Set_soldier(soldiers);
	Calculate_soldiers_power();
}

void Tank::Set_name(const std::string& tank_name)
{
	assert(!tank_name.empty() && "Tank Name is Empty!");
	this->tank_name = tank_name;
}

std::string Tank::Get_name() const
{
	return tank_name;
}

void Tank::Set_soldier(Stack<Soldier>* const& soldiers)
{
	assert(soldiers && "Soldiers is nullptr!");
	this->soldiers = soldiers;
}

Stack<Soldier>* Tank::Get_soldiers() const
{
	return soldiers;
}

float Tank::Calculate_soldiers_power()
{
	float max_soldier_power = 0.0f;

	for (unsigned short i = 0; i < this->soldiers->Get_number(); i++)
		max_soldier_power += this->soldiers->Take(i)->Fighter::Get_fight_power();

	Fighter::Set_fight_power(max_soldier_power + Get_fight_power());

	return max_soldier_power;
}

void Tank::Show() const
{
	Fighter::Show();
	std::cout << "Tank Name: " << Get_name() << '\n';
	std::cout << "Tank Soldiers\n\n";

	for (unsigned short i = 0; i < soldiers->Get_number(); i++)
		soldiers->Take(i)->Soldier::Show();
}

Tank::~Tank()
{
	delete soldiers;
}