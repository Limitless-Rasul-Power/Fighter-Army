#pragma once
#include "Commander.h"
#include "Tank.h"
#include "Military_Aircraft.h"
#include "Military_Ship.h"

class Army
{

private:
	Commander* commander;
	Stack<Soldier>* army_soldiers;
	Stack<Tank>* tank;
	Stack<MilitaryAircraft>* military_aircraft;
	Stack<MilitaryShip>* military_ship;

public:

	Army();

	Army(Commander*  const&, Stack<Soldier>* const&, Stack<Tank>* const&, Stack<MilitaryAircraft>* const&, Stack<MilitaryShip>* const&);

	void Set_commander(Commander* const&);
	Commander* Get_commander() const;

	void Set_army_soldier(Stack<Soldier>* const&);
	Stack<Soldier>* Get_army_soldier() const;

	void Set_tank(Stack<Tank>* const&);
	Stack<Tank>* Get_tank() const;

	void Set_military_aircraft(Stack<MilitaryAircraft>* const&);
	Stack<MilitaryAircraft>* Get_military_aircraft() const;

	void Set_military_ship(Stack<MilitaryShip>* const&);
	Stack<MilitaryShip>* Get_military_ship() const;

	float Calculate_all_army_power() const;

	void Show() const;

	~Army();

};