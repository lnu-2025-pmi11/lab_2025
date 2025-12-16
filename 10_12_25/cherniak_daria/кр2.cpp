#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Laptop
{
private:
    string model;
    int ram;

public:
    Laptop() {
        model = "Unknown";
        ram = 4;
    }

    Laptop(string m, int r) {
        model = m;
        ram = r;
    }

    bool isGaming() const {
        return ram > 16;
    }

    bool operator>(const Laptop& other) const {
        return ram > other.ram;
    }

    bool operator<(const Laptop& other) const {
        return ram < other.ram;
    }

    void upgrade(int additionalRAM) {
        if (additionalRAM > 0)
            ram += additionalRAM;
    }

    void print(ostream& out) const {
        out << "Model: " << model << ", RAM: " << ram << " GB";
    }

    int getRAM() const { return ram; }
    string getModel() const { return model; }
};

void printBoth(const string& text, ofstream& fout)
{
    cout << text;
    fout << text;
}

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin) {
        cout << "Error: Cannot open input.txt\n";
        return 1;
    }

    int n = 5;
    Laptop* arr = new Laptop[n];

    string model;
    int ram;

    for (int i = 0; i < n; i++) {
        fin >> model >> ram;
        arr[i] = Laptop(model, ram);
    }

    Laptop maxLaptop = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxLaptop)
            maxLaptop = arr[i];
    }

    printBoth("Most powerful laptop:\n", fout);
    maxLaptop.print(cout);
    cout << endl;
    maxLaptop.print(fout);
    fout << "\n\n";

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i].getRAM();

    double avg = (double)sum / n;

    printBoth("Average RAM: " + to_string(avg) + " GB\n\n", fout);

    arr[1].upgrade(8);
    arr[3].upgrade(4);

    printBoth("After upgrades:\n", fout);

    for (int i = 0; i < n; i++) {
        arr[i].print(cout);
        cout << endl;
        arr[i].print(fout);
        fout << endl;
    }
    printBoth("\n", fout);

    printBoth("Gaming laptops (RAM > 16 GB):\n", fout);

    for (int i = 0; i < n; i++) {
        if (arr[i].isGaming()) {
            arr[i].print(cout);
            cout << endl;
            arr[i].print(fout);
            fout << endl;
        }
    }

    printBoth("\nAll laptops:\n", fout);

    for (int i = 0; i < n; i++) {
        arr[i].print(cout);
        cout << endl;
        arr[i].print(fout);
        fout << endl;
    }

    delete[] arr;
    fin.close();
    fout.close();

    printBoth("\nDone! Results saved in output.txt\n", fout);

    return 0;
}

