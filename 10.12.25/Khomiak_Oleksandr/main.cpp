#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int number = 5;
class Flight {
private:
    string flightNumber;
    double duration;
public:
    Flight();
    Flight(string f_n, double dur);
    ~Flight();
    double duration_in_minutes();
    bool is_fast_flight();
    bool operator<(Flight& F);
    bool operator>(Flight& F);
    double avarage();
    friend ostream& operator<< (ostream & os, const Flight & F);
    friend istream& operator>>(istream& is, Flight& F); 
};
int main()
{
    char choice;
    cout << "choose how do you want to input information A(by yourself) or B(by file): ";
    cin >> choice; 
    Flight* flights = new Flight[number];
    ofstream output("output.txt");
    if (!output.is_open()) {
        cout << "error";
        return 1;
    }
    if (choice == 'A' || choice == 'a') {
        cout << "insert number and duration of flights: ";
        for (int i = 0; i < number; ++i) {
            cin >> flights[i];
        }
    }
    if (choice == 'B' || choice == 'b') {
        ifstream file("flights.txt");
        if (!file.is_open()) {
            cout << "cannot find the file";
            delete[] flights;
            return 1;
        }
        string number_of_flights;
        double dur;
        int i = 0;
        while ( i < number && file >> number_of_flights >> dur) {
            flights[i] = Flight(number_of_flights, dur);
            ++i;
        }
        file.close();
    }
    Flight max = flights[0];
    Flight min = flights[0];
    for (int i = 1; i < number; ++i) {
        if (flights[i] > max) {
            max = flights[i];
        }
        if (flights[i] < min) {
            min = flights[i];
        }
    }
    output << "Flights: " << endl;
    for (int i = 0; i < number; ++i) {
        output << flights[i];
    }
    output << "short flights:" << endl;
    for (int i = 0; i < number; ++i) {
        if (flights[i].is_fast_flight()) output << flights[i];
    }
    output << "flight with max duration: " << endl;
    output << max;
    output << "flight with min duration: " << endl;
    output << min;
    output << "average duration: " << flights->avarage();
    output.close();
    delete[] flights;
    return 0;
}
Flight::Flight() {
    flightNumber = "empty";
    duration = 0.0;
}

Flight::Flight(string f_n, double dur)
{
    flightNumber = f_n;
    duration = dur;
}

Flight::~Flight()
{
}

double Flight::duration_in_minutes()
{
    double dur_in_min;
    if (duration < 0) {
        cout << "duration can`t be negative, duration is equalised to 0";
        dur_in_min = 0.0;
        return dur_in_min;
    }
    dur_in_min = this->duration * 60;
    return dur_in_min;
}

bool Flight::is_fast_flight()
{
    if (duration < 4) {
        return true;
    }
    return false;
}

bool Flight::operator<(Flight& F)
{
    if (this->duration < F.duration) {
        return true;
    }
    return false;  
}

bool Flight::operator>(Flight& F)
{
    if (this->duration > F.duration) {
        return true;
    }
    return false;
}

double Flight::avarage()
{
    double sum = 0;
    for (int i = 0; i < number; ++i) sum += this[i].duration;
    return sum / number;
}

ostream& operator<<(ostream& os, const Flight& F)
{
    os << "Flight`s number: " << F.flightNumber << endl;
    os << "Flight`s duration: " << F.duration << endl;
    return os;
}

istream& operator>>(istream& is, Flight& F)
{
    is >> F.flightNumber >> F.duration;
    return is;
}
