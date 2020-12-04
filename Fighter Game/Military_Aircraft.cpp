#include <iostream>
#include <assert.h>
#include "Military_Aircraft.h"

MilitaryAircraft::MilitaryAircraft():military_aircraft_name(""), soldiers(nullptr)
{}

MilitaryAircraft::MilitaryAircraft(const float& fight_power, const std::string& weapon,
	const std::string& military_aircraft_name, Stack<Soldier>* const& soldiers)
	: Fighter(fight_power, weapon)
{
	Set_name(military_aircraft_name);
	Set_soldier(soldiers);
	Calculate_soldiers_power();
}

void MilitaryAircraft::Set_name(const std::string& military_aircraft_name)
{
	assert(!military_aircraft_name.empty() && "Military Aircraft Name is Empty!");
	this->military_aircraft_name = military_aircraft_name;
}

std::string MilitaryAircraft::Get_name() const
{
	return military_aircraft_name;
}

void MilitaryAircraft::Set_soldier(Stack<Soldier>* const& soldiers)
{
	assert(soldiers && "Soldiers is nullptr!");
	this->soldiers = soldiers;
}

Stack<Soldier>* MilitaryAircraft::Get_soldiers() const
{
	return soldiers;
}

float MilitaryAircraft::Calculate_soldiers_power()
{
	float max_soldier_power = 0.0f;

	for (unsigned short i = 0; i < this->soldiers->Get_number(); i++)
		max_soldier_power += this->soldiers->Take(i)->Fighter::Get_fight_power();

	Fighter::Set_fight_power(max_soldier_power + Get_fight_power());

	return max_soldier_power;
}

void MilitaryAircraft::Show() const
{
	Fighter::Show();
	std::cout << "Military Aircraft Name: " << Get_name() << '\n';
	std::cout << "Military Aircraft Soldiers\n\n";

	for (unsigned short i = 0; i < soldiers->Get_number(); i++)
		soldiers->Take(i)->Soldier::Show();
}

MilitaryAircraft::~MilitaryAircraft()
{
	delete soldiers;
}