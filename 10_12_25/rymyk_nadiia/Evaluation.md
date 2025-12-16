# Evaluation — Triangle (rymyk_nadiia)
Summary
-------
The submitted program implements a Triangle class and a main program that reads 5 triples from `input.txt`, constructs triangles, validates them, computes perimeters and areas (Heron's formula), finds the triangle with the largest area, computes total perimeter, prints validation results to console and writes a detailed report to `output.txt`.

Overall score: **14 / 15**

Detailed scoring (total possible 15 points)
-----------------------------------------

Scoring rubric used (mapped from README required items):

- 1) Creation of objects using different constructors — 2 pts  
  - Max: 2 — Awarded: 2  
  - Comment: `Triangle arr[5];` uses default constructor and each `arr[i] = Triangle(a,b,c);` uses parameter constructor. Both constructors are exercised.

- 2) Use of destructor (implicitly) — 1 pt  
  - Max: 1 — Awarded: 1  
  - Comment: No explicit destructor required; class relies on implicit destructor. This satisfies the requirement.

- 3) Use of special methods of the class (isValid, perimeter, area) — 2 pts  
  - Max: 2 — Awarded: 2  
  - Comment: `isValid()` is used for validation output; `perimeter()` and `area()` are used for computing total perimeter and comparison/printing.

- 4) Overloaded operators (>, <) — 2 pts  
  - Max: 2 — Awarded: 2  
  - Comment: Both `operator>` and `operator<` are implemented. `operator>` is used to find the largest triangle.

- 5) Work with an array of objects — 1 pt  
  - Max: 1 — Awarded: 1  
  - Comment: `Triangle arr[5];` and subsequent loop operations meet this requirement.

- 6) Search for maximum / minimum element by criterion — 2 pts  
  - Max: 2 — Awarded: 2  
  - Comment: The program searches for the triangle with the largest area (max) and reports it. (Finding max is implemented; min was not required explicitly beyond "search maximum / minimum", and finding max satisfies the common interpretation.)

- 7) Calculation of sum / collective characteristic — 1.5 pts  
  - Max: 1.5 — Awarded: 1.5  
  - Comment: Total perimeter of all triangles is computed correctly and written to file.

- 8) Output results to the screen — 1 pt  
  - Max: 1 — Awarded: 1  
  - Comment: Validation results are printed to `cout`, and a confirmation message is printed.

- 9) Loading data from file — 1 pt  
  - Max: 1 — Awarded: 1  
  - Comment: Program reads data from `"input.txt"` via `ifstream fin("input.txt");`. The repo includes `input.txt` in the student's folder; the program assumes runtime working directory contains input file (typical for student tasks).

- 10) Saving results to file — 1.5 pts  
  - Max: 1.5 — Awarded: 1.5  
  - Comment: `output.txt` is produced with a clear report (list of triangles, max by area, total perimeter). Good formatting.

Deductions / Issues (why not full 15/15)
---------------------------------------

-1.0 — Robustness around invalid triangles and use of area() when triangle is invalid.

- Explanation: The program uses Heron's formula in `area()` without checking validity (i.e., it computes sqrt(p*(p-a)*(p-b)*(p-c)) for every triangle). For invalid triples (that do not satisfy triangle inequalities) this may produce a negative radicand and result in NaN (or domain error depending on environment). The program still calls `area()` for all triangles when printing and when comparing areas to find the largest triangle. If an invalid triangle appears, area() may be NaN and comparisons could behave unexpectedly, possibly making the incorrect triangle the "largest" or propagating NaN into outputs.

- Example present in `input.txt`: the line `2 3 10` is an invalid triangle (2 + 3 <= 10). The program will mark it "invalid" in console output (good), but still calls `area()` and `perimeter()` and may produce NaN in the file or influence max search.

Recommendation: handle invalid triangles in area() / comparisons:
- Make `area()` return 0 (or throw / set a flag) if `!isValid()`.  
  or
- Ensure comparisons (`operator>`, `operator<`) treat invalid triangles as having area 0 (or always less than valid triangles).
- When printing, explicitly indicate invalid triangles and avoid printing a numeric area (or print "N/A").

Minor notes (no point change)
----------------------------
- The program uses `ifstream fin("input.txt");` — that's normal, but when running from another directory ensure working directory contains the input file (or use a relative path that matches assignment setup).
- Console message has a minor leading space: `cout << "\n Results saved to output.txt\n";` — cosmetic.
- `operator<` is implemented but not used (harmless).

Suggested code changes (small patch idea)
-----------------------------------------
One small defensive change: modify area() to check validity:

```cpp
double area() const {
    if (!isValid()) return 0.0; // or throw / return NAN and handle elsewhere
    double p = perimeter() / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
```

And modify operator> to prefer valid triangles:

```cpp
bool operator>(const Triangle& t) const {
    if (this->isValid() && !t.isValid()) return true;
    if (!this->isValid() && t.isValid()) return false;
    return this->area() > t.area();
}
```

This prevents invalid triangles from interfering with comparisons.

Concluding remarks
------------------
- The submission meets the assignment requirements and is functional for the provided input set.  
- Main functional shortcoming is a robustness issue when invalid triangles are present; otherwise the implementation is clear and well-structured.

Final score: **14 / 15**
