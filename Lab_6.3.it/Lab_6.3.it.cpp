#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* b, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		b[i] = Low + rand() % (High - Low + 1);
}
void Print(int* b, const int size)
{
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << setw(4) << b[i];
	cout << "]" << endl;
}
int Min(int* a, const int size)
{
	int min; 
	int imin = -1; 
	for (int i = 0; i < size; i++)
		if (a[i] % 2 != 0)
		{
			min = a[i]; 
			imin = i; 
			break; 
		}
	if (imin == -1)
	{
		cerr << "немає елементів, які задовольняють умові" << endl;
		return 0; 
	} 
	for (int i = imin + 1; i < size; i++)
		if (a[i] < min && a[i] % 2 != 0)
			min = a[i];
	return min;
}


int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;
	int b[n];

	int Low = 10;
	int High = 90;
	Create(b, n, Low, High);
	Print(b, n);

	cout << "min = " << Min(b, n) << endl;

	return 0;

}
