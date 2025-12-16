#include <iostream>
#include <iomanip>
using namespace std;
class CurrencyUAH {
	
private: 
	double amount = 0.0;
	static constexpr double ExchangerateUSD = 41.1;
	static constexpr double ExchangerateEUR = 45;

public: 
	CurrencyUAH(): amount(0.0) {
	}

	CurrencyUAH(double intialAmount) {
		this->amount = intialAmount;
	}
	
	double toUSD() {
		return this->amount / ExchangerateUSD;
	}
	double toEUR() {
		return this-> amount / ExchangerateEUR;
	}

	CurrencyUAH operator+(const CurrencyUAH& other) const {
		return CurrencyUAH(this->amount + other.amount);
	}

	double getAmount() {
		return amount;
	}
};

int main() {
	const int N = 5;
	CurrencyUAH dailySums[N] = {
		CurrencyUAH(150.75), 
		CurrencyUAH(300.00),
		CurrencyUAH(45.50),
		CurrencyUAH(800.25),
		CurrencyUAH(25.00)
	};


	for (int i = 0; i < N; ++i) {
		cout << "Sum #" << (i + 1) << ": ";
		cout << fixed << setprecision(2);
		cout << dailySums[i].getAmount() << " UAH  "
			<< dailySums[i].toUSD() << " USD  "
			<< dailySums[i].toEUR() << " EUR";
		cout << endl;
	}

	CurrencyUAH total;

	for (int i = 0; i < N; ++i) {
		total = total + dailySums[i];
	}
	cout << fixed << setprecision(2);

	double totalUAH = total.getAmount();

	cout << "Total sum in UAH : " << totalUAH << " UAH" << endl;
	cout << "Total sum in USD: " << total.toUSD() << " USD" << endl;
	cout << "Total sum in EUR: " << total.toEUR() << " EUR" << endl;

	return 0;
	
}
