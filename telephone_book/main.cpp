#include "telephone_book.h"


int main(int argc, char** argv)
{
	{


		phone_number temp_phn_num = { 7,812,1234567 };
		phone temp_phn = { temp_phn_num ,"Kiril" };
		phone_book phn_book;
		phn_book.phones = new phone[phn_book.capacity]; 

		add_phone_number(phone(), phn_book);

		add_phone_number(temp_phn, phn_book);

		temp_phn_num = { 7,911,2222222 };
		temp_phn = { temp_phn_num,"Ivanov" };
		add_phone_number(temp_phn, phn_book);

		temp_phn_num = { 7,921,8887766 };
		temp_phn = { temp_phn_num,"Petr" };
		add_phone_number(temp_phn, phn_book);

		temp_phn_num = { 7,941,8887766 };
		temp_phn = { temp_phn_num,"Petrovich" };
		add_phone_number(temp_phn, phn_book);

		temp_phn_num = { 7,912,7776655 };
		temp_phn = { temp_phn_num,"Egor" };
		add_phone_number(temp_phn, phn_book);

		temp_phn_num = { 7,931,6666666 };
		temp_phn = { temp_phn_num,"Devid" };
		add_phone_number(temp_phn, phn_book);

		print_phone_book(phn_book);

		delete_phone({ { 7,911,2222222 },"Ivanov" }, phn_book);
		print_phone_book(phn_book);

		edit_phone_number_by_number({ 7,911,2222222 }, "Sidorov", phn_book);
		print_phone_book(phn_book);

		edit_phone_number_by_number({ 7,911,2222222 }, "Fedorov", phn_book);
		print_phone_book(phn_book);

		flush_phone_book(phn_book);
		cout << "\nPhonebook deleted!\n";
		print_phone_book(phn_book);

		delete[] phn_book.phones;
	}

	return 0;
}