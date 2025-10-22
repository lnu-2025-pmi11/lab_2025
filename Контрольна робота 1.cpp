#include <iostream>
#include <Windows.h>
#include <iomanip>
using namespace std;


int main()
{
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть розмір масиву N (від 5 до 20): ";
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cout << "Введіть елемент " << "[" << i << "]:";
		cin >> arr[i];
	}

	cout << "Введений масив: ";
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}

	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
	}
	cout << "\nСума елементів: " << sum;

	double average = 0;
	average = sum/N;
	cout << "\nСереднє арифметичне: " << fixed << setprecision(2) << average;

	int maxaverage = 0;
	int minaverage = 0;

	for (int j = 0; j < N; j++)
	{
		if (arr[j] > average)
		{
			maxaverage += 1;
		}
		if (arr[j] < average)
		{
			minaverage += 1;
		}
	}
	cout << "\nКількість чисел, більших за середнє: " << maxaverage;
	cout << "\nКількість чисел, менших за середнє: " << minaverage;

}