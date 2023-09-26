#include "2d_arr.h"

void print_2d_arr(int** ar, size_t columns, size_t rows)
{
	for (size_t i = 0; i < columns; i++)
	{
		cout << endl;
		for (size_t j = 0; j < rows; j++)
			cout << ar[i][j] << "\t";
	}
}

void print_1d_arr(float* ar, size_t columns)
{
	cout << endl;
	for (size_t i = 0; i < columns; i++)
		cout << ar[i] << "\t";
}
