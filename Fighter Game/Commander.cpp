#include <iostream>
#include <assert.h>
#include "Commander.h"

Commander::Commander() :work_practice(0.0), victory_count(0), army_no("")
{}

Commander::Commander(const std::string& name, const std::string& surname, const short& age, const float& work_practice,
	const short& victory_count, const std::string& army_no)
	:Person(name, surname, age)
{
	Set_work_practice(work_practice);
	Set_victory_count(victory_count);
	Set_army_number(army_no);
}

void Commander::Set_work_practice(const float& work_practice)
{
	assert(work_practice > 0.0f && "Work Practice must be more than 0!");
	this->work_practice = work_practice;
}

float Commander::Get_work_practice() const
{
	return work_practice;
}

void Commander::Set_victory_count(const short& victory_count)
{
	assert(victory_count > 0 && "Victory Count must be more than 0!");
	this->victory_count = victory_count;
}

short Commander::Get_victory_count() const
{
	return victory_count;
}

void Commander::Set_army_number(const std::string& army_number)
{
	assert(!army_number.empty() && "Army Number is Empty!");
	this->army_no = army_number;
}

std::string Commander::Get_army_number() const
{
	return army_no;
}

void Commander::Show() const
{
	Person::Show();
	std::cout << "Army NO_" << Get_army_number() << '\n';
	std::cout << "Work Practice: " << Get_work_practice() << '\n';
	std::cout << "Victory Count: " << Get_victory_count() << "\n\n";
}