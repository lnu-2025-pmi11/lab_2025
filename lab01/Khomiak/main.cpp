
#include <iostream>
using namespace std;

int main()
{
    int N;
    float sum = 0;
    int more_av = 0;
    int less_av = 0;
    
    do {
        cout << "input size of array from 5 to 20: ";
        cin >> N;
        if (N < 5 || N>20) {
            cout << "error, wron number ";
        }
        else
            break;
    } while (N < 5 || N>20);
    int* arr=new int[N];
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << " number: ";
        cin >> arr[i];
        sum += arr[i];
    }
    double av = sum / N;
    for (int i = 0; i < N; ++i) {
        if (arr[i] > av) {
            ++more_av;
        }
        if (arr[i] < av) {
            ++less_av;
        }
    }
    cout << "array: ";
    for (int i = 0; i < N; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "sum: " << sum << endl;
    cout << "avarage: " << av << endl;
    cout << "more than avarage: " << more_av << endl;
    cout << "less than avarage: " << less_av << endl;
}


