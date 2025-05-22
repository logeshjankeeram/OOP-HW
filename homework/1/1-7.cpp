#include <iostream>
using namespace std;

int main () {
    int arr[] = {1,1,2,2,3,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << "Unique values of an array: ";

    for (int i=0 ; i<size; i++) {
        bool unique = true;

        for (int j=0; j<size; j++){
            if (i!=j && arr[i]==arr[j]) {
                unique = false;
                break;
            }
        }
        if (unique) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
    return 0;
}