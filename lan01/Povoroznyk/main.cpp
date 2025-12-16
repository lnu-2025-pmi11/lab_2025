#include <iostream>
using namespace std;

int main() {

	double N;
	cout << "Input N: "; cin >> N;
	
		if (N < 5 && N > 20){
		cout << "Error";
		cout << "Input N: "; cin >> N;
	}

	double* array = new double;
	for (int i = 0; i < N; ++i) {
		cout << "Input array element: ";
		cin >> array[i];
	}

	cout << "The array: ";
	for (int i = 0; i < N; ++i) {
		cout << array[i] << " ";
	}

	double sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += array[i];
	}
	cout << "\nThe sum is: " << sum << endl;

	double average;
	average = sum / N;
	cout << "The average value is: " << average << endl;

	int Num1 = 0;
	for (int i = 0; i < N; ++i) {
		if (array[i] > average) {
			Num1++;
		}
	}
	cout << "Quantity of numbers larger than average: " << Num1 << endl;

	int Num2 = 0;
	for (int i = 0; i < N; ++i) {
		if (array[i] > average) {
			Num2++;
		}
	}
	cout << "Quantity of numbers smaller than average: " << Num2 << endl;

	return 0;
}
