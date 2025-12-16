#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n = 0;
	cout << "Ââåä³òü ðîçì³ð ìàñèâó N (â³ä 5 - 20): ";
	cin >> n;

	do
	{
	int n;
	cout << "Ââåä³òü ðîçì³ð ìàñèâó N (â³ä 5 - 20): ";
	cin >> n;
	} while(4 < n and n < 21);

	int* numbers = new int[n];
	for (int i = 0; i < n; i++) {
		cout << "Ââåä³òü " << i + 1 << " åëåìåíò: " ;
		cin >> numbers[i];
	}

	cout << "Âèâåäåíèé ìàñèâ: ";
	for (int i = 0; i < n; i++) {
		cout << numbers[i] << " ";
	}
	cout << endl;

	int summa = 0;
	for (int i = 0; i < n; i++) {
		summa += numbers[i];
	}
	cout << "Ñóìà åëåìåíò³â: " << summa << endl;

	float average = 0;
	for (int i = 0; i < n; i++) {
		average = summa / n;
	}
	cout << fixed << setprecision(2);
	cout << "Ñåðåäíº àðèôìåòè÷íå: " << average << endl;

	int minAverage = numbers[0];
	int maxAverage = numbers[0];
	int index_minAverage = 0, index_maxAverage = 0;
	for (int i = 0; i < n; i++) {
		if (numbers[i] > average) index_maxAverage++;

		if (numbers[i] < average) index_minAverage++;
	}
	cout << "Ê³ëüê³ñòü ÷èñåë, ÿê³ á³ëüø³ çà ñåðåäíº àðèôìåòè÷íå: " << index_maxAverage << endl;
	cout << "Ê³ëüê³ñòü ÷èñåë, ÿê³ ìåíø³ çà ñåðåäíº àðèôìåòè÷íå: " << index_minAverage << endl;

	return 0;

}
