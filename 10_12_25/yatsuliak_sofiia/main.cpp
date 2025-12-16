#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <Windows.h>
using namespace std;

class ScientificNumber {
private:
    double mantissa;
    int exponent;

    void normalize() {
        if (mantissa == 0) {
            exponent = 0;
            return;
        }

        while (fabs(mantissa) >= 10) {
            mantissa /= 10;
            exponent++;
        }
        while (fabs(mantissa) < 1) {
            mantissa *= 10;
            exponent--;
        }
    }

public:
    ScientificNumber() {
        mantissa = 0;
        exponent = 0;
    }

    ScientificNumber(double m, int e) {
        mantissa = m;
        exponent = e;
        normalize();
    }

    ScientificNumber(const ScientificNumber& other) {
        mantissa = other.mantissa;
        exponent = other.exponent;
    }

    double toDouble() const {
        return mantissa * pow(10, exponent);
    }

    bool operator>(const ScientificNumber& other) const {
        return this->toDouble() > other.toDouble();
    }

    ScientificNumber operator+(const ScientificNumber& other) const {
        double value = this->toDouble() + other.toDouble();

        int exp = 0;
        if (value != 0) {
            while (fabs(value) >= 10) {
                value /= 10;
                exp++;
            }
            while (fabs(value) < 1) {
                value *= 10;
                exp--;
            }
        }
        return ScientificNumber(value, exp);
    }

    void print(ostream& out) const {
        out << mantissa << " * 10^" << exponent;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open()) {
        cout << "Не вдалося відкрити вхідний файл!\n";
        return 1;
    }

    int n = 5;
    vector<ScientificNumber> arr(n);

    for (int i = 0; i < n; i++) {
        double m;
        int e;
        fin >> m >> e;
        arr[i] = ScientificNumber(m, e);
    }

    ScientificNumber maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    ScientificNumber sum = arr[0];
    for (int i = 1; i < n; i++) {
        sum = sum + arr[i];
    }

    fout << "Числа у науковому форматі:\n";
    for (int i = 0; i < n; i++) {
        arr[i].print(fout);
        fout << " = " << arr[i].toDouble() << "\n";
    }

    fout << "\nНайбільше число: ";
    maxVal.print(fout);

    fout << "\nСума: ";
    sum.print(fout);
    fout << "\n";

    fin.close();
    fout.close();

    cout << "Готово! Результати записано у output.txt\n";
    return 0;
}
