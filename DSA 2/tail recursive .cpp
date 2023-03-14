#include <iostream>
using namespace std;

// Original function
int factorial(int n) {
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

// Tail recursive function
int tailFactorial(int n, int accumulator = 1) {
    if (n == 0)
        return accumulator;
    else
        return tailFactorial(n - 1, n * accumulator);
}

int main() {
    cout << "Factorial of 5: " << factorial(5) << endl;
    cout << "Tail Recursive Factorial of 5: " << tailFactorial(5) << endl;
    return 0;
}
