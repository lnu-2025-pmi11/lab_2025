#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Triangle {
private:
    double a, b, c;

public:
    Triangle() : a(0), b(0), c(0) {}
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}

    bool isValid() const {
        return (a + b > c && a + c > b && b + c > a);
    }

    double perimeter() const {
        return a + b + c;
    }

    double area() const {
        double p = perimeter() / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    bool operator>(const Triangle& t) const {
        return this->area() > t.area();
    }

    bool operator<(const Triangle& t) const {
        return this->area() < t.area();
    }

    void print(ostream& out) const {
        out << "Triangle: a=" << a
            << " b=" << b
            << " c=" << c
            << "  Perimeter=" << perimeter()
            << "  Area=" << area() << endl;
    }
};

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cout << "Error opening input.txt" << endl;
        return 1;
    }

    Triangle arr[5];
    for (int i = 0; i < 5; i++) {
        double a, b, c;
        fin >> a >> b >> c;
        arr[i] = Triangle(a, b, c);
    }
    fin.close();

    cout << "Triangle validation:\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ") ";
        if (arr[i].isValid()) cout << "valid\n";
        else cout << "invalid\n";
    }

    Triangle maxT = arr[0];
    for (int i = 1; i < 5; i++)
        if (arr[i] > maxT)
            maxT = arr[i];

    double totalPerimeter = 0;
    for (int i = 0; i < 5; i++)
        totalPerimeter += arr[i].perimeter();

    ofstream fout("output.txt");
    if (!fout) {
        cout << "Error creating output.txt" << endl;
        return 1;
    }

    fout << "=== Program results ===\n\n";

    fout << "--- All triangles ---\n";
    for (int i = 0; i < 5; i++)
        arr[i].print(fout);

    fout << "\n--- Triangle with the largest area ---\n";
    maxT.print(fout);

    fout << "\nTotal perimeter of all triangles: "
        << totalPerimeter << endl;

    fout.close();

    cout << "\n Results saved to output.txt\n";

    return 0;
}
