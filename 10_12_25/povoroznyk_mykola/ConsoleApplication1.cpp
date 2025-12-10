#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Movie {
public:
	string title;
	double rating;
	Movie() {
		this->title = "";
		this->rating = 0;
	}
	Movie(string title, double rating) {
		this->title = title;
		this->rating = rating;
	}
	~Movie() {

	}

	double getRating() {
		return rating;
	}

	bool operator>(const Movie& c) {
		return this->rating > c.rating;
	}
	bool operator<(const Movie& c) {
		return this->rating < c.rating;
	}
	bool isGood() {
		return rating > 7.0;
	}
	friend ostream& operator<<(ostream& os, const Movie& movie) {
		os << "Film: " << movie.title << ", Rating: " << movie.rating;
		return os;
	}
};

int main() {
	ifstream filein("movies.txt");
	ofstream fileout("movies1.txt");

	if (!filein.is_open() || !fileout.is_open()) {
		cout << "Error" << endl;
		return 1;
	}
	
	const int N = 5;
	const int SIZE = 5;
	Movie movies[SIZE]; 
	int count = 0;
	

	string tempTitle;
	double tempRating;
	while (count < N && getline(filein, tempTitle)) {
		filein >> tempRating;
		filein.ignore(); 
		movies[count] = Movie(tempTitle, tempRating);
		count++;
	}
	if (count == 0) {
		cout << "File is empty!" << endl;
		return 0;
	}

	Movie topMovie = movies[0];
	for (int i = 1; i < count; i++) {
		if (movies[i] > topMovie) { 
			topMovie = movies[i];
		}
	}

	double sum = 0;
	for (int i = 0; i < count; i++) {
		sum += movies[i].getRating();
	}
	double average = sum / count;

	
	cout << "Total: " << count << endl;
	cout << "Best: " << topMovie << endl;
	cout << "Avg: " << average << endl;
	cout << "Good films:" << endl;
	for (int i = 0; i < count; i++) {
		if (movies[i].isGood()) {
			cout << "- " << movies[i] << endl;
		}
	}

	fileout << "Statistics" << endl;
	fileout << topMovie << endl;
	fileout << average << endl;
	fileout << "Good Movies (>7):" << endl;

	for (int i = 0; i < count; i++) {
		if (movies[i].isGood()) {
			fileout << movies[i] << endl; 
		}
	}

	filein.close();
	fileout.close();


	return 0;
}