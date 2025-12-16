#include <iostream>
#include <vector>
#include <cmath>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D() : x(0.0), y(0.0) {}

    Vector2D(double newX, double newY) : x(newX), y(newY) {}

    double length_squared() const {
        return x * x + y * y;
    }

    double length() const {
        return std::sqrt(x * x + y * y);
    }

    void print() const {
        std::cout << "Vector(" << x << ", " << y << ") | Length: " << length();
    }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    bool operator>(const Vector2D& other) const {
        return this->length_squared() > other.length_squared();
    }

    bool operator<(const Vector2D& other) const {
        return this->length_squared() < other.length_squared();
    }
};

int main() {
    std::cout << "--- 1. Creating 5 vectors ---" << std::endl;
    std::vector<Vector2D> vectors;

    vectors.push_back(Vector2D());
    vectors.push_back(Vector2D(3.0, 4.0));
    vectors.push_back(Vector2D(1.0, 6.0));
    vectors.push_back(Vector2D(8.0, 1.0));
    vectors.push_back(Vector2D(-2.0, 2.0));

    std::cout << "Vectors are created." << std::endl;

    std::cout << "\n--- 2. Finding the longest vector ---" << std::endl;

    if (vectors.empty()) {
        std::cout << "The vector list is empty.." << std::endl;
        return 0;
    }

    Vector2D longest_vector = vectors[0];
    for (size_t i = 1; i < vectors.size(); ++i) {
        if (vectors[i] > longest_vector) {
            longest_vector = vectors[i];
        }
    }

    std::cout << "The longest vector: ";
    longest_vector.print();
    std::cout << std::endl;

    std::cout << "\n--- 3. Calculating the sum of all vectors ---" << std::endl;

    Vector2D sum_vector;

    for (const Vector2D& vec : vectors) {
        sum_vector = sum_vector + vec;
    }

    std::cout << "Vector sum: ";
    sum_vector.print();
    std::cout << std::endl;

    std::cout << "\n--- 4. List of all vectors ---" << std::endl;
    for (size_t i = 0; i < vectors.size(); ++i) {
        std::cout << "Vector " << i + 1 << ": ";
        vectors[i].print();
        std::cout << std::endl;
    }

    return 0;
}
