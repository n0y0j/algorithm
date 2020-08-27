#include <iostream>
using namespace std;

// 아니 왜 트리로 구현하면 메모리 에러나... 이진트리 공부하려고 푼 문젠데..
struct Node
{
  char left;
  char right;
};

struct Node arr[26];

void preorder(char root)
{
  if (root == '.')
    return;
  cout << root;
  preorder(arr[root].left);
  preorder(arr[root].right);
}

void inorder(char root)
{
  if (root == '.')
    return;

  inorder(arr[root].left);
  cout << root;
  inorder(arr[root].right);
}

void postorder(char root)
{
  if (root == '.')
    return;

  postorder(arr[root].left);
  postorder(arr[root].right);
  cout << root;
}

int main()
{
  int n;
  char p1, p2, p3;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> p1 >> p2 >> p3;
    arr[p1].left = p2;
    arr[p1].right = p3;
  }

  preorder('A');
  cout << endl;
  inorder('A');
  cout << endl;
  postorder('A');
  cout << endl;
}
