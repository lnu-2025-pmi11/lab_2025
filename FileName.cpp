#include <iostream> 
#include <iomanip>
using namespace std;
int main() {
	int N;
    do {
        cout << "Write down size of N (from 5 to 20): ";
        cin >> N;
        if (N < 5 || N > 20) {
            cout << " Mistake! The size should to be from 5 to 20.\n";
        }
    } while (N < 5 || N > 20);

    int numbers[20]; 
    for (int i = 0; i < N; i++) {
        cout << "Write down element [" << i << "]: ";
        cin >> numbers[i];
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += numbers[i];
    }
    double average = static_cast<double>(sum) / N;
    int greater = 0, smaller = 0;
    for (int i = 0; i < N; i++) {
        if (numbers[i] > average) greater++;
        else if (numbers[i] < average) smaller++;
    }
    cout << "\nWrite down massif: ";
    for (int i = 0; i < N; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\nSum of elements: " << sum;
    cout << "\nAverage: " << fixed << setprecision(2) << average;
    cout << "\nAmount of nombers > Averege: " << greater;
    cout << "\nAmount of nombers < Averege: " << smaller << endl;
    return 0;
}
