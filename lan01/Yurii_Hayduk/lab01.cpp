#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;



int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	int N;
	bool isCorrect = false;

	while (!isCorrect)
	{
		cout << "Enter N(5-20):";
		cin >> N;

		if (N >= 5 && N <= 20)
			isCorrect = true;
		else
			cout << "Incorrect N! Please try again." << endl;
	}
	system("cls");

	int* numbers = new int[N];

	for (int i = 0; i < N; i++)
	{
		numbers[i]=rand()%101-50;
	}

	for (int i = 0; i < N; i++)
	{
		cout << setw(5) << numbers[i];
	}
	cout << endl;
	int sum = 0;
	for(int i = 0; i < N; i++)
	{
		sum += numbers[i];
	}
	cout << "Sum : " << sum << endl;
	double averge = (double)sum / N;
	cout << "Average : " << setprecision(4) <<averge << endl;

	int count = 0;
	cout << "Bigger than average numbers: ";
	for (int i = 0; i < N; i++) {
		if(numbers[i] > averge) {
			cout << setw(5) << numbers[i];
			count++;
		}
	}
	cout << endl << "Count of bigger than average numbers: " << count << endl;
	count = 0;
	cout << "Smaller than average numbers: ";
	for (int i = 0; i < N; i++) {
		if (numbers[i] < averge) {
			cout << setw(5) << numbers[i];
			count++;
		}
	}
	cout << endl << "Count of smaller than average numbers: " << count << endl;

	delete[] numbers;


	return 0;
}
