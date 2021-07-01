#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

const char *FILE_PATH = "./output.txt";

const char *OPEN_BR = "(";
const char *CLOSE_BR = ")";
const char *EMPTY_NODE = "* ";

struct Node
{
  char value;

  Node *firstChild;
  Node *secondChild;
  Node *thirdChild;

  Node(char value) : value(value), firstChild(nullptr),
                     secondChild(nullptr), thirdChild(nullptr) {}
};

void printRecursively(Node *node, ofstream &outFile)
{
  if (node == nullptr)
  {
    outFile << EMPTY_NODE;
    return;
  }
  outFile << OPEN_BR << node->value << ' ';

  printRecursively(node->firstChild, outFile);
  printRecursively(node->secondChild, outFile);
  printRecursively(node->thirdChild, outFile);

  outFile << CLOSE_BR;
}

void serialize(Node *root, const char *filePath)
{
  ofstream outFile(filePath);
  if (!outFile.is_open())
  {
    cerr << "File could not be opened.\n";
    return;
  }
  printRecursively(root, outFile);
  outFile.close();
}

int maxDepth(Node *root)
{
  if (root == nullptr)
  {
    return 0;
  }

  int depth = 0;
  depth = max(depth, maxDepth(root->firstChild));
  depth = max(depth, maxDepth(root->secondChild));
  depth = max(depth, maxDepth(root->thirdChild));

  return depth + 1;
}

void readLast(Node *root)
{
  queue<Node *> q;
  q.push(root);

  int currentDepth = 0;
  int depth = maxDepth(root);

  while (currentDepth + 1 != depth)
  {
    int sizeQ = q.size();
    for (size_t i = 1; i <= sizeQ; i++)
    {
      Node *current = q.front();
      q.pop();

      if (current->firstChild)
        q.push(current->firstChild);
      if (current->secondChild)
        q.push(current->secondChild);
      if (current->thirdChild)
        q.push(current->thirdChild);
    }
    currentDepth++;
  }

  while (!q.empty())
  {
    Node *current = q.front();
    q.pop();

    std::cout << current->value;
  }
}

int main()
{
  Node *root = new Node('b');

  Node *nodeX = new Node('x');
  Node *nodeY = new Node('y');
  Node *nodeP = new Node('p');
  Node *nodeQ = new Node('q');
  Node *nodeR = new Node('r');
  Node *nodeS = new Node('s');
  Node *nodeC = new Node('c');
  Node *nodeA = new Node('a');
  Node *nodeT = new Node('t');

  root->firstChild = nodeX;
  root->secondChild = nodeY;

  nodeX->firstChild = nodeP;
  nodeX->secondChild = nodeQ;
  nodeX->thirdChild = nodeR;

  nodeR->firstChild = nodeC;
  nodeR->thirdChild = nodeA;

  nodeY->thirdChild = nodeS;
  nodeS->secondChild = nodeT;

  readLast(root);
  serialize(root, FILE_PATH);
}
