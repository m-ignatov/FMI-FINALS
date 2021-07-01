#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
  int value;
  vector<Node *> children;

  void addChild(Node *child)
  {
    children.push_back(child);
  }

  Node(int value) : value(value) {}
};

int depth(Node *root)
{
  if (root->children.empty())
  {
    return 1;
  }
  int depthScore = 0;
  vector<Node *> children = root->children;
  for (size_t i = 0; i < children.size(); i++)
  {
    depthScore = max(depthScore, depth(children[i]));
  }
  return 1 + depthScore;
}

Node *buildTree(int a[], int n, int k)
{
  Node *root = new Node(a[0]);
  Node *current = root;
  queue<Node *> q;

  for (size_t i = 1, child = 0; i < n; i++, child++)
  {
    if (child == k)
    {
      current = q.front();
      q.pop();
      child = 0;
    }
    Node *node = new Node(a[i]);
    current->addChild(node);
    q.push(node);
  }
  return root;
}

int main()
{
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int n = 10;
  int k = 3;

  Node *root = buildTree(a, n, k);
  std::cout << depth(root) << '\n';
}
