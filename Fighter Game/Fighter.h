#pragma once
#include <string>
class Fighter
{

private:
	float fight_power;
	std::string weapon;

public:

	Fighter();

	Fighter(const float&, const std::string&);

	void Set_fight_power(const float&);
	float Get_fight_power() const;

	void Set_weapon(const std::string&);
	std::string Get_weapon() const;

	void Attack();

	void Show() const;

};