#include <iostream>
#include <iomanip> 
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;

    do {
        cout << "������ ����� ������ N(�� 5 �� 20): ";
        cin >> N;
        if (N < 5 || N > 20) {
            cout << "����� ������ �� ���� �� 5 �� 20.\n";
        }
    } while (N < 5 || N > 20);

    int numbers[20];

    for (int i = 0; i < N; i++) {
        cout << "������ ������� [" << i << "]: ";
        cin >> numbers[i];
    }
    
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += numbers[i];
    }
    double average = static_cast<double>(sum) / N;
    int greaterCount = 0, smallerCount = 0;
    for (int i = 0; i < N; i++) {
        if (numbers[i] > average)
            greaterCount++;
        else if (numbers[i] < average)
            smallerCount++;
    }
    cout << "\n�������� �����: ";
    for (int i = 0; i < N; i++) {
        cout << numbers[i] << " ";
    }

    cout << "\n���� ��������: " << sum;
    cout << "\n������ �����������: " << fixed << setprecision(2) << average;
    cout << "\n������� �� ������: " << greaterCount;
    cout << "\n������ �� ������: " << smallerCount << endl;

    return 0;
}