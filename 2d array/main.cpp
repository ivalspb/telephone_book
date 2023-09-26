#include "2d_arr.h"

int main(int argc, char** argv)
{
	{
		using namespace std;
		srand(time(NULL));
		size_t columns = rand() % 9+1, rows = rand() %9+1;

		cout << "array " << rows << " rows * " << columns << " columns" << endl; 

		int* rand_dyn_ar = new int[columns * rows];
		int** dyn_ar2d = new  int* [columns];//вспомогательный массив
		for (size_t i = 0; i < columns; i++)
			dyn_ar2d[i] = rand_dyn_ar + i * rows;
		for (size_t i = 0; i < rows * columns; i++)
			rand_dyn_ar[i] = rand() % 40 - 20;
		print_2d_arr(dyn_ar2d, columns, rows);

		float* dyn_ar_positive_average_rows = new float[rows];
		for (size_t i = 0; i < rows; i++)
		{
			float current_average = 0;
			size_t positive_count = 0;
			for (size_t j = 0; j < columns; j++)
			{
				if (dyn_ar2d[j][i] > 0) 
				{
					current_average += dyn_ar2d[j][i];
					positive_count++;
				}
			}
			if (positive_count) dyn_ar_positive_average_rows[i] = current_average / positive_count;
			else dyn_ar_positive_average_rows[i] = 0;
		}
		cout << "\ndyn_ar_positive_average_rows\n";
		print_1d_arr(dyn_ar_positive_average_rows, rows);

		delete[] dyn_ar_positive_average_rows;
		delete[] dyn_ar2d;
		delete[] rand_dyn_ar;
	}
}