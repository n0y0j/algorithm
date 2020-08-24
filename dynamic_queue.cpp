#include <iostream>
using namespace std;

template <typename T>
struct Node
{
  T data;
  Node<T> *next;
};

template <typename T>
class Queue
{
private:
  T *queue;
  Node<T> *front;
  Node<T> *rear;

public:
  Queue()
  {
    front = nullptr;
    rear = nullptr;
  }
  bool queue_empty();
  void enqueue(T item);
  T dequeue();
  void display();
};

template <typename T>
bool Queue<T>::queue_empty()
{
  return rear == nullptr;
}

template <typename T>
void Queue<T>::enqueue(T item)
{
  Node<T> *temp = new Node<T>;
  temp->data = item;
  temp->next = nullptr;

  if (queue_empty())
  {
    front = temp;
    rear = temp;
  }
  else
  {
    rear->next = temp;
    rear = temp;
  }
}

template <typename T>
T Queue<T>::dequeue()
{
  if (!queue_empty())
  {
    Node<T> *p = front;
    T temp = p->data;

    front = front->next;
    delete p;

    if (front == nullptr)
      rear = nullptr;
    return temp;
  }
}

template <typename T>
void Queue<T>::display()
{
  Node<T> *pos = front;

  while (pos != nullptr)
  {
    cout << pos->data << " ";
    pos = pos->next;
  }
  cout << endl;
}

int main()
{
  Queue<int> q1;

  q1.enqueue(10);
  q1.enqueue(20);
  q1.enqueue(30);
  q1.enqueue(40);
  q1.enqueue(50);

  cout << q1.dequeue() << endl;

  q1.display();
}
