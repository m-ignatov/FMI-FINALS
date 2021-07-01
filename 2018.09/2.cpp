#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

const int MAX_N = 100;
const char *FILE_NAME = "2.txt";

struct Node
{
  int number;

  Node *next;
  Node *kNext;

  Node(int number) : number(number), next(nullptr), kNext(nullptr) {}
};

Node *readList(const char *fileName)
{
  ifstream inputFile(fileName);

  int numbers[MAX_N];
  int n = 0;
  int k = 0;

  if (!inputFile.is_open())
  {
    return nullptr;
  }
  
  while (inputFile >> numbers[n])
  {
    n++;
  }
  inputFile.close();
  k = sqrt(n);

  Node *startNode = new Node(numbers[0]);
  Node *kNode = startNode;
  Node *prevNode = startNode;

  for (int i = 1; i < n; i++)
  {
    Node *newNode = new Node(numbers[i]);
    if (!(i % k))
    {
      kNode->kNext = newNode;
      kNode = newNode;
    }
    prevNode->next = newNode;
    prevNode = newNode;
  }
  return startNode;
}

bool member(Node *list, int target)
{
  while (list != nullptr)
  {
    if (target == list->number)
    {
      return true;
    }

    Node *kNode = list->kNext;
    if (kNode == nullptr)
    {
      list = list->next;
    }
    else
    {
      list = (target > kNode->number) ? kNode : list->next;
    }
  }
  return false;
}

int main()
{
  Node *list = readList(FILE_NAME);
  std::cout << member(list, 6) << '\n';
}
