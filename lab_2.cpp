/*я розумію, що здаю завдання дуже пізно, однак я зараз находжусь за кордоном, і мені не хватило часу на виконання цього завдання раніше. Надіюсь на ваше розуміння)*/
#include <iostream>

using namespace std;

int const N = 2;
int const M = 5;

struct Matrix {

	double arr[N][N];

	Matrix() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) arr[i][j] = 1.0;
				else arr[i][j] = 0.0;
			}
		}
	}
	Matrix(double a, double b, double c, double d) {
		arr[0][0] = a;
		arr[0][1] = b;
		arr[1][0] = c;
		arr[1][1] = d;
	}
	Matrix addition(Matrix& A) {

		Matrix add;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				add.arr[i][j] = arr[i][j] + A.arr[i][j];
			}
		}
		return add;
	}
	double det() {
		return arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
	}
	Matrix transpose() {

		Matrix transposed;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				transposed.arr[i][j] = arr[j][i];
			}
		}

		return transposed;
	}
	void comparison(Matrix& A, Matrix& B) {
		if (A.det() > B.det()) {
			cout << "first matrix's determinant is bigger than second\n";
		}
		else if (A.det() < B.det()) {
			cout << "first matrix's determinant is less than second\n";
		}
		else {
			cout << "both determinants are equal\n";
		}
	}
	void print() {
		for (int i = 0; i < N; i++) {
			cout << "[";
			for (int j = 0; j < N; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "]\n";
		}
		cout << endl;
	}
};
void main() {
	Matrix a, b, c, d, e;
	a = Matrix(1, 2, 3, 1);
	b = Matrix();
	c = Matrix(2, 4, 2.5, 0);
	d = Matrix(1.5, 3, 0, 0);
	e = Matrix(0, 5, 3.2, 2.4);
	//1 завдання
	Matrix matrices[M] = {
	Matrix(1, 2, 3, 1),
	Matrix(),
	Matrix(2, 4, 2.5, 0),
	Matrix(1.5, 3, 0, 0),
	Matrix(0, 5, 3.2, 2.4),
	};
	//2 завдання
	cout << "determinants: \n";
	cout << a.det() << endl;
	cout << b.det() << endl;
	cout << c.det() << endl;
	cout << d.det() << endl;
	cout << e.det() << endl << endl;
	// 3 завдання
	if (a.det() >= b.det() && a.det() >= c.det() && a.det() >= d.det() && a.det() >= e.det()) {
		cout << "highest determinant is " << a.det() << endl;
	}
	else if (b.det() >= a.det() && b.det() >= c.det() && b.det() >= d.det() && b.det() >= e.det()) {
		cout << "highest determinant is " << b.det() << endl;
	}
	else if (c.det() >= a.det() && c.det() >= b.det() && c.det() >= d.det() && c.det() >= e.det()) {
		cout << "highest determinant is " << c.det() << endl;
	}
	else if (d.det() >= a.det() && d.det() >= b.det() && d.det() >= c.det() && d.det() >= e.det()) {
		cout << "highest determinant is " << d.det() << endl;
	}
	else {
		cout << "highest determinant is " << e.det() << endl;
	}
	cout << endl;
	// 4 завдання 
	cout << "sum of two matrixes: \n";
	Matrix f;
	f = a.addition(b);
	f.print();
	// 5 завдання
	cout << "transposed matrixes: \n";
	Matrix g, h, i;
	g = c.transpose();
	g.print();
	h = d.transpose();
	h.print();
	i = e.transpose();
	i.print();
}