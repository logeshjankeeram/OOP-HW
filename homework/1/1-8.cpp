#include <iostream>
using namespace std;

int main () {
    int arr[] = {1,5,6,3,7,9,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    for (int i=0 ; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++){
            if (arr[j]>arr[j+1]) {
                int position = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = position;
            }
        }

    }
    cout << "The sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}