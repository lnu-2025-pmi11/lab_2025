#include <iostream>
#include <iomanip> 
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;

    do {
        cout << "Ââåä³òü ðîçì³ð ìàñèâó N(â³ä 5 äî 20): ";
        cin >> N;
        if (N < 5 || N > 20) {
            cout << "Ðîçì³ð ìàñèâó ìàº áóòè â³ä 5 äî 20.\n";
        }
    } while (N < 5 || N > 20);

    int numbers[20];

    for (int i = 0; i < N; i++) {
        cout << "Ââåä³òü åëåìåíò [" << i << "]: ";
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
    cout << "\nÂâåäåíèé ìàñèâ: ";
    for (int i = 0; i < N; i++) {
        cout << numbers[i] << " ";
    }

    cout << "\nÑóìà åëåìåíò³â: " << sum;
    cout << "\nÑåðåäíº àðèôìåòè÷íå: " << fixed << setprecision(2) << average;
    cout << "\nÁ³ëüøèõ çà ñåðåäíº: " << greaterCount;
    cout << "\nÌåíøèõ çà ñåðåäíº: " << smallerCount << endl;

    return 0;

}
