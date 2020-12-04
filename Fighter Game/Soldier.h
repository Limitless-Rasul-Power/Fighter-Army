#pragma once
#include "Person.h"
#include "Fighter.h"
class Soldier : protected Person, public Fighter
{

private:
	unsigned short id;

public:

	Soldier();

	Soldier(const std::string&, const std::string&, const short&, const float&, const std::string&, const short&);

	void Set_id(const short&);
	unsigned short Get_id() const;

	void Show() const;

};