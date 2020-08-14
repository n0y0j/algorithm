#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

class Linked_list
{
private:
  Node *head;

public:
  Linked_list() { head = 0; }
  bool isEmpty();
  void insert(int);
  void append(int);
  void delete_node(int);
  void search_node(int);
  void display();
  ~Linked_list();
};

// Check the list is empty
bool Linked_list::isEmpty()
{
  if (head == 0)
    return true;
  else
    return false;
}

// Add data to the end of a node
void Linked_list::append(int data)
{
  Node *temp = new Node;

  temp->data = data;
  temp->next = 0;

  if (head == 0)
  {
    head = temp;
  }
  else
  {
    Node *ptr = head;
    while (ptr->next != 0)
      ptr = ptr->next;
    ptr->next = temp;
  }
}

// Insert data in ascending order
void Linked_list::insert(int data)
{
  Node *temp = new Node;
  Node *p, *q;

  temp->data = data;
  temp->next = 0;

  if (head == 0)
  {
    head = temp;
  }
  else if (temp->data < head->data)
  {
    temp->next = head;
    head = temp;
  }
  else
  {
    p = head;
    while ((p != 0) && p->data < temp->data)
    {
      q = p;
      p = p->next;
    }
    if (p != 0)
    {
      temp->next = p;
      q->next = temp;
    }
    else
      q->next = temp;
  }
}

// Delete data
void Linked_list::delete_node(int n)
{
  Node *p, *q;
  if (head->data == n)
  {
    p = head;
    head = head->next;
    delete p;
  }
  else
  {
    p = head;
    while (p != 0 && p->data != n)
    {
      q = p;
      p = p->next;
    }
    if (p != 0)
    {
      q->next = p->next;
      delete p;
    }
    else
      cout << "data is not in list." << endl;
  }
}

// Search data
void Linked_list::search_node(int n)
{
  Node *p, *q;
  if (head->data == n)
    cout << n << " is in list." << endl;
  else
  {
    p = head;
    while (p != 0 && p->data != n)
    {
      q = p;
      p = p->next;
    }
    if (p != 0)
    {
      cout << n << " is in list." << endl;
    }
    else
      cout << n << " is not in list." << endl;
  }
}

// Print list
void Linked_list::display()
{
  if (!isEmpty())
  {
    Node *ptr = head;

    while (ptr)
    {
      cout << ptr->data << " ";
      ptr = ptr->next;
    }
    cout << endl;
  }
  else
    cout << "Linkedlist is empty!!" << endl;
}

// Disappearance of List
Linked_list::~Linked_list()
{
  Node *p;

  while (head != 0)
  {
    p = head;
    head = head->next;
    delete p;
  }
}

// TEST
int main()
{
  Linked_list l1;

  l1.append(5);
  l1.append(25);
  l1.insert(10);
  l1.insert(40);
  l1.insert(20);
  l1.insert(30);
  l1.insert(50);
  l1.delete_node(30);

  l1.display();

  l1.search_node(20);
  l1.search_node(30);

  l1.~Linked_list();
  l1.display();
}