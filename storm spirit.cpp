#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int N;
	do {
		cout << "Enter number from 5 to 20: ";
		cin >> N;
		if (N < 5 || N > 20) {
			cout << "False because you stupid monkey" << endl;
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

	double avg = sum / N;

	int greaterCount = 0;
	int smallerCount = 0;

	for (int i = 0; i < N; i++) {
		if (numbers[i] > avg) {
			greaterCount++;
		}
		else if (numbers[i] < avg) {
			smallerCount++;
		}
	}
	cout << "\n led Array" << endl;
	for (int i = 0; i < N; i++) {
		cout << numbers[i] << " ";
	}

	cout << "\nSum: " << sum << endl;
	cout << "\nAvg: " << avg << endl;
	cout << "\nNumbers greater than avg: " << greaterCount << endl;
	cout << "\nNumbers smaller than avg: " << smallerCount << endl;

	delete[] numbers;

	return 0;
}