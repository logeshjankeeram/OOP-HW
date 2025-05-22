#include <iostream>
using namespace std;

int overall (int value) {
    int sum = 0;
    while (value != 0) {
        sum += value % 10;
        value /= 10;
    }
    return sum;
}

int main () {
    int value;
    cout << "Enter a value ";
    cin >> value;
    if (value >= 10) {
    cout << "The sum of digits of the value is " << overall(value) << endl;
    }
    else {
        cout << "Enter at least 2-digit value" << endl;
    }
    return 0;
}