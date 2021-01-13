#include <stdio.h>
#include <math.h>

int num[1000001] = {0};
#define lld long long

int main() {
    /* n: 시험장의 개수
       m: 각 시험장의 응시자 수
       p, q: 총감독관과 부감독관이 감시할 수 있는 응시자 수
       res: 총 필요한 감독관의 수 */
    int n, p, q;
    lld res = 0;
    scanf("%d", &n);

    for ( int i=0; i < n; i++ ) {
        scanf("%d", &num[i]);
    }

    scanf("%d %d", &p, &q);

    for ( int j=0; j < n; j++ ) {
        num[j] = num[j] - p;
        res++;

        if (num[j] > 0) {
            res += num[j] / q;

            if(num[j] % q > 0) res++;
        }
    }

    printf("%lld", res);
}
