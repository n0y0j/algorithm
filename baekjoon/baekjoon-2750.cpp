#include <iostream>
using namespace std;

void InsertionSort(int arr[], int size) {
    int key, j;

    for(int i = 1; i < size; i++) {
        
        key = arr[i];
        
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
                arr[j+1] = arr[j];
        }

        arr[j+1] = key;

    }
}


int main() {
    int size, n;
    cin >> size;
    int arr[size];

    for (int i=0; i<size; i++) {
        cin >> n;
        arr[i] = n;
    }

    InsertionSort(arr, size);

     for (int i=0; i<size; i++) {
        cout << arr[i] << endl;
    }
}