#include <iostream>
using namespace std;

const int size = 10;

template <typename T>
class Stack
{
private:
  T stack[size];
  int top;

public:
  Stack()
  {
    top = -1;
  }

  bool isEmpty() { return top == -1; };
  bool isFull() { return top == size - 1; };
  void push(T data);
  T pop();
  void display();
};

template <typename T>
void Stack<T>::push(T data)
{
  if (!isFull())
    stack[++top] = data;
  else
    cout << "Stack is full." << endl;
}

template <typename T>
T Stack<T>::pop()
{
  if (!isEmpty())
    return stack[top--];
  else
    cout << "Stack is Empty." << endl;
}

template <typename T>
void Stack<T>::display()
{
  int pos = top;

  while (pos != -1)
    cout << stack[pos--] << " ";
  cout << endl;
}

int main()
{
  Stack<int> s1;

  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);
  s1.push(50);
  s1.push(60);

  s1.display();

  s1.pop();
  s1.pop();

  s1.display();
}