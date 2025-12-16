#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 5;

class Point3D {
private:
    double x;
    double y;
    double z;

public:
    Point3D() : x(0.0), y(0.0), z(0.0) {}

    Point3D(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}

    ~Point3D() {}

    double distanceFromOrigin() const {
        return sqrt(x * x + y * y + z * z);
    }

    double distance(const Point3D& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        double dz = z - other.z;
        return sqrt(dx * dx + dy * dy + dz * dz);
    }

    Point3D operator+(const Point3D& other) const {
        return Point3D(x + other.x, y + other.y, z + other.z);
    }

    bool operator>(const Point3D& other) const {
        return this->distanceFromOrigin() > other.distanceFromOrigin();
    }

    bool operator<(const Point3D& other) const {
        return this->distanceFromOrigin() < other.distanceFromOrigin();
    }

    void print(ostream& os) const {
        ios_base::fmtflags oldFlags = os.flags();
        int oldPrecision = os.precision();

        os << fixed << setprecision(2) << "(" << x << ", " << y << ", " << z << ")";

        os.flags(oldFlags);
        os.precision(oldPrecision);
    }
};

void createInputFile(const char* filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        outFile << "1.0 2.0 3.0" << endl;
        outFile << "-4.5 5.5 -6.5" << endl;
        outFile << "7.0 0.0 0.0" << endl;
        outFile << "0.5 0.5 0.5" << endl;
        outFile << "1.0 1.0 1.0" << endl;
        outFile.close();
        cout << "\nData file '" << filename << "' successfully created." << endl;
    }
    else {
        cerr << "\nError: Cannot create file " << filename << endl;
    }
}

int loadPointsFromFile(const char* filename, Point3D points[]) {
    ifstream inFile(filename);
    double x, y, z;
    int count = 0;

    if (!inFile.is_open()) {
        cerr << "\nError: Cannot open file " << filename << " for reading." << endl;
        return 0;
    }

    cout << "\nLoading data from file '" << filename << "'..." << endl;

    while (count < ARRAY_SIZE && (inFile >> x >> y >> z)) {
        points[count] = Point3D(x, y, z);
        count++;
    }

    inFile.close();
    return count;
}


int main() {
    cout << fixed << setprecision(2);

    cout << "--- 1. Object Creation ---" << endl;
    Point3D p_default;
    Point3D p1(10.0, 20.0, 30.0);
    Point3D p2(5.0, 5.0, 5.0);

    cout << "\n--- 2. Operators and Special Methods ---" << endl;

    Point3D p_sum = p1 + p2;
    cout << "P1: "; p1.print(cout); cout << ", P2: "; p2.print(cout); cout << endl;
    cout << "Sum P1 + P2: "; p_sum.print(cout); cout << endl;

    cout << "Distance of P1 from origin: " << p1.distanceFromOrigin() << endl;

    cout << "Is P1 > P2? " << (p1 > p2 ? "Yes" : "No") << endl;

    cout << "Distance between P1 and P2: " << p1.distance(p2) << endl;

    const char* INPUT_FILE = "points_data_simple.txt";
    const char* OUTPUT_FILE = "results_simple.txt";

    Point3D points[ARRAY_SIZE];

    createInputFile(INPUT_FILE);
    int N = loadPointsFromFile(INPUT_FILE, points);

    if (N == 0) {
        cerr << "\nProgram terminated." << endl;
        return 1;
    }

    cout << "\n--- 3. Array Analysis (" << N << " points) ---" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Point " << i << ": "; points[i].print(cout);
        cout << " (Distance from origin: " << points[i].distanceFromOrigin() << ")" << endl;
    }

    int farthest_index = 0;
    for (int i = 1; i < N; ++i) {
        if (points[i] > points[farthest_index]) {
            farthest_index = i;
        }
    }

    cout << "\nFarthest point from origin (Index " << farthest_index << "): ";
    points[farthest_index].print(cout);
    cout << " (Distance: " << points[farthest_index].distanceFromOrigin() << ")" << endl;

    double total_distance = 0.0;
    for (int i = 0; i < N; ++i) {
        total_distance += points[i].distanceFromOrigin();
    }

    cout << "Total distance of all points from origin: " << total_distance << endl;

    ofstream resFile(OUTPUT_FILE);
    if (resFile.is_open()) {
        resFile << fixed << setprecision(2);
        resFile << "=== Point3D Analysis Results ===" << endl;
        resFile << "Number of points: " << N << endl;
        resFile << "-----------------------------------" << endl;

        resFile << "Farthest point from origin: ";
        points[farthest_index].print(resFile);
        resFile << " (Distance: " << points[farthest_index].distanceFromOrigin() << ")" << endl;

        resFile << "Total distance from origin: " << total_distance << endl;
        resFile << "-----------------------------------" << endl;

        resFile << "Distances between points (i, j):" << endl;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                double dist = points[i].distance(points[j]);
                resFile << "Dist(" << i << ", " << j << "): ";
                points[i].print(resFile);
                resFile << " <-> ";
                points[j].print(resFile);
                resFile << " = " << dist << endl;
            }
        }

        resFile.close();
        cout << "\nResults saved to file '" << OUTPUT_FILE << "'." << endl;
    }
    else {
        cerr << "\nError: Cannot open file " << OUTPUT_FILE << " for writing." << endl;
    }

    return 0;
}