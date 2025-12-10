#include <iostream>
#include<fstream>
using namespace std;
class BankAccout
{
public:
    string accountNumber;
    double balance;
    BankAccout()
    {
        this->accountNumber = "";
        this->balance = 0;
    }
    BankAccout(string accountNumber, int balance)
    {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }
    void deposit(double money)
    {
        balance += money;
    }
    void withdraw(double money)
    {
        if(balance <= 0)
        {
            cout << "You cant withdraw" << endl;
        }else
        {
            balance -= money;
        }
    }
    double getBalance()
    {
        return balance;
    }

    friend ostream& operator<<(ostream& os, BankAccout &bank)
    {
        os << bank.accountNumber << " : " << bank.balance << "$";
        return os;
    }
    friend istream& operator>>(istream& is, BankAccout &bank)
    {
        is >> bank.accountNumber >> bank.balance;
        return is;
    }
    bool operator>(BankAccout &bank)
    { 
        return balance > bank.balance;  
    }
    bool operator<(BankAccout &bank)
    {
        return balance < bank.balance;
        
    }
    bool operator==(BankAccout &bank)
    {
        return balance == bank.balance;
    }
    void show(double depos, double withd);
    ~BankAccout()
    {

    }
};

double maxBalance(BankAccout *bank, int len)
{
    double max = bank[0].balance;
    for(int i = 0; i < len; i++)
    {
        if(bank[i].balance > max)
        {
            max = bank[i].balance;
        }
    }
    return max;
}

double sumBalance(BankAccout *bank, int len)
{
    double sum = 0;
    for(int i = 0; i < len; i++)
    {
        sum += bank[i].balance;
    }
    return sum;
}
void Compr(BankAccout &acc1, BankAccout &acc2)
{
    if(acc1 > acc2)
    {
        cout << acc1;
    }else if(acc1 == acc2)
    {
        cout << acc1 << endl;
        cout << acc2;
    }else
    {
        cout << acc2;
    }
}
void declare(BankAccout *bank, int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << bank[i] << endl;
    }
}
void BankAccout::show(double depos, double withd)
{
    cout << "Balance before deposit: " << getBalance() << "$" << endl;
    deposit(depos);
    cout << "Balance after deposition: " << getBalance() << "$" << endl;
    withdraw(withd);
    cout << "Balance after withdraw: " << getBalance() << "$" << endl;
}
int main() {
    cout << "------------------------------------------" << endl;
    fstream infile("data.txt");
    ofstream result("result.txt");
    if(!infile)
    {
        cerr << "error";
        return 1;
    }
    int len = 5;
    BankAccout *arr = new BankAccout[len];
    for(int i = 0; i < len; i++)
    {
        infile >> arr[i];
    }
    
    result << "Sum: " << sumBalance(arr, len) << endl;
    result << "Max: " << maxBalance(arr, len) << endl;
    declare(arr, len);

    infile.close();
    result.close();
    cout << "------------------------------------------------" << endl;

    BankAccout acc1;
    BankAccout acc2("1111", 400);
    cout << "------------------------" << endl;
    cout << "FIRST ACCOUNT: " << endl;
    acc1.show(0, 5);
    cout << "------------------------" << endl;

    cout << "-----------------------" << endl;
    cout << "SECOND ACCOUNT: " << endl;
    acc2.show(100, 50);
    cout << "---------------------" << endl;
    cout << "Account with bigger balance: ";
    Compr(acc1, acc2);
    return 0;
}
