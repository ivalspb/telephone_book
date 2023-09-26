#pragma once
#include <iostream>

using namespace std;

struct phone_number
{
	size_t country_code = 7;
	size_t city_code = 812;
	size_t phn_number=1112233;
};

struct phone
{
private:
	static const size_t name_lenght = 32;
public:
	phone_number m_phone;
	char name[name_lenght] = "defaultName";
};

struct phone_book
{
	phone *phones;
	size_t capacity = 5;
	size_t tel_counter = 0;
};

void add_phone_number(const phone&, phone_book&);
void delete_phone(const phone&, phone_book&);
void print_phone_book(const phone_book&);
void edit_phone_number_by_number(const phone_number&, const char* new_name, phone_book&);
void flush_phone_book(phone_book&);