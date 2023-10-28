#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* b, const int size, const int Low, const int High, int i)
{
	b[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(b, size, Low, High, i + 1);
}
void Print(int* b, const int size, int i)
{
	cout << setw(4) << b[i];
	if (i < size - 1)
		Print(b, size, i + 1);
	else
		cout << endl;
}
int IFirst(int* a, const int size, int& min, int i)
{
	if (a[i] % 2 != 0)
	{
		min = a[i];
		return i; 
	} 

	if (i < size - 1)
		return IFirst(a, size, min, i + 1);
	else
		return -1;
}
int Min(int* a, const int size, int min, int i)
{
	if (a[i] < min && a[i] % 2 != 0)
		min = a[i];
	if (i < size - 1)
		return Min(a, size, min, i + 1);
	else
		return min;
}
int main()
{
	srand((unsigned)time(NULL));
	const int n = 10;
	int b[n];

	int Low = 10;
	int High = 90;
	Create(b, n, Low, High, 0);
	Print(b, n, 0);

	int min; 
	int imin = IFirst(b, n, min, 0);

	if (imin == -1)
		cerr << "немає елементів, які задовольняють умові" << endl;
	else
		cout << "min = " << Min(b, n, min, imin + 1) << endl;

	return 0;

}
