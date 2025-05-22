#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int value;
    cout << "Enter a value: ";
    cin >> value;
    if (prime(value)) {
        cout << value << " is a prime value" << endl;
    } else {
        cout << value << " isn't a prime value" << endl;
    }
    return 0;
}