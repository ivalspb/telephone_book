#include "telephone_book.h"

//using namespace std;



void add_phone_number(const phone& m_num, phone_book& ph_bk)
{
	bool existing = false;
	for (size_t i = 0; i < ph_bk.tel_counter; i++)
		if ((ph_bk.phones[i].m_phone.country_code == m_num.m_phone.country_code)&&
			(ph_bk.phones[i].m_phone.city_code == m_num.m_phone.city_code)&&
			(ph_bk.phones[i].m_phone.phn_number == m_num.m_phone.phn_number)&&
			(strcmp(ph_bk.phones[i].name,m_num.name)==0))
		{
			cout << "\nAdded phone already exists!\n";
			break;
		}
	if (ph_bk.capacity == ph_bk.tel_counter)
	{
		ph_bk.capacity += 5;
		phone* temp_phn_book = new phone[ph_bk.capacity];
		for (size_t i = 0; i < ph_bk.tel_counter; i++) temp_phn_book[i] = ph_bk.phones[i];
		delete[] ph_bk.phones;
		ph_bk.phones = temp_phn_book;
	}
	ph_bk.phones[ph_bk.tel_counter].m_phone = m_num.m_phone;
	strcpy_s(ph_bk.phones[ph_bk.tel_counter].name, m_num.name);
	ph_bk.tel_counter++;
}

void delete_phone(const phone& m_num, phone_book& ph_bk)
{
	bool exists=false;
	for (size_t i = 0; i < ph_bk.tel_counter; i++)
	{
		if ((ph_bk.phones[i].m_phone.country_code == m_num.m_phone.country_code) &&
			(ph_bk.phones[i].m_phone.city_code == m_num.m_phone.city_code) &&
			(ph_bk.phones[i].m_phone.phn_number == m_num.m_phone.phn_number) &&
			(strcmp(ph_bk.phones[i].name, m_num.name) == 0))
		{
			for (size_t j = i; j < ph_bk.tel_counter-1; j++) 
			{
				ph_bk.phones[j].m_phone = ph_bk.phones[j + 1].m_phone;
				strcpy_s(ph_bk.phones[j].name, ph_bk.phones[j+1].name);
			}
			ph_bk.tel_counter--;
			exists = true;
			break;
		}
	}
	if(!exists) cout << "\nDeleted phone not exists!\n";
}

void print_phone_book(const phone_book& ph_bk) 
{
	cout << endl;
	for (size_t i = 0; i < ph_bk.tel_counter; i++)
	{
		cout << "+" << ph_bk.phones[i].m_phone.country_code
			<< "(" << ph_bk.phones[i].m_phone.city_code << ")"
			<< ph_bk.phones[i].m_phone.phn_number<<" "
			<< ph_bk.phones[i].name << endl;
	}
}

void edit_phone_number_by_number(const phone_number& phn_n, const char* new_name, phone_book& ph_bk)
{
	bool existing = false;
	for (size_t i = 0; i < ph_bk.tel_counter; i++)
	{
		if ((ph_bk.phones[i].m_phone.country_code == phn_n.country_code) &&
			(ph_bk.phones[i].m_phone.city_code == phn_n.city_code) &&
			(ph_bk.phones[i].m_phone.phn_number == phn_n.phn_number))
		{
			strcpy_s(ph_bk.phones[i].name, new_name);
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
		add_phone_number(temp_phn,ph_bk);
	}
}

void flush_phone_book(phone_book &ph_bk)
{
	delete[] ph_bk.phones;
	ph_bk.phones = new phone[5];
	ph_bk.capacity = 5;
	ph_bk.tel_counter = 0;
}

