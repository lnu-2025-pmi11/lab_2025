#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip> //setw

using namespace std;

class Temperature {
private:
    double celsius;

public:
    Temperature() : celsius(0.0) { }

    Temperature(double c) : celsius(c) { }

   
    ~Temperature() { }

    double getCelsius() const {
        return celsius;
    }

    void setCelsius(double c) {
        celsius = c;
    }

    double toFahrenheit() const {
        return celsius * 9.0 / 5.0 + 32.0;
    }

    double toKelvin() const {
        return celsius + 273.15;
    }

    bool operator>(const Temperature& other) const {
        return this->celsius > other.celsius;
    }

    bool operator<(const Temperature& other) const {
        return this->celsius < other.celsius;
    }

    Temperature operator+(const Temperature& other) const {
        return Temperature(this->celsius + other.celsius);
    }

    friend ostream& operator<<(ostream& os, const Temperature& t);
    friend istream& operator>>(istream& is, Temperature& t);
};

ostream& operator<<(ostream& os, const Temperature& t) {
    os << t.celsius;
    return os;
}

istream& operator>>(istream& is, Temperature& t) {
    is >> t.celsius;
    return is;
}

void printTemp(Temperature* arr,int size ) {
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    

    Temperature t1Default;          
    Temperature t2Param(25.5);
    


    string path = "temps.txt";
    
    const int size = 5;
    Temperature* temps = new Temperature[size];

    ifstream inf(path);
    if (!inf.is_open()) { cout << "path error"; }
    else {
        for (int i = 0; i < size; i++)
        {
            inf >> temps[i];
        }
        ;
    }
    inf.close();

    cout << "Array of temperatures:";
    printTemp(temps, size);

    
    cout << "Array of temperatures(Kelvin):";
    for (int i = 0; i < size; i++)
    {
        cout<<temps[i].toKelvin()<<" ";
    }
    cout << endl;

    cout << "Array of temperatures(Fahrenheit):";
    for (int i = 0; i < size; i++)
    {
        cout<<temps[i].toFahrenheit()<<" ";
    }
    cout << endl;
  

    double min = temps[0].getCelsius();
    double max = temps[0].getCelsius();

    for (int i = 0; i < size; i++)
    {
        if (temps[i].getCelsius() < min) { min = temps[i].getCelsius(); }
        if (temps[i].getCelsius() > max) { max = temps[i].getCelsius(); }
    }

    cout << "min: " << min << endl;
    cout << "max: " << max << endl;

    double avrg = 0;
    for (int i = 0; i < size; i++)
    {
        avrg += temps[i].getCelsius();
    }
    avrg = avrg / size;
    cout << "Avrg: " << avrg << endl;


    delete[] temps;
    return 0;
}
