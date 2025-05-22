#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int value;
    cout << "Enter the value - ";
    cin >> value;

    for (int i=1; i <= value; ++i) {
        int power = i*i;
        cout << "The square of the number " << i << " is " << power << endl;
    }
    return 0;
}