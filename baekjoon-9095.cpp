#include <iostream>
using namespace std;

int main()
{
  int arr[11];
  arr[1] = 1;
  arr[2] = 2;
  arr[3] = 4;

  int test_n = 0;
  int test_value = 0;

  cin >> test_n;

  for (int i = 0; i < test_n; i++)
  {
    cin >> test_value;
    for (int j = 4; j <= test_value; j++)
      arr[j] = arr[j - 1] + arr[j - 2] + arr[j - 3];

    cout << arr[test_value] << endl;
  }
}