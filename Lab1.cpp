#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    
    int n;
    cout << "write a number between 5 and 20" << endl; 
    do
    {
        cin >> n;
        if (n < 5 || n > 20)
        {
            cout << "invalid" << endl;
        }
    } while (n < 5 || n > 20);
    
    cout <<"=================================" << endl;

    int* numbers = new int[n]();
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum += numbers[i];
    }
    double average = sum / (double)n;
    int countMore = 0;
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > average)
        {
            countMore++;
        }
    }
    
    int countLess = 0;
    for (int i = 0; i < n; i++)
    {
        if (numbers[i] < average)
        {
            countLess++;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    cout << sum<< endl;
    cout << std::fixed << setprecision(2) << average << endl;
    cout << countLess << endl;
    cout << countMore << endl;

}
