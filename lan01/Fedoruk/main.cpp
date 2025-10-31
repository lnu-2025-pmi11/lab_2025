#include <iostream>
#include <iomanip>
using namespace std;

void main() {
	int N;
	cout << "lenght: ";
	cin >> N;

	int* arr = new int[N];
	double sum = 0;
	double ser = 0;
	int a = 0;
	int b = 0;

	for (int i = 0; i < N; i++) {
		cout << " write " << N << " elements for array (range of numbers: 5-20): \n";
		cout << i + 1 << "st element: ";
		cin >> arr[i];
		if (arr[i] < 5) {
			cout << "error, the number is less than 5";
			i = N;
		}
		else if (arr[i] > 20) {
			cout << "error, the number is bigger than 20";
			i = N;
		}
		sum = sum + arr[i];
	}
	ser = sum / N;

	for (int i = 0; i < N; i++) {
		if (arr[i] < ser)
			a++;
		else if (arr[i] > ser)
			b++;
	}
	//return arr[N], sum, ser, a, b;

	cout << "array is: ";
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "sum of elements = " << sum << endl;
	cout << fixed << setprecision(2);
	cout << "avarage value = " << ser << endl;
	cout << "amount of numbers that are less than avarage value: " << a;
	cout << "amount of numbers that are bigger than avarage value: " << b;
}
