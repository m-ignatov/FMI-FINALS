#include <iostream>

template <typename T>
struct Node
{
  T value;
  Node *next;

  Node(T value) : value(value), next(nullptr) {}
};

template <typename T>
class Queue
{
public:
  Queue();
  Queue(const Queue<T> &);
  Queue<T> &operator=(const Queue<T> &);
  ~Queue();

  void pop();
  void push(const T &);
  T back() const;
  T front() const;
  int size() const;
  bool empty() const;

private:
  Node<T> *head;
  Node<T> *tail;
  int length;

  void deleteQueue();
  void copyQueue(const Queue<T> &);
};

template <typename T>
Queue<T>::Queue() : length(0), head(nullptr), tail(nullptr) {}

template <typename T>
Queue<T>::Queue(const Queue<T> &rhs)
{
  copyQueue(rhs);
}

template <typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &rhs)
{
  if (this != &rhs)
  {
    deleteQueue();
    copyQueue(rhs);
  }
  return *this;
}

template <typename T>
Queue<T>::~Queue()
{
  deleteQueue();
}

template <typename T>
void Queue<T>::pop()
{
  if (head)
  {
    if (head->next)
    {
      Node<T> *deleteNode = head;
      delete deleteNode;
      head = head->next;
    }
    else
    {
      tail = nullptr;
      head = nullptr;
    }
    length--;
  }
}

template <typename T>
void Queue<T>::push(const T &value)
{
  if (tail)
  {
    Node<T> *newNode = new Node<T>(value);
    tail->next = newNode;
    tail = newNode;
  }
  else
  {
    head = tail = new Node<T>(value);
  }
  length++;
}

template <typename T>
T Queue<T>::back() const
{
  if (tail)
  {
    return tail->value;
  }
  return -1;
}

template <typename T>
T Queue<T>::front() const
{
  if (head)
  {
    return head->value;
  }
  return -1;
}

template <typename T>
int Queue<T>::size() const
{
  return length;
}

template <typename T>
bool Queue<T>::empty() const
{
  return (length == 0);
}

template <typename T>
void Queue<T>::deleteQueue()
{
  Node<T> *current = head;
  while (head)
  {
    current = head;
    delete current;
    head = head->next;
  }
}

template <typename T>
void Queue<T>::copyQueue(const Queue<T> &rhs)
{
  length = rhs.length;

  Node<T> *rhsCurrent = rhs.head;
  head = tail = new Node<T>(rhsCurrent->value);

  Node<T> *current = head;
  rhsCurrent = rhsCurrent->next;

  while (rhsCurrent)
  {
    current->next = new Node<T>(rhsCurrent->value);
    tail = current->next;

    current = current->next;
    rhsCurrent = rhsCurrent->next;
  }
}

int main()
{
  Queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  Queue<int> q2 = q;
  q2.pop();

  std::cout << q2.front() << '\n';
  std::cout << q2.back() << '\n';
}
