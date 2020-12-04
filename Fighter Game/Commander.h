#pragma once
#include "Person.h"
class Commander : protected Person
{

private:
	float work_practice;
	unsigned short victory_count;
	std::string army_no;

public:

	Commander();

	Commander(const std::string&, const std::string&, const short&, const float&, const short&, const std::string&);

	void Set_work_practice(const float&);
	float Get_work_practice() const;

	void Set_victory_count(const short&);
	short Get_victory_count() const;

	void Set_army_number(const std::string&);
	std::string Get_army_number() const;

	void Show() const;

};