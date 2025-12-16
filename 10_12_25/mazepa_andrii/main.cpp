#include <iostream>
#include <fstream>
#include <locale>
#include <Windows.h>
#include <cmath>

using namespace std;

const int n = 5;

struct Point
{
	int x;
	int y;

	Point(): x(0), y(0) {}
	Point(int x1, int y1): x(x1), y(y1) {}

	friend ostream& operator<<(ostream& os, const Point& p)
	{
		os << "x: " << p.x << " y: " << p.y;
		return os;
	}
	friend istream& operator>>(istream& is, Point& p)
	{
		is >> p.x >> p.y;
		return is;
	}

};

class LineSegment
{
private:
	Point point1;
	Point point2;
public:
	LineSegment(): point1(0,0), point2(1,1) {}
	LineSegment(Point p1, Point p2)
	{
		point1 = p1;
		point2 = p2;
	}
	~LineSegment(){}
	double length()
	{
		double add1 = pow(point2.x - point1.x, 2);
		double add2 = pow(point2.y - point1.y, 2);
		return sqrt(add1 + add2);
	}
	bool operator>(LineSegment& ls)
	{
		return this->length() > ls.length();
	}
	bool operator<(LineSegment& ls)
	{
		return this->length() < ls.length();
	}
	Point midpoint()
	{
		return Point((point1.x + point2.x) / 2, (point1.y + point2.y) / 2);
	}
	bool isParallel(LineSegment& ls)
	{
		double k1 = (point2.y - point1.y) / (point2.x - point1.x);
		double k2 = (ls.point2.y - ls.point1.y) / (ls.point2.x - ls.point1.x);
		return k1 == k2;
	}
	friend ostream& operator<<(ostream& os, const LineSegment& ls)
	{
		os << "p1: " << ls.point1 << " p2: " << ls.point2;
		return os;
	}
	friend istream& operator>>(istream& is, LineSegment& ls)
	{
		is >> ls.point1 >> ls.point2;
		return is;
	}
};

void findLength(LineSegment* arr, double* lengths)
{
	for (int i = 0; i < n; i++)
	{
		lengths[i] = arr[i].length();
	}
}

void findMaxLengths(const double* lengths, int* indeces)
{
	for (int i = 0; i < n; i++)
	{
		indeces[i] = 0;
	}

	double max = 0;

	for (int i = 0; i < n; i++)
	{
		if (max < lengths[i])
		{
			max = lengths[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (lengths[i] == max)
		{
			indeces[i] = 1;
		}
	}
}

double findSum(double* lengths)
{
	double sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += lengths[i];
	}
	
	return sum;
}

double findAvgLength(double* lengths)
{
	return findSum(lengths) / n;
}


void printResult(ostream& os, LineSegment* ls)
{
	double lengths[n];
	int maxIndeces[n];

	findLength(ls, lengths);

	os << "Довжини всіх відрізків:" << endl;
	for (int i = 0; i < n; i++)
	{
		os << "Відрізок[" << i << "]: p1: " << ls[i].midpoint() << " Довжина = " << lengths[i] << endl;
	}
	os << endl;

	double sum = findSum(lengths);
	os << "Сума всіх довжин: " << sum << endl;

	double avg = findAvgLength(lengths);
	os << "Середня довжина: " << avg << endl;


	findMaxLengths(lengths, maxIndeces);

	os << endl << "Найдовший(і) відрізок(ки):" << endl;

	double maxLength = 0;
	bool first = true;

	for (int i = 0; i < n; i++)
	{
		if (maxIndeces[i] == 1)
		{
			if (first) 
			{
				maxLength = lengths[i];
				first = false;
			}
			os << "Відрізок[" << i << "] з довжиною: " << lengths[i] << endl;
		}

	}

	os << endl << "Аналіз паралельності:" << endl;
	bool foundParallel = false;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ls[i].isParallel(ls[j])) {
				os << "Відрізок[" << i << "] та Відрізок[" << j << "] ПАРАЛЕЛЬНІ." << endl;
				foundParallel = true;
			}
		}
	}

	if (!foundParallel) {
		os << "Жодна пара відрізків не є паралельною." << endl;
	}
}



int main()
{
	locale::global(locale("uk_UA.UTF-8"));
	SetConsoleOutputCP(CP_UTF8);

	LineSegment arr[n];
	ifstream in;
	in.open("data.txt");

	if (in.is_open())
	{
		int i = 0;
		LineSegment ls;
		while (i < n && in >> ls)
		{
			arr[i++] = ls;
		}
	}
	else
	{
		cerr << "Помилка: Не вдалося відкрити файл data.txt!" << endl;
		return 1;
	}

	in.close();

	printResult(cout, arr);

	ofstream out;
	out.open("result.txt");
	
	printResult(out, arr);

	out.close();

	return 0;
}

