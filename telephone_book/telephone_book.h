#pragma once
#include <iostream>

using namespace std;

struct phone_number
{
	size_t country_code = 7;
	size_t city_code = 812;
	size_t phn_number;
	bool operator==(const phone_number&);
	friend ostream& operator<<(ostream&, const phone_number&);
};

struct phone
{
private:
	friend ostream& operator<<(ostream&, const phone&);
	static const size_t name_lenght = 32;

public:
	phone_number m_phone;
	char name[name_lenght];

	bool operator==(const phone&);
	phone& operator= (const phone&);

};

class phone_book
{
	phone *phones;
	size_t capacity = 5;
	size_t tel_counter = 0;

public:
	phone_book();
	~phone_book();

	void add_phone_number(const phone&);
	void delete_phone(const phone&);
	void print_phone_book() const;
	void edit_phone_number_by_number(const phone_number&, const char* new_name);
	void delete_phone_book();
	
};

