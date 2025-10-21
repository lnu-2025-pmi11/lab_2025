#include <iostream>
#include <iomanip> 
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;

    do {
        cout << "Введіть розмір масиву N(від 5 до 20): ";
        cin >> N;
        if (N < 5 || N > 20) {
            cout << "Розмір масиву має бути від 5 до 20.\n";
        }
    } while (N < 5 || N > 20);

    int numbers[20];

    for (int i = 0; i < N; i++) {
        cout << "Введіть елемент [" << i << "]: ";
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
    cout << "\nВведений масив: ";
    for (int i = 0; i < N; i++) {
        cout << numbers[i] << " ";
    }

    cout << "\nСума елементів: " << sum;
    cout << "\nСереднє арифметичне: " << fixed << setprecision(2) << average;
    cout << "\nБільших за середнє: " << greaterCount;
    cout << "\nМенших за середнє: " << smallerCount << endl;

    return 0;
}