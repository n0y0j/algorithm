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

    int i[8];

    i[0]=20;
    i[1]=10;
    i[2]=70;
    i[3]=40;
    i[4]=50;
    i[5]=30;
    i[6]=80;
    i[7]=60;

    InsertionSort(i, 8);

    for (int j=0; j < 8; j++) cout << i[j] << " ";

}