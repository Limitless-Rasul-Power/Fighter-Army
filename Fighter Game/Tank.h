#pragma once
#include "Soldier.h"
#include "Stack.h"
class Tank : public Fighter
{

private:
	std::string tank_name;
	Stack<Soldier>* soldiers;

public:

	Tank();

	Tank(const float&, const std::string&, const std::string&, Stack<Soldier>* const&);

	void Set_name(const std::string&);
	std::string Get_name() const;

	void Set_soldier(Stack<Soldier>* const&);
	Stack<Soldier>* Get_soldiers() const;

	float Calculate_soldiers_power();

	void Show() const;

	~Tank();

};