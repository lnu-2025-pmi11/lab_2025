#include <iostream>
#include <string>
#include <fstream>
#include <iomanip> 


using namespace std;

class Student {
public:
    string name;
    double score;

    Student() : name(""), score(0.0) {}
    Student(string n, double s) : name(n), score(0.0) { setScore(s); }

    bool isValid() const { return score >= 0.0 && score <= 100.0; }


    bool setScore(double s) {
        if (s >= 0.0 && s <= 100.0) {
            score = s;
            return true;
        }
        return false;
    }

    bool operator>(const Student& other) const {
        return score > other.score;
    }
};


int main() {
	
    const int N = 5;
    Student students[N];

    cout << "Enter info for 5 students.\n";

    for (int i = 0; i < N; ++i) {
        cout << "\nStudent#" << (i + 1) << "\n";
      
        cout << "  Name: ";
        getline(cin, students[i].name);
        if (students[i].name.empty()) {
            
            cout << " Name cant be empty. Pls enter again.\n";
            --i;
            continue;
        }

       
        cout << "  Grates (0-100): ";
        double s;
        if (!(cin >> s)) {
            cout << "  Input error — a number is required. Please try again.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            --i;
            continue;
        }
        cin.ignore(10000, '\n'); 

        if (!students[i].setScore(s)) {
            cout << " The score must be between 0 and 100. Please try again.\n";
            --i;
            continue;
        }
    }

  
    bool allValid = true;
    Student best = students[0];
    double sum = 0.0;
    for (int i = 0; i < N; ++i) {
        if (!students[i].isValid()) allValid = false;
        if (students[i] > best) best = students[i];
        sum += students[i].score;
    }

    double average = sum / N;


    cout << "\n=== Results ===\n";
    if (!allValid) cout << "Warning: There is incorrect data!\n";
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << ". " << students[i].name << " — "
            << fixed << setprecision(2) << students[i].score << "\n";
    }
    cout << "\nThe best students: " << best.name << " ("
        << fixed << setprecision(2) << best.score << ")\n";
    cout << "Average grates: " << fixed << setprecision(2) << average << "\n";

    ofstream fout("results.txt");
    if (fout) {
        fout << "List of students:\n";
        for (int i = 0; i < N; ++i) {
            fout << students[i].name << ", " << fixed << setprecision(2) << students[i].score << "\n";
        }
        fout << "\nThe Best students: " << best.name << ", " << fixed << setprecision(2) << best.score << "\n";
        fout << "Average points of group " << fixed << setprecision(2) << average << "\n";
        fout.close();
        cout << "Results have been saved in results.txt\n";
    }
    else {
        cout <<" Failed to open the file for writing.\n";
    }

    return 0;
}