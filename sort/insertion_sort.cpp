#include <iostream>
using namespace std;

// 모든 원소를 이미 정렬된 배열부분과 차례대로 비교해 자신의 위치를 찾아 삽입
// 첫번째 원소를 시작으로 매 순서마다 해당 원소가 들어 갈 위치를 찾음 ( 시간복잡도: O(n**2) )
// 만약, 이동없이 한번의 루프로 끝나면 O(n) <= 이미 배열이 정렬되어 있을 때
// in-place, stable, comparison
void InsertionSort(int arr[], int size) {
    int key, j;

    for(int i = 1; i < size; i++) {
        
        key = arr[i];
        
        // j번째 인덱스는 비교했을 때 key값보다 클 때만 이동하고 값을 바꿔줌
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