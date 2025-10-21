#include <iostream>
#include <iomanip>
using namespace std;

void fillArray(int* data, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Enter element [" << i << "]: ";
        cin >> data[i];
    }
}

double calculateSum(int* data, int size) {
    double total = 0;
    for (int i = 0; i < size; i++) {
        total += data[i];
    }
    return total;
}

void printArray(int* data, int size) {
    cout << "Your array: ";
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void showComparison(int* data, int size, double avg) {
    cout << "Elements greater than " << avg << ": ";
    for (int i = 0; i < size; i++) {
        if (data[i] > avg) cout << data[i] << " ";
    }
    cout << endl;

    cout << "Elements smaller than " << avg << ": ";
    for (int i = 0; i < size; i++) {
        if (data[i] < avg) cout << data[i] << " ";
    }
    cout << endl;
}

int main() {
    int length;
    cout << "Enter the length of the array (5-20): ";
    cin >> length;

    if (length < 5 || length > 20) {
        cout << "Invalid length! Please try again." << endl;
        return 0;
    }

    int* nums = new int[length];
    fillArray(nums, length);

    double sum = calculateSum(nums, length);
    double average = sum / length;

    cout << fixed << setprecision(2);
    printArray(nums, length);
    cout << "Sum of elements: " << sum << endl;
    cout << "Average value: " << average << endl;

    showComparison(nums, length, average);

    delete[] nums;
    return 0;
}
