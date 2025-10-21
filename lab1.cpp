#include <iostream>
using namespace std;


int main()
{
    int N = 0;
    cout << "Enter size between 5-20: ";
    cin >> N;
    while (N > 20 || N < 5) {
        cout << "Error! Enter again:";
        cin >> N;
    }

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cout << "Enter element [" << i << "]: ";
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    
    double ave = sum / N;
    int bigger_than_ave = 0, smaller_than_ave = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] > ave) {
            bigger_than_ave += 1;
        }
        if (arr[i] < ave) {
            smaller_than_ave += 1;
        }
    }

    cout << "\nARRAY: \n";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    cout << "\nSum of elements: " << sum << '\n';
    cout << "Average: " << ave << '\n';
    cout << "Numbers bigger than average: " << bigger_than_ave << '\n';
    cout << "Numbers smaller than average: " << smaller_than_ave << '\n';




}

