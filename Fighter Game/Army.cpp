#include <iostream>
#include <assert.h>
#include <windows.h>
#include "Army.h"

#define RED 12
#define WHITE 7

Army::Army():commander(nullptr), army_soldiers(nullptr), tank(nullptr), military_aircraft(nullptr), military_ship(nullptr)
{}

Army::Army(Commander* const& commander, Stack<Soldier>* const& army_soldiers,
	Stack<Tank>* const& tank, Stack<MilitaryAircraft>* const& military_aircraft, Stack<MilitaryShip>* const& military_ship)
{
	Set_commander(commander);
	Set_army_soldier(army_soldiers);
	Set_tank(tank);
	Set_military_aircraft(military_aircraft);
	Set_military_ship(military_ship);
}

void Army::Set_commander(Commander* const& commander)
{
	assert(commander && "Commander is nullptr!");
	this->commander = commander;
}

Commander* Army::Get_commander() const
{
	return commander;
}

void Army::Set_army_soldier(Stack<Soldier>* const& army_soldiers)
{
	assert(army_soldiers && "Army Soldiers are nullptr!");
	this->army_soldiers = army_soldiers;
}

Stack<Soldier>* Army::Get_army_soldier() const
{
	return army_soldiers;
}

void Army::Set_tank(Stack<Tank>* const& tank)
{
	assert(tank && "Tank is nullptr!");
	this->tank = tank;
}

Stack<Tank>* Army::Get_tank() const
{
	return tank;
}

void Army::Set_military_aircraft(Stack<MilitaryAircraft>* const& military_aicraft)
{
	assert(military_aicraft && "Military Aircraft is nullptr!");
	this->military_aircraft = military_aicraft;
}

Stack<MilitaryAircraft>* Army::Get_military_aircraft() const
{
	return military_aircraft;
}

void Army::Set_military_ship(Stack<MilitaryShip>* const& military_ship)
{
	assert(military_ship && "Military Ship is nullptr!");
	this->military_ship = military_ship;
}

Stack<MilitaryShip>* Army::Get_military_ship() const
{
	return military_ship;
}

float Army::Calculate_all_army_power() const
{
	float army_power = 0.0f;

	for (unsigned short i = 0; i < army_soldiers->Get_number(); i++)
		army_power += army_soldiers->Take(i)->Get_fight_power();

	for (unsigned short i = 0; i < tank->Get_number(); i++)
		army_power += tank->Take(i)->Get_fight_power();

	for (unsigned short i = 0; i < military_aircraft->Get_number(); i++)
		army_power += military_aircraft->Take(i)->Get_fight_power();

	for (unsigned short i = 0; i < military_ship->Get_number(); i++)
		army_power += military_ship->Take(i)->Get_fight_power();

	return army_power;

}

void Army::Show() const
{
	std::cout << "Commander INFO\n\n";
	commander->Commander::Show();

	std::cout << "\n\nSoldiers INFO\n\n";
	for (unsigned short i = 0; i < army_soldiers->Get_number(); i++)
		army_soldiers->Take(i)->Soldier::Show();

	std::cout << "\n\nTank INFO\n\n";
	for (unsigned short i = 0; i < tank->Get_number(); i++)
		tank->Take(i)->Tank::Show();

	std::cout << "\n\nMilitary Aircraft INFO\n\n";
	for (unsigned short i = 0; i < military_aircraft->Get_number(); i++)
		military_aircraft->Take(i)->MilitaryAircraft::Show();

	std::cout << "\n\nMilitary Ship INFO\n\n";
	for (unsigned short i = 0; i < military_ship->Get_number(); i++)
		military_ship->Take(i)->MilitaryShip::Show();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
	std::cout << "\t\t\t\t\t          ALL ARMY POWER  = " << Calculate_all_army_power() << '\n';
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

Army::~Army()
{
	delete commander;
	delete army_soldiers;
	delete tank;
	delete military_aircraft;
	delete military_ship;
}