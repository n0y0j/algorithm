#include <iostream>
using namespace std;

#define MAX 100001

int in_order[MAX];
int post_order[MAX];
int idx[MAX];

void pre_order(int in_start, int in_end, int post_start, int post_end)
{
  if (in_start > in_end || post_start > post_end)
    return;

  int root = post_order[post_end];
  cout << root << " ";

  int root_idx = idx[root];
  int idx_count = root_idx - in_start;

  pre_order(in_start, root_idx - 1, post_start, post_start + idx_count - 1);
  pre_order(root_idx + 1, in_end, post_start + idx_count, post_end - 1);
}

int main()
{
  int n, s;

  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> s;
    in_order[i] = s;
  }

  for (int i = 0; i < n; i++)
  {
    cin >> s;
    post_order[i] = s;
  }

  for (int i = 0; i < n; i++)
    idx[in_order[i]] = i;

  pre_order(0, n - 1, 0, n - 1);
  cout << endl;
}