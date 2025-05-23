#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    string original;
    char newDigit;
    cin >> original >> newDigit;

    int originalNum = stoi(original);
    string newNumberStr = newDigit + original;
    int newNumber = stoi(newNumberStr);

    if (isPrime(originalNum) && isPrime(newNumber))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
