#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class ComplexPolar {
private:
    double r;   
    double phi; 

public:
    ComplexPolar() : r(1), phi(0) {}
    ComplexPolar(double radius, double angle) : r(radius), phi(angle) {}

    double magnitude() const {
        return r;
    }

    void toCartesian(double& x, double& y) const {
        x = r * cos(phi);
        y = r * sin(phi);
    }

    ComplexPolar operator+(const ComplexPolar& other) const {
        double x1, y1, x2, y2;
        this->toCartesian(x1, y1);
        other.toCartesian(x2, y2);

        double xr = x1 + x2;
        double yr = y1 + y2;

        double newR = sqrt(xr * xr + yr * yr);
        double newPhi = atan2(yr, xr);

        return ComplexPolar(newR, newPhi);
    }

    bool operator>(const ComplexPolar& other) const {
        return this->r > other.r;
    }

    void print() const {
        cout << "r = " << r << ", phi = " << phi << " rad";
    }

   
    void save(ofstream& out) const {
        out << r << " " << phi << "\n";
    }

    void load(ifstream& in) {
        in >> r >> phi;
    }
};


void saveArray(const char* filename, ComplexPolar* arr, int n) {
    ofstream out(filename);
    if (!out) {
        cerr << "Error opening file for writing.\n";
        return;
    }
    out << n << "\n"; 
    for (int i = 0; i < n; i++)
        arr[i].save(out);
    out.close();
}

ComplexPolar* loadArray(const char* filename, int& n) {
    ifstream in(filename);
    if (!in) {
        cerr << "Error opening file for reading.\n";
        n = 0;
        return nullptr;
    }
    in >> n;
    ComplexPolar* arr = new ComplexPolar[n];
    for (int i = 0; i < n; i++)
        arr[i].load(in);
    in.close();
    return arr;
}

int main() {

    
    int n;
    ComplexPolar* arr = loadArray("complex.txt", n);
    if (!arr) return 1;

    cout << "Array loaded from file. Elements: " << n << endl;


    
    cout << "\nCartesian coordinates:\n";
    for (int i = 0; i < n; i++) {
        double x, y;
        arr[i].toCartesian(x, y);
        cout << i + 1 << ") x = " << x << ", y = " << y << endl;
    }


    
    ComplexPolar max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
    }

    cout << "\nThe largest module: ";
    max.print();
    cout << endl;


    
    ComplexPolar sum = arr[0];
    for (int i = 1; i < n; i++) {
        sum = sum + arr[i];
    }

    cout << "\nThe sum in polar form:\n";
    sum.print();
    cout << endl;

    double sx, sy;
    sum.toCartesian(sx, sy);
    cout << "In Cartesian: x = " << sx << ", y = " << sy << endl;


    delete[] arr;
    return 0;
}