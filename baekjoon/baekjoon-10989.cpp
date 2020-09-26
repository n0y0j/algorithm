#include<iostream>
using namespace std;

// using counting sort
// 메모리 제한 8mb이므로 수를 입력받아 저장하면 메모리 초과임 바로 표준출력해야함
int main()
{
    // c++의 iostream과 c의 stdio의 동기화를 끊음
    // cin과 cout의 속도가 C의 입출력 속도에 비해 떨어지기 때문에 속도를 높이는 기능으로 사용
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int count[10001] = {0};
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        int s;
        cin >> s;
        count[s]++;
    }
    
    for(int i=1; i<=10000; i++) {
        if(count[i] > 0)
            for(int j=0; j<count[i]; j++)
                cout << i << "\n";
    }
}
