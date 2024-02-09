#include <iostream>
#include <cmath>
#include <iomanip>

#define TOLERANCE 0.05 // It's clearer to rename this to reflect its purpose
#define f(x) (pow(M_E,-x)) // Use M_E for the base of the natural logarithm

using namespace std;

void fixedPoint(double x) {
    double X, Xnext, error;
    int i = 0; // Starting from 0 to count the first iteration correctly

    // Print headers outside the loop
    cout << "No. of iteration" << setw(15) << " Xn" << setw(20) << "Xn+1" << setw(20) << "Error" << endl;

    // Initialize variables
    X = x; // Initial guess
    error = TOLERANCE; // Initialize error to start the loop

    do {
        Xnext = f(X); // Calculate the next value using the current value
        error = fabs((Xnext - X) / Xnext); // Correct error calculation
        i++; // Increment iteration counter
        cout << i << setw(30) << X << setw(20) << Xnext << setw(20) << error << endl;
        X = Xnext; // Update X for the next iteration
    } while (error >= TOLERANCE); // Continue until the error is less than the tolerance
}

int main() {
    double n;
    cout << "Enter a value: " << endl;
    cin >> n;
    fixedPoint(n);

    return 0;
}
