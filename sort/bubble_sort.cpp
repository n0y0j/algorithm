#include <iostream>
using namespace std;


// 서로 인접한 두 원소를 비교하는 방법 ( 1, 2번째 인덱스 -> 2, 3번째 인덱스 ... )
// 리스트에서 전체의 원소를 한 번씩 비교하면, 가장 큰 값이 맨 끝 인덱스로 이동함
// 위와 같은 과정은 size-1번 반복해야함 ( 시간복잡도: O(n**2) )
// in-place, stable, comparison
// stable: 같은 값의 원소가 정렬과정에서 위치가 바뀌지 않는 것
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