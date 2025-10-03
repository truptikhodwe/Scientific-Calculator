#include <iostream>
#include "calculator.h"
using namespace std;

void showMenu() {
    cout << "\n--- Scientific Calculator Menu ---\n";
    cout << "1. Square Root (√x)\n";
    cout << "2. Factorial (!x)\n";
    cout << "3. Natural Logarithm (ln(x))\n";
    cout << "4. Power (x^b)\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    double num1, num2;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a number: ";
                cin >> num1;
                cout << "Result: " << squareRoot(num1) << endl;
                break;
            case 2:
                cout << "Enter an integer: ";
                cin >> num1;
                cout << "Result: " << factorial(static_cast<int>(num1)) << endl;
                break;
            case 3:
                cout << "Enter a number: ";
                cin >> num1;
                cout << "Result: " << naturalLog(num1) << endl;
                break;
            case 4:
                cout << "Enter the base (x): ";
                cin >> num1;
                cout << "Enter the exponent (b): ";
                cin >> num2;
                cout << "Result: " << power(num1, num2) << endl;
                break;
            case 5:
                cout << "Exiting calculator. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}