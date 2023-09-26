#include "telephone_book.h"

//using namespace std;

phone_book::phone_book()
{
	phones = new phone[capacity];
}

phone_book::~phone_book()
{
	delete[] phones;
	tel_counter = 0;
	capacity = 5;
}

void phone_book::add_phone_number(const phone& m_num)
{
	bool existing = false;
	for (size_t i = 0; i < tel_counter; i++)
		if (phones[i] == m_num)
		{
			cout << "\nThis phone " << m_num << " already exists!\n";
			break;
		}
	if (capacity == tel_counter)
	{
		capacity += 5;
		phone* temp_phn_book = new phone[capacity];
		for (size_t i = 0; i < tel_counter; i++) temp_phn_book[i] = phones[i];
		delete[] phones;
		phones = temp_phn_book;
	}
	phones[tel_counter] = m_num;
	tel_counter++;
}

void phone_book::delete_phone(const phone& m_num)
{
	for (size_t i = 0; i < tel_counter; i++)
	{
		if (phones[i] == m_num)
		{
			for (size_t j = i; j < tel_counter-1; j++) phones[j] = phones[j + 1];
			tel_counter--;
			break;
		}
	}
}

void phone_book::print_phone_book() const
{
	cout << endl;
	for (size_t i = 0; i < tel_counter; i++) cout << phones[i] << endl;
}

void phone_book::edit_phone_number_by_number(const phone_number& phn_n, const char* new_name)
{
	bool existing = false;
	for (size_t i = 0; i < tel_counter; i++)
	{
		if (phones[i].m_phone == phn_n)
		{
			strcpy_s(phones[i].name, new_name);
			existing = true; 
			break;
		}
	}
	//контакта с таким телефоном не нашлось?? создаем новый
	if(!existing)
	{
		phone temp_phn;
		temp_phn.m_phone = phn_n;
		strcpy_s(temp_phn.name, new_name);
		this->add_phone_number(temp_phn);
	}
}

void phone_book::delete_phone_book()
{
	phone* empty_book = new phone[capacity];
	this->~phone_book();
	phones = empty_book;
}

bool phone::operator==(const phone& m_phn)
{
	return ((this->m_phone == m_phn.m_phone)&&(strcmp(this->name,m_phn.name)==0));
}

phone& phone::operator=(const phone& phn)
{
	this->m_phone = phn.m_phone;
	strcpy_s(this->name, phn.name);
	return *this;
}

bool phone_number::operator==(const phone_number& m_phn_n)
{
	return ((this->city_code == m_phn_n.city_code)&&(this->country_code==m_phn_n.country_code)&&(this->phn_number==m_phn_n.phn_number));
}

ostream& operator<<(ostream& stream, const phone_number& phn_n)
{
	stream << "+" << phn_n.country_code << "(" << phn_n.city_code << ")" << phn_n.phn_number;
	return stream;
}

ostream& operator<<(ostream& stream, const phone& phn)
{
	stream << phn.m_phone << "\t" << phn.name;
	return stream;
}
