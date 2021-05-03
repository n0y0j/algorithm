#include <iostream>
using namespace std;

int main()
{
  int num, max, n;

  for (int i = 0; i < 9; i++) {
      cin >> num;

      if ( i == 0 ) {
          max = num;
          n = i + 1;
      } else if ( max < num ) {
          max = num;
          n = i + 1;
      }
      continue;
  }

  cout << max << endl;
  cout << n << endl;
}