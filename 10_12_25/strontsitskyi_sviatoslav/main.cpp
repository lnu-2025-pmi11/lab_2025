#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Car {
private:
	string brand;
	double mileage;
public:
	Car() {
		this->brand = "Unknown";
		this->mileage = 0.0;
	}
	Car(string str, double km = 0.0) {
		this->brand = str;
		this->mileage = km;
	}
	void drive(double km) {
		if (km > 0) {
			mileage += km;
		}
	}

	friend istream& operator>>(istream& is, Car& a) {
		return is >> a.brand >> a.mileage;
	}

	friend ostream& operator<<(ostream& os, const Car& a) {
		return os << a.brand << " " << a.mileage << " km";
	}

	double getMileage() const {
		return mileage;
	}

	bool operator<(const Car& a) {
		return this->mileage < a.mileage;
	}
	bool operator>(const Car& a) {
		return this->mileage > a.mileage;
	}
	string getCondition() {
		if (mileage >= 0 && mileage <= 50000.0) return "Excelent";
		else if (mileage <= 100000.0) return "Good";
		else if (mileage <= 200000.0) return "Not bad";
		else if (mileage >= 200001.0) return "Bad";
	}
	~Car() {};
};

int main() {

	const int n = 5;
	Car array[n];
	ifstream infile("data.txt");
	if (!infile.is_open()) {
		cerr << "Problem";
		return 1;
	}
	for (int i = 0; i < n; ++i) {
		infile >> array[i];
	}
	infile.close();

	Car min = array[0];
	for (int i = 0; i < n; ++i) {
		if (min > array[i]) {
			min = array[i];
		}
	}
	double sum = 0.0;
	for (int i = 0; i < n; ++i) {
		sum += array[i].getMileage();
	}

	ofstream outfile("result.txt");
	if (!outfile.is_open()) {
		cerr << "Problem";
		infile.close();
		return 0;
	}
	outfile << "Minimal: " << min << endl;
	outfile << "Average: " << sum / n << " km" << endl;
	
	for (int i = 0; i < n; ++i) {
		cout << array[i] << " ";
		cout << array[i].getCondition() << endl;
	}
	outfile.close();

	return 0;
}