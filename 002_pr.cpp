#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Rectangle {
private:
    double height;
    double width;
public:
    Rectangle() {
        height = 1;
        width = 1;
    }
    Rectangle(double h, double w) {
        height = h;
        width = w;
    }
    double Area() const{
        return height * width;
    }
    double Perimeter() const{
        return 2 * (height + width);
    }
    friend Rectangle operator*(const Rectangle& r, double k) {
        return Rectangle(r.height * k, r.width * k);
    }
    friend ostream& operator<<(ostream& os, const Rectangle& r) {
        os << "Height: " << r.height << " | Width: " << r.width;
        return os;
    }
    friend istream& operator>>(istream& is, Rectangle& r) {
        is >> r.height >> r.width;
        return is;
    }
    bool operator<(const Rectangle& r) const {
        return this->Area() < r.Area();
    }
    bool operator>(const Rectangle& r) const {
        return this->Area() > r.Area();
    }

};


int main()
{
    /*Клас для роботи з прямокутниками.

    Атрибути:
    width, height(double)

    Методи :
    Конструктори : за замовчуванням(1x1), з параметрами
    area() — площа = w × h
    perimeter() — периметр = 2(w + h)
    Оператор * — масштабування(Rectangle * коефіцієнт)
    Оператор > , < — порівняння за площею
    Завдання в main() :

    Створити масив 5 прямокутників
    Масштабувати деякі з них
    Знайти найбільший прямокутник
    Обчислити суму всіх площ
    Вивести результати*/


    ifstream file1("InFile.txt");
    ofstream file2("OutFile.txt");
    if (!file1.is_open()) {
        cerr << "Problem1\n";
        return 1;
    }
    if (!file2.is_open()) {
        cerr << "Problem2\n";
        return 1;
    }
    int size = 5;
    Rectangle* rectangles = new Rectangle[size];

    for (int i = 0; i < size; i++) {
        file2 << "\nRectangle[" << i + 1 << "]\n";
        file1 >> rectangles[i];
        file2 << rectangles[i];
        if (rectangles[i].Area() <= 0) {
            file2 << "\nIncorrect value in file for rectangle [" << i + 1 << "]!Setting to 1x1\n";
            rectangles[i] = Rectangle(1, 1);
        }
    }

    rectangles[1] = Rectangle(5.0, 4.5);

    file2 << "\n-----RECTANGLES BEFORE MULTIPLICATION-----\n\n";
    for (int i = 0; i < size; i++) {
        file2 << "Rectangle[" << i + 1 << "]: " << rectangles[i] << "\n";
    }

    rectangles[2] = rectangles[2] * 3;
    rectangles[0] = rectangles[0] * 0.5;

    file2 << "\n-----RECTANGLES AFTER MULTIPLICATION-----\n\n";
    for (int i = 0; i < size; i++) {
        file2 << "Rectangle[" << i + 1 << "]: " << rectangles[i] << "\n";
    }

    Rectangle max = rectangles[0];

    for (int i = 0; i < size; i++) {
        if (max < rectangles[i]) {
            max = rectangles[i];
        }
    }

    file2 << "\n\nThe biggest rectangle: " << max;

    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += rectangles[i].Area();
    }

    file2 << "\n\nSum of areas: " << sum;

    delete[] rectangles;
    file1.close();
    file2.close();
    cout << "Check the OutFile :)";
    return 0;
}


