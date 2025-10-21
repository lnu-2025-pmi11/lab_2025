#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//creating array
	int N;
	do {
		cout << "Enter N: ";
		cin >> N;
	} while (N > 4 && N < 21);

	int* array = new int[N];
	for (int i = 0; i < N; ++i)
	{
		cout << "\ninput [ " << i << " ] element: ";
		cin >> array[i];
	}
	//print array
	cout << "array: \n";
	for (int i = 0; i < N; ++i)
	{
		cout << array[i] << ' ';
	}
	cout << endl;
	//sum
	float sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += array[i];
	}
	cout << "\nsum of elements of array:  " << sum << endl;

	//avarege
	float avarage = sum / N;
	cout << fixed << setprecision(2);
	cout << "avarage : " << avarage;
	//number of more/less than avarege
	int maxCount = 0;
	int minCount = 0;
	for (int i = 0; i < N; ++i)
	{
		if (array[i] < avarage)
		{
			minCount++;
		}
		else if (array[i] > maxCount)
		{
			maxCount++;
		}
	}
	cout << "\nnumber of more than avarege:  " << maxCount << endl;
	cout << "number of less than avarege:  " << minCount << endl;

	delete[] array;

	//ending
	double b;
	//cout << "to end pragram input number: ";
	//cin >> b;
	
	system("pause");
	return 0;
}
