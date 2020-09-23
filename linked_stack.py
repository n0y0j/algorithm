class Node:
  def __init__(self, data):
    self.next = None
    self.data = data

class Stack:
  def __init__(self):
    self.head = None

  def push(self, data):
      temp = Node(data)
      temp.next = self.head
      self.head = temp;
    
  def pop(self):
    data = self.head.data
    self.head = self.head.next
    return data

  def isEmpty(self):
    return (self.head == None)
  
  def peek(self):
    if self.isEmpty():
      print("Stack is empty")
    return (self.head.data)

  def display(self):
    if self.isEmpty():
      print("Stack is empty.")
    else:
     pos = self.head;
     while(pos != None):
      print(pos.data)
      pos = pos.next
    

if __name__ == "__main__":
    s1 = Stack()

    s1.push(10)
    s1.push(20)
    s1.push(30)
    s1.push(40)
    s1.push(50)

    s1.pop()

    s1.display()



      