#pragma once
#include <string>
class Person
{

private:
	std::string name;
	std::string surname;
	unsigned short age;

public:

	Person();

	Person(const std::string&, const std::string&, const short&);

	void Set_name(const std::string&);
	std::string Get_name() const;

	void Set_surname(const std::string&);
	std::string Get_surname() const;

	void Set_age(const short&);
	unsigned short Get_age() const;

	void Show() const;
};