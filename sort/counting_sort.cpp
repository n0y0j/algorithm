#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX 101

// 각 숫자가 몇번 나왔는지 count를 한 후, 그 카운트의 누적 합을 이용하여 정렬
// ( 0이 3번나오고 1이 2번 나왔을 시, count의 누적합은 5(3+2)이다. 즉, 0~2번 인덱스의 값은 0이고 3~4번 인덱스 값은 1이다. )
// 시간복잡도는 O(n)으로 quicksort보다 빠르지만, 공간 효율성이 너무 떨어짐
// out-place, stable
void CountingSort(int arr[]) {
    int count[MAX] = {0,};
    int sum_count[MAX] = {0, };
    int sort_list[MAX] = {0, };

    for ( int i=0; i<MAX-1; i++ ) {
        count[arr[i]]++;
    }

    sum_count[0] = count[0];
    for ( int j=1; j<MAX-1; j++ ) {
        sum_count[j] = sum_count[j-1] + count[j]; 
    }

    // 정렬할 리스트에 역순으로 가장 큰 값부터 삽입
    for ( int k = MAX-1; k >= 0; k-- ) {
        sort_list[sum_count[arr[k]]] = arr[k];
        sum_count[arr[k]]--;
    }

    for ( int l = 0; l < MAX-1; l++ ) {
        cout << sort_list[l] << " ";
    }

}

int main() {
    int arr[MAX];

    for(int i=0; i<MAX; i++) {
        arr[i] = rand() % 100;
    }

    CountingSort(arr);
}