#include <iostream>
using namespace std;

// 배열을 잘게 쪼개고 둘씩 크기를 비교하여 정렬한 후 그 배열들을 합침 ( 분할 정복 알고리즘 ) ( 시간복잡도: O(nlogn) )
// 분할된 배열들을 저장하기 위해 메모리 소비량이 매우 크다
// out-place, stable, comparison
int sort[8];

void merge(int arr[], int left, int right, int mid) {
    int left_pos = left;
    int right_pos = mid+1;

    // index of sort array
    int sort_pos = left;

    while ( left_pos <= mid && right_pos <= right ) {
        if (arr[left_pos] <= arr[right_pos]) sort[sort_pos++] = arr[left_pos++];
        else sort[sort_pos++] = arr[right_pos++];
    }

    // array에 남아있는 수들 추가
    if ( left_pos <= mid ) {
        for ( int i = left_pos; i <= mid; i++ ) {
            sort[sort_pos++] = arr[i];
        }
    }
    else {
        for ( int i = right_pos; i <= right; i++ ) {
            sort[sort_pos++] = arr[i];
        }
    }

    // 다시 복사
    for ( int i = 0; i <= right; i++ ) {
        arr[i] = sort[i];
    }
}

void merge_sort(int arr[], int left, int right) {
    
    if ( left < right ) {
        int mid = ( left + right ) / 2;
        // left part
        merge_sort(arr, left, mid);
        // right part
        merge_sort(arr, mid+1, right);
        // array merge
        merge(arr, left, right, mid);
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

    merge_sort(i, 0, 8-1);

    for ( int j = 0; j <= 7; j++ ) {
        cout << i[j] << " ";
    }

}

