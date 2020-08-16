#include <iostream>
using namespace std;

#define MAX 100

class Array_list
{
private:
  int *arr;
  int num_data;

public:
  Array_list()
  {
    int *arr = new int[MAX];
    num_data = 0;
  }
  Array_list(int size)
  {
    int *arr = new int[size];
    num_data = 0;
  }

  bool isEmpty();
  void list_extension(int, int);
  void list_extension_index(int, int, int);
  void insert(int);
  void insert_index(int, int);
  void remove();
  void remove_index(int);
  void search_index(int);
  void display();
  ~Array_list();
};

bool Array_list::isEmpty()
{
  if (num_data == 0)
    return true;
  else
    return false;
}

void Array_list::list_extension(int data, int len)
{
  int newSize = len + 1;
  int *newArray = new int[newSize];

  newArray[newSize - 1] = data;

  for (int i = 0; i < len; i++)
    newArray[i] = arr[i];

  arr = new int[newSize];

  for (int i = 0; i < newSize; i++)
  {
    arr[i] = newArray[i];
  }
}

void Array_list::list_extension_index(int data, int len, int index)
{
  int newSize = len + 1;
  int *newArray = new int[newSize];

  newArray[index - 1] = data;

  for (int i = 0; i < index - 1; i++)
    newArray[i] = arr[i];

  for (int i = newSize - 1; i > index - 1; i--)
    newArray[i] = arr[i - 1];

  arr = new int[newSize];

  for (int i = 0; i < newSize; i++)
  {
    arr[i] = newArray[i];
  }
}

void Array_list::insert(int data)
{
  int len = num_data;
  if (num_data >= MAX - 1)
  {
    cout << "list is full!!" << endl;
  }
  else
  {
    if (num_data == len)
      list_extension(data, len);
    else
      arr[num_data] = data;
  }
  num_data++;
}

void Array_list::insert_index(int data, int index)
{
  int len = num_data;
  if (num_data >= MAX - 1)
  {
    cout << "list is full!!" << endl;
  }
  else
  {
    if (num_data == len)
      list_extension_index(data, len, index);
    else
      arr[index] = data;
  }
  num_data++;
}

void Array_list::remove()
{
  if (num_data == 0)
    isEmpty();
  else
  {
    arr[num_data] = 0;
    num_data--;
  }
}

void Array_list::remove_index(int index)
{
  if (num_data == 0)
    isEmpty();
  else
  {
    arr[index - 1] = 0;
    for (int i = index - 1; i < num_data - 1; i++)
      arr[i] = arr[i + 1];

    num_data--;
  }
}

void Array_list::search_index(int index)
{
  if (num_data == 0 || index > num_data || index == 0)
    cout << "data is not in list." << endl;
  else
    cout << arr[index - 1] << endl;
}

void Array_list::display()
{
  if (num_data == 0)
    isEmpty();
  else
  {
    for (int i = 0; i < num_data; i++)
      cout << arr[i] << " ";
    cout << endl;
  }
}

Array_list::~Array_list()
{
  delete[] arr;
}

int main()
{
  Array_list a1(2);

  a1.insert(10);
  a1.insert(20);
  a1.insert(30);
  a1.insert(40);
  a1.insert_index(50, 4);

  a1.remove();
  a1.remove_index(2);

  a1.search_index(0);

  a1.display();
}