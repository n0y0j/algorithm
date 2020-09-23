#include <iostream>
using namespace std;

const int size = 10;

template <typename T>
class Queue
{
private:
  T queue[size];
  int front;
  int rear;

public:
  Queue()
  {
    front = -1;
    rear = -1;
  }
  bool queue_full();
  bool queue_empty();
  void enqueue(T item);
  T dequeue();
  void display();
};

template <typename T>
bool Queue<T>::queue_full()
{
  return (size == rear - 1);
}

template <typename T>
bool Queue<T>::queue_empty()
{
  return (front == rear);
}

template <typename T>
void Queue<T>::enqueue(T item)
{
  if (!queue_full())
    queue[++rear] = item;
}

template <typename T>
T Queue<T>::dequeue()
{
  if (!queue_empty())
  {
    return queue[++front];
  }
}

template <typename T>
void Queue<T>::display()
{
  int pos = front + 1;

  while (pos <= rear)
  {
    cout << queue[pos] << " ";
    pos++;
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
