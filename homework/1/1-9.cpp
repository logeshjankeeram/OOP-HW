#include <iostream>
using namespace std;

int factorial(int a) {
    if (a==0 || a==1) {
        return 1;
    }
    if (a<0) {
        return 0;
    }
    return a*factorial(a-1);
}

int main() {
    int value;
    cout << "Enter a value - ";
    cin >> value;
    cout << "The factorial of the value is - " << factorial(value) << endl;
    return 0;
}