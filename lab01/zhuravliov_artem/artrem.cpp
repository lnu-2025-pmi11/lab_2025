#include <iostream>   // для cin, cout

using namespace std;

int main() {
	int N;
	do {
		cout << "input size of array from 5 to 20: ";
		cin >> N;
		if (N < 5 || N > 20) {
			cout << "Error: size must be between 5 and 20." << endl;
			return 1;
		}
	} while (N < 5 || N > 20);
	int* numbers = new int[N];

	cout << "input " << N << " numbers: ";
	for (int i = 0; i < N; i++) {
		cout << "number " << i + 1 << ": ";
		cin >> numbers[i];
	}
	int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += numbers[i];
	}

	double average = static_cast<double>(sum) / N;

	int greaterCount = 0;
	int smallerCount = 0;

	for (int i = 0; i < N; i++) {
		if (numbers[i] > average) {
			greaterCount++;
		}
		else if (numbers[i] < average) {
			smallerCount++;
		}
	}
	cout << "\n led Array" << endl;
	for (int i = 0; i < N; i++) {
		cout << numbers[i] << " ";
	}

	cout << "\nSum: " << sum << endl;
	cout << "\nAverage: " << average << endl;
	cout << "\nNumbers greater than average: " << greaterCount << endl;
	cout << "\nNumbers smaller than average: " << smallerCount << endl;

	delete[] numbers;

	return 0;
}
