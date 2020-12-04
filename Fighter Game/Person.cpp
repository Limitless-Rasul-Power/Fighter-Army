#include <iostream>
#include <assert.h>
#include "Person.h"

Person::Person():name(""), surname(""), age(0)
{}

Person::Person(const std::string& name, const std::string& surname, const short& age)
{
	Set_name(name);
	Set_surname(surname);
	Set_age(age);
}

void Person::Set_name(const std::string& name)
{
	assert(!name.empty() && "Name is Empty!");
	this->name = name;
}

std::string Person::Get_name() const
{
	return name;
}

void Person::Set_surname(const std::string& surname)
{
	assert(!surname.empty() && "Name is Empty!");
	this->surname = surname;
}

std::string Person::Get_surname() const
{
	return surname;
}

void Person::Set_age(const short& age)
{
	assert(age > 0 && "Age must be more than 0!");
	this->age = age;
}

unsigned short Person::Get_age() const
{
	return age;
}

void Person::Show() const
{
	std::cout << "Name: " << Get_name() << '\n';
	std::cout << "Surname: " << Get_surname() << '\n';
	std::cout << "Age: " << Get_age() << "\n\n";
}