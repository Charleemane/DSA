#include <iostream>

using namespace std;

void displayPrimeFactors(int n, int divisor) {
    if (n <= 1) {
        return;
    }

    if (n % divisor == 0) {
        cout << divisor << " ";
        while (n % divisor == 0) {
            n = n / divisor;
        }
    }

    displayPrimeFactors(n, divisor + 1);
}

int main() {
    int number;

    cout << "Enter a number: ";
    cin >> number;

    if (number <= 1) {
        cout << "Prime factors are not applicable for numbers less than or equal to 1." << endl;
    } else {
        cout << "Prime factors of " << number << " are: ";
        displayPrimeFactors(number, 2);
        cout << endl;
    }

    return 0;
}
