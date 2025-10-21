#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int n;
	cout << "write number from 5 to 20: ";
	do
	{
		cin >> n;
		if (n < 5 || n > 20)
		{
			cout << "error" << endl;
		}
	} while (n < 5 || n > 20);

	cout << "------------------------" << endl;

	int* numbers = new int[n]();
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}

	for (int i = 0; i < n; i++)
	{
		sum += numbers[i];
	}

	double average = (double)sum / n;

	int countMore = 0;
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] > average)
		{
			countMore++;
		}
	}

	int countLess = 0;
	for (int i = 0; i < n; i++)
	{
		if (numbers[i] < average)
		{
			countLess++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << numbers[i] << " ";
	}
	cout << endl;

	cout << sum << endl;
	cout << fixed << setprecision(2) << average << endl;
	cout << countLess;
	cout << countMore;
	

}