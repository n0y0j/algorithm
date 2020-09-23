#include <iostream>
#include <queue>
using namespace std;

int map[8][8];
int visited[8];

void BFS(int v) {
    queue<int> q1;
    q1.push(v);
    visited[v] = 0;

    while (!q1.empty()) {
        int temp = q1.front();
        q1.pop();
        cout << temp << " ";

        for (int i=0; i<8; i++) {
            if (map[temp][i] == 1 && visited[i] == 1) {
                q1.push(i);
                visited[i] = 0;
            }
        }
    }
    
            
}

int main() {

    // 초기화
    for (int i=0; i<8; i++)
        for (int j=0; j<8; j++)
            map[i][j] = 0;

    for (int i=0; i<8; i++)
        visited[i] = 1;


    //          0
    //      1       2
    //    3   4    5  6
    //          7
    map[0][1] = map[1][0] = 1;  
    map[0][2] = map[2][0] = 1;        
                                
    map[1][3] = map[3][1] = 1;        
    map[1][4] = map[4][1] = 1;

    map[2][5] = map[5][2] = 1;
    map[2][6] = map[6][2] = 1;

    map[3][7] = map[7][3] = 1;
    map[4][7] = map[7][4] = 1;
    map[5][7] = map[7][5] = 1;
    map[6][7] = map[7][6] = 1;

    for (int i=0; i<8; i++) {
        cout << endl;
        for (int j=0; j<8; j++)
            cout << map[i][j] << " ";
    }

    cout << endl;
    cout << "BFS: ";
    BFS(0);

}
