#include <iostream>

int main(int argc, char** argv)
{
	using namespace std;
	srand(time(NULL));
	size_t N = rand() % 30, M = rand() % 30;
	int* rand_dyn_ar = new int[N*M];
	int** dyn_ar2d = new  int*[N];
	for(size_t i=0;i<N;i++) 
		dyn_ar2d[i] = &rand_dyn_ar[i*M];
}