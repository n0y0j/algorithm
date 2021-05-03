#include <iostream>
using namespace std;

int main()
{
  int n, num, max, min;

  cin >> n;

  for (int i = 0; i < n; i++) {
      cin >> num;
      if ( i == 0 ) {
          max = num;
          min = num;
          continue;
      } else if ( max < num ) {
          max = num;
          continue;
      } else if ( min > num ) {
          min = num;
          continue;
      }
  }

  cout << min << " " << max;
}