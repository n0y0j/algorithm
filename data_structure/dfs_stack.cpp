#include <iostream>
#include <stack>
using namespace std;

int map[9][9];
int visited[9];

void DFS(int v) {
    stack<int> s1;

    s1.push(v);
    visited[v] = 0;

    while (!s1.empty()) {
        int curr = s1.top();
        s1.pop();
        cout << curr << " ";

        for (int i=0; i<9; i++) {
            if (map[curr][i] == 1 && visited[i] == 1) {
                s1.push(i);
                visited[i] = 0;
            }
        }

    }
    
}

int main() {

    // 초기화
    for (int i=0; i<9; i++)
        for (int j=0; j<9; j++)
            map[i][j] = 0;

    for (int i=0; i<9; i++)
        visited[i] = 1;


    //      0
    //      |
    //      1 ㅡ  3 \    7
    //      |  /  |   5 <
    //      2 ㅡ  4      6 ㅡ  8
    //          
    map[0][1] = map[1][0] = 1;      
                                
    map[1][2] = map[2][1] = 1;        
    map[1][3] = map[3][1] = 1;

    map[2][3] = map[3][2] = 1;
    map[2][4] = map[4][2] = 1;

    map[3][4] = map[4][3] = 1;
    map[3][5] = map[5][3] = 1;

    map[5][6] = map[6][5] = 1;
    map[5][7] = map[7][5] = 1;

    map[6][8] = map[8][6] = 1;

    for (int i=0; i<9; i++) {
        cout << endl;
        for (int j=0; j<9; j++)
            cout << map[i][j] << " ";
    }

    cout << endl;
    cout << "DFS: ";
    DFS(0);

}
