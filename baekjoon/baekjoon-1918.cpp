#include <iostream>
#include <string>
using namespace std;

const int size = 100;

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

  bool empty() { return top == -1; };
  void push(T data);
  T pop();
  T peak();
};

template <typename T>
void Stack<T>::push(T data)
{
  stack[++top] = data;
}

template <typename T>
T Stack<T>::pop()
{
  return stack[top--];
}

template <typename T>
T Stack<T>::peak()
{
  return stack[top];
}

int main()
{
  Stack<char> s1;

  string temp = "";
  string n;
  cin >> n;

  for (int i = 0; i < n.length(); i++)
  {
    if (n[i] >= 'A' && n[i] <= 'Z')
      temp += n[i];

    else if (n[i] == '(')
      s1.push(n[i]);

    else if (n[i] == ')')
    {
      while (s1.peak() != '(')
        temp += s1.pop();
      s1.pop();
    }

    else if (n[i] == '*' || n[i] == '/')
    {
      if (!s1.empty() && (s1.peak() == '*' || s1.peak() == '/'))
        temp += s1.pop();

      s1.push(n[i]);
    }

    else if (n[i] == '+' || n[i] == '-')
    {
      while (!s1.empty())
      {
        if (s1.peak() == '(')
          break;
        temp += s1.pop();
      }
      s1.push(n[i]);
    }
  }

  while (!s1.empty())
    temp += s1.pop();

  cout << temp << endl;
}