#include<iostream>

// 12번 실패하고 성공...
int sort[1000000];

void merge(int arr[], int left, int right, int mid) {
    int left_pos = left;
    int right_pos = mid+1;
    int sort_pos = left;

    while ( left_pos <= mid && right_pos <= right ) {
        if (arr[left_pos] <= arr[right_pos]) sort[sort_pos++] = arr[left_pos++];
        else sort[sort_pos++] = arr[right_pos++];
    }

    if ( left_pos > mid ) {
        for ( int i = right_pos; i <= right; i++ )
            sort[sort_pos++] = arr[i];
        
    }
    else {
        for ( int i = left_pos; i <= mid; i++ )
            sort[sort_pos++] = arr[i];
        
    }

    for ( int i = left; i <= right; i++ )
        arr[i] = sort[i];

}

void merge_sort(int arr[], int left, int right) {
    int mid;

    if ( left < right ) {
        mid = ( left + right ) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, right, mid);
    }
    
}
int main() {
    std::ios_base::sync_with_stdio(false);
    int size;
    std::cin >> size;
    int arr[size];

    for (int i=0; i<size; i++) 
        std::cin>>arr[i];
    

    merge_sort(arr, 0, size-1);

    for (auto n: arr)
        std::cout<<n<<'\n';
}