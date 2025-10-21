#include <iostream>
#include <iomanip>
using namespace std;


int main() {
	setlocale(LC_ALL, "uk_UA");

	int N;
	cout << "Введіть значення від 5 до 20:" << endl;
	cin >> N;
	if (N < 5 || N > 20) {
		cout << "Помилка" << endl;
	}
	

	double* numbers = new double[N]; 
	cout << "Введіть " << N << " цілих чисел" << endl;
	for (int a = 0; a < N; a++) {
		cin >> numbers[a];
	}

	double sum = 0;
	for (int a = 0; a < N; a++) {
		cout << numbers[a] << " ";
		for (int a = 0; a < N; a++) {
			sum += numbers[a];
		}
		cout << "Сума елементів масиву: " << sum << endl;


		double average = static_cast<double>(sum) / N;
		cout << fixed << setprecision(2);
		cout << "Середнє арифметичне: " << average << endl;

		int greaterCount = 0;
		int smallerCount = 0;
		for (int a = 0; a < N; a++) {
			if (numbers[a] > average) greaterCount++;
			else if (numbers[a] < average) smallerCount++;


		}
		cout << "Кількість елементів більших за середнє: " << greaterCount << endl;
		cout << "Кількість елементів менших за середнє: " << smallerCount << endl;
		return 0;
	}
}

