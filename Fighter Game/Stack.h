#pragma once
template<typename T>
class Stack
{

private:
	T** data;
	unsigned short number;

public:

	Stack():data(nullptr), number(0)
	{}

	void Push(T* const& added)
	{
		auto new_data = new T * [Get_number() + 1];

		for (unsigned short i = 0; i < Get_number(); i++)
			new_data[i] = this->data[i];

		new_data[Get_number()] = added;

		delete[] this->data;
		this->data = new_data;
		new_data = nullptr;
		Set_number(Get_number() + 1);
	}

	void Pop()
	{
		auto new_data = new T * [Get_number() - 1];

		for (unsigned short i = 0; i < Get_number() - 1; i++)
			new_data[i] = this->data[i];

		delete[] this->data;
		this->data = new_data;
		new_data = nullptr;
		Set_number(Get_number() - 1);
	}

	T*& Peek()
	{
		return data[0];
	}

	void Set_number(const short& number)
	{
		this->number = number;
	}

	unsigned short Get_number()
	{
		return number;
	}

	T*& Take(const short& index)
	{
		return data[index];
	}

	~Stack()
	{
		for (unsigned short i = 0; i < Get_number(); i++)
			delete data[i];

		delete[] data;
	}

};