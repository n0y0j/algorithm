#include <iostream>
using namespace std;

template <typename T>
struct Node
{
  T data;
  Node<T> *next;
  Node<T> *prev;
};

template <typename T>
class Linked_list
{
private:
  Node<T> *head;
  Node<T> *tail;
  int size;

public:
  Linked_list()
  {
    head = nullptr;
    tail = nullptr;
    size = 0;
  }
  bool isEmpty();
  void insert_front(T);
  void insert_back(T);
  void insert_index(T, int);
  void delete_front();
  void delete_back();
  void delete_data(T);
  void delete_index(int);
  void search_node(T);
  ~Linked_list();

  class iterator
  {
    friend class Linked_list;

  private:
    Node<T> *ptr;
    iterator(Node<T> *new_ptr) : ptr(new_ptr) {}

  public:
    iterator() : ptr(nullptr) {}
    bool operator!=(const iterator &itr) const
    {
      return ptr != itr.ptr;
    }

    T &operator*() const
    {
      return ptr->data;
    }

    iterator operator++(int)
    {
      ptr = ptr->next;
      return ptr;
    }
  };

  iterator begin() const
  {
    return iterator(head);
  }

  iterator end() const
  {
    Node<T> *temp = nullptr;
    tail->next = temp;
    return iterator(temp);
  }
};

// Check the list is empty
template <typename T>
bool Linked_list<T>::isEmpty()
{
  return head == nullptr;
}

// Add data at the beginning
template <typename T>
void Linked_list<T>::insert_front(T data)
{

  Node<T> *temp = new Node<T>;

  temp->data = data;
  temp->next = nullptr;
  temp->prev = nullptr;

  if (head == nullptr)
  {
    head = temp;
    tail = temp;
  }
  else
  {
    head->prev = temp;
    temp->next = head;
    head = temp;
  }

  size += 1;
}

// Add data to the end of a node
template <typename T>
void Linked_list<T>::insert_back(T data)
{
  Node<T> *temp = new Node<T>;

  temp->data = data;
  temp->next = nullptr;
  temp->prev = nullptr;

  if (head == nullptr)
  {
    head = temp;
    tail = temp;
  }
  else
  {
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
  }

  size += 1;
}

// Add index of the data
template <typename T>
void Linked_list<T>::insert_index(T data, int index)
{
  Node<T> *temp = new Node<T>;

  temp->data = data;
  temp->next = nullptr;
  temp->prev = nullptr;

  if (head == nullptr)
  {
    head = temp;
    tail = temp;
  }
  else if (index == 0)
  {
    insert_front(data);
  }
  else
  {
    Node<T> *ptr;
    Node<T> *p_next;

    if (index <= size / 2)
    {
      ptr = head;
      for (int i = 0; i < index - 1; i++)
        ptr = ptr->next;
    }
    else
    {
      ptr = tail;
      for (int i = 0; i < size - index - 1; i++)
        ptr = ptr->prev;
    }

    if (ptr->next == nullptr)
    {
      insert_back(data);
    }
    else
    {
      p_next = ptr->next;
      temp->next = ptr->next;
      p_next->prev = temp;
      ptr->next = temp;
      temp->prev = ptr;
    }
  }

  size += 1;
}

// Delete data at the beginning
template <typename T>
void Linked_list<T>::delete_front()
{
  Node<T> *p = head;

  head = head->next;
  p->next = nullptr;
  p->prev = nullptr;
  delete p;
}

// Delete data to the end of a node
template <typename T>
void Linked_list<T>::delete_back()
{
  Node<T> *p = head;

  while (p->next != tail)
    p = p->next;

  tail = p;
  p = p->next;
  p->next = nullptr;
  p->prev = nullptr;
  tail->next = nullptr;
  delete p;
}

// Delete data
template <typename T>
void Linked_list<T>::delete_data(T data)
{
  if (head->data == data)
  {
    delete_front();
  }
  else
  {
    Node<T> *p, *q;
    p = head;
    while (p != 0 && p->data != data)
    {
      q = p;
      p = p->next;
    }
    if (p->next == nullptr)
    {
      delete_back();
    }
    else if (p->next != nullptr)
    {
      Node<T> *p_next = p->next;

      q->next = p_next;
      p_next->prev = q;

      p->next = nullptr;
      p->prev = nullptr;

      delete p;
    }
    else
      cout << "data is not in list." << endl;
  }
}

// Delete index of the data
template <typename T>
void Linked_list<T>::delete_index(int index)
{
  Node<T> *p, *q;

  if (index <= size / 2)
  {
    p = head;
    for (int i = 0; i < index; i++)
    {
      q = p;
      p = p->next;
    }
  }
  else
  {
    p = tail;
    for (int i = 0; i < size - index; i++)
      p = p->prev;
  }

  if (p == head)
  {
    delete_front();
  }
  else if (p->next == 0)
  {
    delete_back();
  }
  else
  {
    Node<T> *p_next = p->next;
    q->next = p_next;
    p_next->prev = q;
    p->next = nullptr;
    p->prev = nullptr;
    delete p;
  }
}

// Search data
template <typename T>
void Linked_list<T>::search_node(T data)
{
  Node<T> *p, *q;
  if (head->data == data)
  {
    cout << data << " is in list." << endl;
  }
  else if (tail->data == data)
  {
    cout << data << " is in list." << endl;
  }
  else
  {
    p = head;
    while (p != 0 && p->data != data)
    {
      q = p;
      p = p->next;
    }
    if (p != 0)
    {
      cout << data << " is in list." << endl;
    }
    else
      cout << data << " is not in list." << endl;
  }
}

// Disappearance of List
template <typename T>
Linked_list<T>::~Linked_list()
{
  Node<int> *p;

  while (head != nullptr)
  {
    p = head;
    head = head->next;
    delete p;
  }
}

// TEST
int main()
{
  Linked_list<int> l1;
  auto iter = l1.begin();

  l1.insert_back(5);
  l1.insert_back(25);
  l1.insert_back(30);
  l1.insert_back(35);
  l1.insert_back(40);

  l1.insert_index(50, 0);
  l1.insert_index(60, 5);
  l1.insert_index(65, 7);
  l1.insert_index(70, 0);
  l1.insert_index(75, 1);

  l1.delete_back();
  l1.delete_back();

  l1.delete_front();
  l1.delete_data(25);

  l1.delete_index(0);
  l1.delete_index(4);
  l1.delete_index(1);

  l1.search_node(20);
  l1.search_node(30);

  for (auto itr = l1.begin(); itr != l1.end(); itr++)
    cout
        << *itr << " ";
  cout << endl;

  l1.~Linked_list();
}