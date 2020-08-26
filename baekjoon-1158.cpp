#include <iostream>
#include <queue>
using namespace std;

int main()
{
  int n, s;
  cin >> n >> s;
  queue<int> q;

  for (int i = 1; i <= n; i++)
    q.push(i);

  cout << "<";
  while (q.size())
  {
    if (q.size() == 1)
    {
      cout << q.front() << ">";
      q.pop();
      break;
    }
    for (int i = 1; i < s; i++)
    {
      q.push(q.front());
      q.pop();
    }
    cout << q.front() << ", ";
    q.pop();
  }
  cout << endl;
}
