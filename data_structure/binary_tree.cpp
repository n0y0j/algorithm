#include <iostream>
using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node
{
private:
  T data;
  Node<T> *right;
  Node<T> *left;

public:
  Node(T data, Node *left = nullptr, Node *right = nullptr)
  {
    this->data = data;
    this->left = left;
    this->right = right;
  };
  friend class Tree<T>;
};

template <typename T>
class Tree
{
private:
  Node<T> *root;

public:
  Tree(T data) { root = new Node<T>(data); };

  void build_tree();
  Node<T> *get_root() { return root; };
  void inorder(Node<T> *current);
  void postorder(Node<T> *current);
  void preorder(Node<T> *current);
};

//            A
//       B              C
//    D     E       F      G
//  H  I  J   K   L   M
template <typename T>
void Tree<T>::build_tree()
{
  root->left = new Node<T>('B', new Node<T>('D', new Node<T>('H'), new Node<T>('I')), new Node<T>('E', new Node<T>('J'), new Node<T>('K')));
  root->right = new Node<T>('C', new Node<T>('F', new Node<T>('L'), new Node<T>('M')), new Node<T>('G'));
}

// Left -> Current -> Right
template <typename T>
void Tree<T>::inorder(Node<T> *current)
{
  if (current)
  {
    inorder(current->left);
    cout << current->data << " ";
    inorder(current->right);
  }
}

// Left -> Right -> Current
template <typename T>
void Tree<T>::postorder(Node<T> *current)
{
  if (current)
  {
    postorder(current->left);
    postorder(current->right);
    cout << current->data << " ";
  }
}

// Current -> Left -> Right
template <typename T>
void Tree<T>::preorder(Node<T> *current)
{
  if (current)
  {
    cout << current->data << " ";
    preorder(current->left);
    preorder(current->right);
  }
}

int main()
{
  Tree<char> t1('A');
  t1.build_tree();

  t1.inorder(t1.get_root());
  cout << endl;

  t1.postorder(t1.get_root());
  cout << endl;

  t1.preorder(t1.get_root());
  cout << endl;
}
