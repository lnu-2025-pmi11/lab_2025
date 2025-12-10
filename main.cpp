#include <iostream>
#include <fstream>
using namespace std;

class Worker {
public:
	string name;
	double salary;

	double RaiseSalary(double percent) {
		return (salary + salary*percent/100);
	}
	double CalculateTax() {
		return salary * 18 / 100;
	}

	bool operator>(const Worker& other) const {
		return this->salary > other.salary;
	}
};

int main() {
	Worker workers[5];

	ifstream inputFile("names.txt");
	if (!inputFile.is_open()) {
		cerr << "error, couldn't open file" << endl;
	
	}

	for (int i = 0; i < 5; i++) {
		inputFile >> workers[i].name >> workers[i].salary;
	}
	inputFile.close();


	for (int i = 0; i < 5; i++) {
		cout << workers[i].name << " " << workers[i].salary << " " << workers[i].CalculateTax() << endl;
	}
	

	cout << "how much ppl would you like to give a raise ?" << endl;
	int  number;
	cin >> number;
	while (number > 5) {
		cout << "theres not that many workers, enter again" << endl;
		cin >> number;
	}

	cout << "enter which worker you would like to give a raise" << endl;
	int* numbers = new int[number];
	for (int i = 0; i < number; i++) {
		cin >> numbers[i];
	}

	double percent;
	cout << "enter a percent of the raise" << endl;
	cin >> percent;
	
	 int i = 0, n=0;
	 while(i < 5, n<number){
		if (i == numbers[n] -1) {
			workers[i].salary = workers[i].RaiseSalary(percent);
			
			n++;
		}
		i++;
	}

	 ofstream outputFile("data.txt");
	 if (!outputFile.is_open()) {
		 cerr << "error, couldn't open file" << endl;

	 }


	cout << "UPDATED TABLE" << endl;
	for (int i = 0; i < 5; i++) {
		cout << workers[i].name << " " << workers[i].salary << " " << workers[i].CalculateTax() << endl;
		outputFile << workers[i].name << " " << workers[i].salary << " " << workers[i].CalculateTax() << endl;
	}

	Worker MaxSalary = workers[0];
	for (int i = 0; i < 5; i++) {
		if (workers[i] > MaxSalary) {
			MaxSalary = workers[i];
		}
	}
	cout << endl;
	cout << "the worker with the highest pay is " << MaxSalary.name << endl;
	outputFile << endl;
	outputFile << "the worker with the highest pay is " << MaxSalary.name << endl;

	double totalSalary = 0;
	double totalTax = 0;
	for (int i = 0; i < 5; i++) {
		totalSalary += workers[i].salary;
		totalTax += workers[i].CalculateTax();
	}

	cout << "total amount of salary is " << totalSalary << endl;
	cout << "total amount of taxes is " << totalTax << endl;
	outputFile << "total amount of salary is " << totalSalary << endl;
	outputFile << "total amount of taxes is " << totalTax << endl;

	outputFile.close();

}
