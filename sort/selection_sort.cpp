#include <iostream>
using namespace std;

// 원소가 들어갈 자리를 미리 마련하고, 배열에서 최소값을 찾아 삽입함
// 배열을 전체적으로 1회 비교했다면, 0번째 인덱스에 최소값이 삽입됨
// 위와 같은 과정을 size-1번 진행 ( 시간 복잡도: O(n**2) )
// in-place, stable, comparison
void swap(int arr[], int min_index, int i) {
    int temp = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = temp;
}

void SelectionSort(int arr[], int size) {
    int min_index;

    for( int i = 0; i < size - 1; i++ ) {
        min_index = i;

        for ( int j = i; j < size; j++ ) {
            if ( arr[j] < arr[min_index] ) min_index = j;
        }

        // 자기 자신이 최솟값이라면 이동안함
        if ( i != min_index ) swap(arr, min_index, i);
        
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

    SelectionSort(i, 8);

    for (int j=0; j < 8; j++) cout << i[j] << " ";

}