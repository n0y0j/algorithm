#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> left_char = {'E', 'S', 'T', 'J'};
vector<char> right_char = {'I', 'N', 'F', 'P'};

int main() {
    /* mbti: 연길이의 MBTI
       result: 연길이 이상형의 MBTI */
    string mbti, result;
    cin >> mbti;

    for (int i=0; i < mbti.length(); i++ ) {
        if (left_char[i] == mbti[i]) result += right_char[i];
        else result += left_char[i];
    }

    cout << result << endl;
}