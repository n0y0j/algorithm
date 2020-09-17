#include <iostream>
using namespace std;

void swap(int arr[], int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void QuickSort(int arr[], int start, int end) {
    int pivot = arr[start];
    int left = start+1;
    int right = end;

    while (left<=right) {
        
        while( pivot > arr[left] ) left++;
        while( pivot < arr[right] ) right--;

        if ( left <= right) {
            swap(arr, left, right);
        }
    }

    if ( start < end ) {
        swap(arr, start, right);

        QuickSort(arr, start, right-1);
        QuickSort(arr, right+1, end);
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

    QuickSort(i, 0, 8-1);

    for (int j=0; j < 8; j++) cout << i[j] << " ";
}