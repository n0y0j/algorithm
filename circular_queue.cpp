#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
  int rear;
  int front;
  int queue_size;
  T *queue;

public:
  Queue(int size)
  {
    rear = 0;
    front = 0;
    queue_size = size + 1;
    queue = new T[queue_size];
  }

  bool queue_empty() { return rear == front; };
  bool queue_full() { return (rear + 1) % queue_size == front; };
  void enqueue(T data);
  T dequeue();
  void display();
};

template <typename T>
void Queue<T>::enqueue(T data)
{
  if (!queue_full())
  {
    rear = (rear + 1) % queue_size;
    queue[rear] = data;
  }
  else
    cout << "Queue is full." << endl;
}

template <typename T>
T Queue<T>::dequeue()
{
  if (!queue_empty())
  {
    front = (front + 1) % queue_size;
    return queue[front];
  }
  else
    cout << "Queue is empty." << endl;
}

template <typename T>
void Queue<T>::display()
{
  int pos = front + 1;

  while (pos != (rear + 1) % queue_size)
  {
    cout << queue[pos % queue_size] << " ";
    pos = (pos + 1) % queue_size;
  }
  cout << endl;
}

int main()
{
  Queue<int> cq1(4);

  cq1.enqueue(10);
  cq1.enqueue(20);
  cq1.enqueue(30);
  cq1.enqueue(40);
  cq1.display();

  cout << cq1.dequeue() << endl;
  cq1.enqueue(50);
  cq1.display();

  cout << cq1.dequeue() << endl;
  cq1.enqueue(60);
  cq1.display();

  cout << cq1.dequeue() << endl;
  cq1.enqueue(70);
  cq1.display();

  cout << cq1.dequeue() << endl;
  cq1.enqueue(80);
  cq1.display();

  cout << cq1.dequeue() << endl;
  cq1.enqueue(90);
  cq1.display();
}