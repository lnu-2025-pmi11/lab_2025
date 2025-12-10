#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int calculateGCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b > 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Rational {
private:
    int numerator;
    int denominator;

    void reduce() {
        if (denominator == 0) {
            cout << "Error: Denominator cannot be zero! Setting to 1." << endl;
            denominator = 1;
        }
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int gcd = calculateGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

public:
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int p, int q) {
        numerator = p;
        denominator = q;
        reduce();
    }

    ~Rational() {
    }

    double toDouble() {
        return (double)numerator / denominator;
    }

    void print() {
        cout << numerator << "/" << denominator;
    }

    void printToFile(ofstream& file) {
        file << numerator << "/" << denominator;
    }

    void set(int p, int q) {
        numerator = p;
        denominator = q;
        reduce();
    }

    Rational operator+(Rational other) {
        int newNum = numerator * other.denominator + other.numerator * denominator;
        int newDen = denominator * other.denominator;
        return Rational(newNum, newDen);
    }

    Rational operator*(Rational other) {
        return Rational(numerator * other.numerator, denominator * other.denominator);
    }

    bool operator>(Rational other) {
        return this->toDouble() > other.toDouble();
    }

    bool operator<(Rational other) {
        return this->toDouble() < other.toDouble();
    }
};

void createTestFile() {
    ofstream file("data.txt");
    if (file.is_open()) {
        file << 1 << " " << 2 << endl;
        file << 3 << " " << 4 << endl;
        file << 5 << " " << 1 << endl;
        file << 2 << " " << 8 << endl;
        file << 7 << " " << 3 << endl;
        file.close();
        cout << "File 'data.txt' created successfully." << endl;
    }
    else {
        cout << "Error creating file!" << endl;
    }
}

int main() {
    createTestFile();

    cout << "--- DEMONSTRATION START ---" << endl;

    Rational r1;
    Rational r2(6, 8);

    cout << "Object r1 (default): "; r1.print(); cout << endl;
    cout << "Object r2 (param 6/8): "; r2.print(); cout << endl;

    const int SIZE = 5;
    Rational arr[SIZE];

    ifstream inputFile("data.txt");
    if (!inputFile.is_open()) {
        cout << "Cannot open data.txt" << endl;
        return 1;
    }

    cout << "\n--- Loading array from file ---" << endl;
    int p, q;
    for (int i = 0; i < SIZE; i++) {
        inputFile >> p >> q;
        arr[i].set(p, q);
        cout << "Read fraction #" << i + 1 << ": ";
        arr[i].print();
        cout << endl;
    }
    inputFile.close();

    Rational maxRat = arr[0];
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] > maxRat) {
            maxRat = arr[i];
        }
    }
    cout << "\nMax fraction is: "; maxRat.print(); cout << " (" << maxRat.toDouble() << ")" << endl;

    Rational sumRat(0, 1);
    for (int i = 0; i < SIZE; i++) {
        sumRat = sumRat + arr[i];
    }
    cout << "Sum of all fractions: "; sumRat.print(); cout << endl;

    Rational product = arr[0] * arr[1];
    cout << "Product of first two fractions: "; product.print(); cout << endl;

    ofstream outputFile("results.txt");
    if (outputFile.is_open()) {
        outputFile << "--- Results ---" << endl;
        outputFile << "Max fraction: ";
        maxRat.printToFile(outputFile);
        outputFile << endl;

        outputFile << "Sum of fractions: ";
        sumRat.printToFile(outputFile);
        outputFile << endl;

        outputFile.close();
        cout << "\nResults saved to 'results.txt'." << endl;
    }
    else {
        cout << "Error writing results!" << endl;
    }

    cout << "\n--- End of Main ---" << endl;
    return 0;
}
