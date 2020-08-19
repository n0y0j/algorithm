#include <iostream>
using namespace std;

template <typename T>
class Array_list
{
private:
  T *arr;
  int num_data;
  int size;

public:
  Array_list()
  {
    arr = new T[1];
    num_data = 0;
    size = 1;
  }

  bool isEmpty();
  void list_extension(T, int);
  void list_extension_index(T, int, int);
  void insert(T);
  void insert_index(T, int);
  void remove();
  void remove_index(int);
  void search_index(int);
  void display();
  ~Array_list();
};

template <typename T>
bool Array_list<T>::isEmpty()
{
  return (num_data == 0);
}

template <typename T>
void Array_list<T>::list_extension(T data, int len)
{
  int size = len * 2;
  T *newArray = new T[size];

  newArray[size - 1] = data;

  for (int i = 0; i < len; i++)
    newArray[i] = arr[i];

  delete[] arr;
  arr = new T[size];

  for (int i = 0; i < size; i++)
  {
    arr[i] = newArray[i];
  }
}

template <typename T>
void Array_list<T>::list_extension_index(T data, int len, int index)
{
  int size = len * 2;
  T *newArray = new T[size];

  newArray[index - 1] = data;

  for (int i = 0; i < index - 1; i++)
    newArray[i] = arr[i];

  for (int i = size - 1; i > index - 1; i--)
    newArray[i] = arr[i - 1];

  delete[] arr;
  arr = new T[size];

  for (int i = 0; i < size; i++)
  {
    arr[i] = newArray[i];
  }
}

template <typename T>
void Array_list<T>::insert(T data)
{
  if (num_data == size)
    list_extension(data, size);

  else
    arr[num_data] = data;
  num_data++;
}

template <typename T>
void Array_list<T>::insert_index(T data, int index)
{

  if (num_data == size)
    list_extension_index(data, size, index);
  else
    arr[index] = data;
  num_data++;
}

template <typename T>
void Array_list<T>::remove()
{
  if (num_data == 0)
    isEmpty();
  else
  {
    arr[num_data] = 0;
    num_data--;
  }
}

template <typename T>
void Array_list<T>::remove_index(int index)
{
  if (num_data == 0)
    isEmpty();
  else
  {
    arr[index] = 0;
    for (int i = index; i < num_data - 1; i++)
      arr[i] = arr[i + 1];

    num_data--;
  }
}

template <typename T>
void Array_list<T>::search_index(int index)
{
  if (num_data == 0 || index > num_data)
    cout << "data is not in list." << endl;
  else
    cout << arr[index] << endl;
}

template <typename T>
void Array_list<T>::display()
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

template <typename T>
Array_list<T>::~Array_list()
{
  delete[] arr;
  arr = 0;
}

int main()
{
  Array_list<int> a1;

  a1.insert(10);
  a1.insert(20);
  a1.insert(30);
  a1.insert(40);
  a1.insert_index(50, 4);

  a1.remove();
  a1.remove_index(2);

  a1.search_index(1);

  a1.display();
  a1.~Array_list();
}