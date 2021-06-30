#include <iostream>

template <typename T>
struct Node
{
  T data;
  Node *next;

  Node(const T &data, Node *node = nullptr) : data(data), next(node) {}
};

template <typename T>
class Stack
{
public:
  Stack();
  Stack(const Stack<T> &rhs);
  Stack &operator=(const Stack<T> &rhs);
  ~Stack();

  void push(const T &value);
  bool empty() const;
  int size() const;
  T top() const;
  T pop();

private:
  Node<T> *peak;
  int length;

  void deleteStack();
  void copyStack(const Stack<T> &rhs);
};

template <typename T>
void Stack<T>::deleteStack()
{
  Node<T> *current;
  while (peak != nullptr)
  {
    current = peak;
    peak = peak->next;
    delete current;
  }
}

template <typename T>
void Stack<T>::copyStack(const Stack<T> &rhs)
{
  peak = nullptr;
  length = rhs.length;

  if (length != 0)
  {
    Node<T> *rhsCurrent = rhs.peak;
    peak = new Node<T>(rhsCurrent->data);

    Node<T> *current = peak;
    rhsCurrent = rhsCurrent->next;
    while (rhsCurrent != nullptr)
    {
      current->next = new Node<T>(rhsCurrent->data);

      current = current->next;
      rhsCurrent = rhsCurrent->next;
    }
  }
}

template <typename T>
Stack<T>::Stack()
{
  peak = nullptr;
  length = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &rhs)
{
  copyStack(rhs);
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rhs)
{
  if (this != &rhs)
  {
    deleteStack();
    copyStack(rhs);
  }
  return *this;
}

template <typename T>
Stack<T>::~Stack()
{
  deleteStack();
}

template <typename T>
void Stack<T>::push(const T &value)
{
  Node<T> *newNode = new Node<T>(value, peak);
  peak = newNode;
  length++;
}

template <typename T>
bool Stack<T>::empty() const
{
  return (length == 0);
}

template <typename T>
int Stack<T>::size() const
{
  return length;
}

template <typename T>
T Stack<T>::top() const
{
  if (length == 0)
  {
    return 0;
  }
  return peak->data;
}

template <typename T>
T Stack<T>::pop()
{
  if (length == 0)
  {
    return 0;
  }
  T value = peak->data;
  Node<T> *nextNode = peak->next;

  delete peak;
  peak = nextNode;
  length--;

  return value;
}

int main()
{
  Stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);

  Stack<int> st2 = Stack<int>(st);

  std::cout << "Stack 2 element: " << st2.pop() << '\n';
  std::cout << "Stack 2 element: " << st2.pop() << '\n';
  std::cout << "Stack 2 size: " << st2.size() << '\n';
  std::cout << "Stack 1 size: " << st.size() << '\n';

  st = st2;

  std::cout << "Stack 1 element: " << st.pop() << '\n';
  std::cout << "Stack 1 size: " << st.size() << '\n';
}