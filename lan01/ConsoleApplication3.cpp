#include <iostream>
using namespace std;
int main()
{
	int N = 0;
	int Sum = 0;
	int Bilshe = 0;
	double average = 0.0;
	int Menshe = 0;
	cout << "Enter x; 5<x<20 \n";
	cin >> N;
	int* Massive = new int[N];
	for (int i = 0; i < N; ++i) {
		cout << "Enter ";
		cin >> Massive[i];
		Sum += Massive[i];
	}
	average = Sum / N;
		cout << Sum << "\n";
	cout << average;
	for (int i = 0; i < N; ++i) {
		if (Massive[i] > average) {
			++Bilshe;
		}
		else if (Massive[i] < average) {
			++Menshe;
		}
	}
	cout << "BILSHE" << Bilshe << "\n";
	cout << "MENSHE" << Menshe << "\n";
}

