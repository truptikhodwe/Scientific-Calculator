#include "calculator.h"
#include <bits/stdc++.h> // For sqrt, log, pow, error handling

double squareRoot(double n) {
    if (n < 0) {
        return NAN; // Not a Number for negative input
    }
    return sqrt(n);
}

long long factorial(int n) {
    if (n < 0) {
        return -1; // Indicate error for negative input
    }
    if (n == 0) {
        return 1;
    }
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double naturalLog(double n) {
    if (n <= 0) {
        return NAN; // Log is undefined for non-positive numbers
    }
    return log(n);
}

double power(double base, double exponent) {
    return pow(base, exponent);
}