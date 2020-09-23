#include <iostream>
using namespace std;

template <typename T>
struct Node
{
  T data;
  Node<T> *left;
  Node<T> *right;
};

template <typename T>
class Tree
{
private:
  Node<T> *root;

public:
  Tree()
  {
    root = NULL;
  };

  Node<T> *insert(Node<T> *curr, T data);
  Node<T> *remove(Node<T> *curr, T data);
  Node<T> *find_min(Node<T> *curr);
  Node<T> *search(Node<T> *curr, T data);
  void inorder(Node<T> *curr);

  void insert(T data) { root = insert(root, data); };
  void remove(T data) { root = remove(root, data); };
  void search(T data) { root = search(root, data); };
  void display()
  {
    inorder(root);
    cout << endl;
  }
};

template <typename T>
Node<T> *Tree<T>::insert(Node<T> *curr, T data)
{
  if (curr == NULL)
  {
    curr = new Node<T>;
    curr->data = data;
    curr->left = nullptr;
    curr->right = nullptr;
  }
  else if (curr->data > data)
    curr->left = insert(curr->left, data);

  else if (curr->data < data)
    curr->right = insert(curr->right, data);

  return curr;
}

template <typename T>
Node<T> *Tree<T>::remove(Node<T> *curr, T data)
{
  if (curr != NULL)
  {
    if (curr->data > data)
      curr->left = remove(curr->left, data);
    else if (curr->data < data)
      curr->right = remove(curr->right, data);
    else if (curr->left && curr->right)
    {
      Node<T> *p = find_min(curr->right);
      curr->data = p->data;
      curr->right = remove(curr->right, curr->data);
    }
    else
    {
      Node<T> *temp = curr;
      if (curr->left == NULL)
        curr = curr->right;
      else if (curr->right == NULL)
        curr = curr->left;
      delete temp;
    }
  }
  else
    cout << "data is not in a tree." << endl;

  return curr;
}

template <typename T>
Node<T> *Tree<T>::find_min(Node<T> *curr)
{
  if (curr->left == NULL)
    return curr;
  else
    find_min(curr->left);
}

template <typename T>
Node<T> *Tree<T>::search(Node<T> *curr, T data)
{
  if (curr == NULL)
    cout << data << " is not in a tree." << endl;
  else
  {
    if (curr->data == data)
      cout << data << " is in a tree." << endl;
    else if (curr->data > data)
      search(curr->left, data);
    else
      search(curr->right, data);
  }
  return curr;
}

template <typename T>
void Tree<T>::inorder(Node<T> *curr)
{
  if (curr)
  {
    inorder(curr->left);
    cout << curr->data << " ";
    inorder(curr->right);
  }
}

int main()
{
  Tree<int> t1;

  t1.insert(10);
  t1.insert(5);
  t1.insert(7);
  t1.insert(14);
  t1.insert(12);
  t1.insert(18);
  t1.insert(15);

  t1.remove(10);

  t1.search(10);
  t1.search(12);

  t1.display();
}
