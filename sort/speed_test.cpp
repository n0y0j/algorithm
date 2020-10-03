#include <cstdio>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;

#define n 10

int _random (int i) { return rand()%i; }

void BubbleSort(vector<int> arr) {

    for (int i = n - 1; i > 0; i--) {

        for (int j = 0; j < i; j++ ) {
            if ( arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void swap(vector<int> arr, int left, int right) {
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

void SelectionSort(vector<int> arr) {
    int min_index;

    for( int i = 0; i < n - 1; i++ ) {
        min_index = i;

        for ( int j = i; j < n; j++ ) {
            if ( arr[j] < arr[min_index] ) min_index = j;
        }

        if ( i != min_index ) swap(arr, min_index, i);
        
    }
}

void InsertionSort(vector<int> arr) {
    int key, j;
    for(int i = 1; i < n; i++) {
        key = arr[i];
        
        for (j = i - 1; j >= 0 && arr[j] > key; j--) {
                arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

int sort_arr[n];
void merge(vector<int> arr, int left, int right, int mid) {
    int left_pos = left;
    int right_pos = mid+1;

    int sort_pos = left;

    while ( left_pos <= mid && right_pos <= right ) {
        if (arr[left_pos] <= arr[right_pos]) sort_arr[sort_pos++] = arr[left_pos++];
        else sort_arr[sort_pos++] = arr[right_pos++];
    }

    if ( left_pos <= mid ) {
        for ( int i = left_pos; i <= mid; i++ ) {
            sort_arr[sort_pos++] = arr[i];
        }
    }
    else {
        for ( int i = right_pos; i <= right; i++ ) {
            sort_arr[sort_pos++] = arr[i];
        }
    }

    for ( int i = 0; i <= right; i++ ) {
        arr[i] = sort_arr[i];
    }
}

void MergeSort(vector<int> arr, int left, int right) {
    
    if ( left < right ) {
        int mid = ( left + right ) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid+1, right);
        merge(arr, left, right, mid);
    }    
}

void QuickSort(vector<int> arr, int start, int end) {
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

void CountingSort(vector<int> arr) {
    int count[n] = {0,};
    int sum_count[n] = {0, };
    int sort_list[n] = {0, };

    for ( int i=0; i<n-1; i++ ) {
        count[arr[i]]++;
    }

    sum_count[0] = count[0];
    for ( int j=1; j<n-1; j++ ) {
        sum_count[j] = sum_count[j-1] + count[j]; 
    }

    for ( int k = n-1; k >= 0; k-- ) {
        sort_list[sum_count[arr[k]]] = arr[k];
        sum_count[arr[k]]--;
    }
}


int main() {
    vector<int> v;

    // Create vector
    for (int i=0; i<n; i++)
        v.push_back(i);

    random_shuffle(v.begin(), v.end(), _random);

    clock_t start, end;

    printf("10만개의 원소로 정렬을 시작합니다");
    printf("\n");

    start = clock();
    BubbleSort(v);
    end = clock();
    printf("bubble sort: %lf\n", (double) (end-start)/CLOCKS_PER_SEC);

    start = clock();
    SelectionSort(v);
    end = clock();
    printf("selection sort: %lf\n", (double) (end-start)/CLOCKS_PER_SEC);

    start = clock();
    InsertionSort(v);
    end = clock();
    printf("Insertion sort: %lf\n", (double) (end-start)/CLOCKS_PER_SEC);

    start = clock();
    MergeSort(v, 0, n-1);
    end = clock();
    printf("Merge sort: %lf\n", (double) (end-start)/CLOCKS_PER_SEC);

    start = clock();
    QuickSort(v, 0, n-1);
    end = clock();
    printf("Quick sort: %lf\n", (double) (end-start)/CLOCKS_PER_SEC);

    start = clock();
    CountingSort(v);
    end = clock();
    printf("Counting sort: %lf\n", (double) (end-start)/CLOCKS_PER_SEC);

}



