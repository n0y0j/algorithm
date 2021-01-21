#include <iostream>
using namespace std;

int main() {
    /* n: 입력 받는 숫자
       a: 숫자의 10의 자리
       b: 숫자의 1의 자리
       c: 새로 나온 숫자의 오른쪽
       num: 입력 받은 숫자 저장
       res: 사이클 계산 */
    int n, a, b, c, num, res = 0;

    cin >> n;
    num = n;

    while(true) {
        a = n / 10;
        b = n % 10;
        c = (a+b) % 10;
        res++;

        if ( num == ( b * 10 ) + c) break;
        else n = ( b * 10 ) + c;
    }

    cout << res << endl;
}