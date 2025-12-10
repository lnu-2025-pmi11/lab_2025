
#include <iostream>

using namespace std;

class Date 
{
private:
    int day, 
        month, 
        year;

    bool isLeap(int y) const 
    {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    int daysInMonth(int m, int y) const 
    {
        switch (m) 
        {
        case 1: 
        case 3: 
        case 5: 
        case 7: 
        case 8: 
        case 10: 
        case 12:
            return 31;
        case 4: 
        case 6: 
        case 9: 
        case 11:
            return 30;
        case 2:
            if (isLeap(y))
                return 29;
            else
                return 28;
        default:
            return 0;
        }
    }

public:
    
    Date() 
    {
        day = 1;
        month = 1;
        year = 1900;
    }

    Date(int d, int m, int y) 
    {
        day = d;
        month = m;
        year = y;
    }

    
    bool isValid() const 
    {
        if (year < 1 || month < 1 || month > 12)
            return false;
        int daysInMonthT = daysInMonth(month, year);
        return day >= 1 && day <= daysInMonthT;
    }

    
    bool operator<(const Date& other) const 
    {
        if (year != other.year) return year < other.year;
        if (month != other.month) return month < other.month;
        return day < other.day;
    }

    bool operator>(const Date& other) const 
    {
        return other < *this;
    }

    
    void addDays(int d) 
    {
        day += d;
        while (true) 
        {
            int daysInMonthT = daysInMonth(month, year);
            if (day <= daysInMonthT) break;
            day -= daysInMonthT;
            month++;
            if (month > 12) 
            {
                month = 1;
                year++;
            }
        }
    }

    
    int daysUntil(Date other) const 
    {
        Date a = *this;
        Date b = other;

        
        int sign = 1;
        if (a > b) 
        {
            Date temp = a;
            a = b;
            b = temp;
            sign = -1;
        }

        int days = 0;
        while (a < b) 
        {
            a.addDays(1);
            days++;
        }
        return days * sign;
    }

    
    void print() const
    {
        if (day < 10)
            cout << "0";
        cout << day << ".";

        if (month < 10)
            cout << "0";
        cout << month << ".";

        cout << year << endl;
    }
};


int main()
{
    int n;
    cout << "insert count of dates: ";
    cin >> n;

    Date* arr = new Date[n];

    cout << "insert dates (day month year)"<< endl;
    for (int i = 0; i < n; i++) 
    {
        int d, m, y;
        cin >> d >> m >> y;
        arr[i] = Date(d, m, y);
    }


    cout << "check "<< endl;
    for (int i = 0; i < n; i++) 
    {
        arr[i].print();
        if (arr[i].isValid())
            cout << "     valid" << endl;
        else
            cout << "  nonvalid" << endl;
    }

    Date min = arr[0];
    Date max = arr[0];

    for (int i = 1; i < n; i++) 
    {
        if (arr[i].isValid()) 
{
            if (arr[i] < min) min = arr[i];
            if (arr[i] > max) max = arr[i];
        }
    }

    cout << "Earliest: "<<endl;
    min.print();
    cout << "Latest: "<<endl;
    max.print();

    cout << "add 10 days to each"<<endl;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i].isValid()) 
        {
            arr[i].addDays(10);
            arr[i].print();
        }
    }

    cout << "interval between "
        << min.daysUntil(max)
        << " days"<<endl;

    delete[] arr;  
}

