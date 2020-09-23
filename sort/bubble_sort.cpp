#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size) {

    for (int i = size - 1; i > 0; i--) {

        for (int j = 0; j < i; j++ ) {
            if ( arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
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

    BubbleSort(i, 8);

    for (int j=0; j < 8; j++) cout << i[j] << " ";

}