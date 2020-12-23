#include <stdio.h>

int num[100001] = {0};

int main() {
    /* n: 수의 개수
       m: 합을 구하는 횟수
       p, q: 합을 구하는 구간
       var: 값을 입력받는 변수 */
    int n, m, p, q, var = 0;
    scanf("%d %d", &n, &m);
    
    for ( int i=1; i <= n; i++ ) {
        scanf("%d", &var);
        num[i] = num[i-1] + var;
    }
    
    for ( int j=0; j < m; j++ ) {
        scanf("%d %d", &p, &q);
        printf("%d\n", num[q] - num[p-1]);
    }

}
