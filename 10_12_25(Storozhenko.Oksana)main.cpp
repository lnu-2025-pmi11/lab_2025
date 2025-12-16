#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const double PI = 3.14;
class Circle {
private:
    double radius;
public:
    Circle() {
        radius = 1;
        cout << "Constructor default, r = " << radius << endl;
    }
    Circle(double r) {
        radius = r;
        cout << "Constructor with param, r = " << radius << endl;
    }
    ~Circle() {}
    double area() {
        return PI * radius * radius;
    }
    double circumference() {
        return 2 * PI * radius;
    }
    double diameter() {
        return 2 * radius;
    }
    bool operator>(Circle other) {
        return area() > other.area();
    }
    bool operator<(Circle other) {
        return area() <other.area();
    }
    double getRadius() {
        return radius;
    }
};
int main() {
    const int N = 5;
    Circle circles[N];
    double r;
    ifstream fin("radius.txt");
    if (fin.is_open()) {
        for (int i = 0; i < N; i++) {
            fin >> r;
            circles[i] = Circle(r); 
        }
        fin.close();
    }
    cout << "\nAll circles:";
    for (int i = 0; i < N; i++) {
        cout << "Circle " << i + 1
            << "r = " << circles[i].getRadius()
            << "area = " << circles[i].area()
            << "diameter = " << circles[i].diameter()
            << endl;
    }
    int maxIndex = 0;
    for (int i = 1; i < N; i++) {
        if (circles[i] > circles[maxIndex]) {
            maxIndex = i;
        }
    }
    double sumArea = 0;
    for (int i = 0; i < N; i++) {
        sumArea += circles[i].area();
    }
    double sumCirc = 0;
    for (int i = 0; i < N; i++) {
        sumCirc += circles[i].circumference();
    }
    double avgCirc = sumCirc / N;
    cout << "\nLargest circle:";
    cout << "Radius = " << circles[maxIndex].getRadius() << endl;
    cout << "Area   = " << circles[maxIndex].area() << endl;
    cout << "\nSum of areas = " << sumArea << endl;
    cout << "Average circumference = " << avgCirc << endl;
    ofstream fout("results.txt");
    fout << "Largest circle radius: " << circles[maxIndex].getRadius() << endl;
    fout << "Largest circle area: " << circles[maxIndex].area() << endl;
    fout << "Sum of areas: " << sumArea << endl;
    fout << "Average circumference: " << avgCirc << endl;
    fout.close();
    return 0;
}