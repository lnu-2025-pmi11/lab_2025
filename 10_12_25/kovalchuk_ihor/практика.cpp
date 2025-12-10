#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

class Quadratic {
private:
    double a, b, c;

public:
    Quadratic() : a(0), b(0), c(0) {}
    Quadratic(double a, double b, double c) : a(a), b(b), c(c) {}

    double evaluate(double x) const {
        return a * x * x + b * x + c;
    }

    string findRoots() const {
        double D = b * b - 4 * a * c;
        if (D < 0) return "Коренів немає (D < 0)";

        if (a == 0) {
            if (b == 0) return "Немає коренів";
            return "Лінійний корінь: x = " + to_string(-c / b);
        }

        double x1 = (-b + sqrt(D)) / (2 * a);
        double x2 = (-b - sqrt(D)) / (2 * a);

        if (D == 0)
            return "Один корінь: x = " + to_string(x1);

        return "Два корені: x1 = " + to_string(x1) + ", x2 = " + to_string(x2);
    }

    Quadratic operator+(const Quadratic& other) const {
        return Quadratic(a + other.a, b + other.b, c + other.c);
    }

    string toString() const {
        return to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c);
    }
};

int main() {
    setlocale(LC_ALL, "Ukrainian");
    Quadratic arr[5] = {
        Quadratic(1, 2, 3),
        Quadratic(2, -1, 0),
        Quadratic(-1, 4, 1),
        Quadratic(0.5, -2, 2),
        Quadratic(3, 0, -5)
    };

    double x = 2;

    // === ФАЙЛ ДЛЯ ЗАПИСУ ===
    ofstream fout("input.txt");

    if (!fout.is_open()) {
        cout << "Помилка відкриття файлу!\n";
        return 1;
    }

    fout << "Значення поліномів у точці x = 2:\n\n";

    double maxVal = arr[0].evaluate(x);
    int maxIndex = 0;

    for (int i = 0; i < 5; i++) {
        double val = arr[i].evaluate(x);

        fout << i + 1 << ") " << arr[i].toString() << " = " << val << "\n";

        if (val > maxVal) {
            maxVal = val;
            maxIndex = i;
        }
    }

    fout << "\nПоліном з найбільшим значенням у x = 2:\n";
    fout << arr[maxIndex].toString() << " = " << maxVal << "\n\n";

    
    Quadratic sum = arr[0];
    for (int i = 1; i < 5; i++) sum = sum + arr[i];

    fout << "Сума всіх поліномів:\n";
    fout << sum.toString() << "\n";

    fout << "\nКорені суми поліномів:\n";
    fout << sum.findRoots() << "\n";

    fout.close();

    cout << "Дані успішно записано у input.txt\n";

    return 0;
}
