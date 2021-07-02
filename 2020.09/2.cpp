#include <iostream>
#include <queue>

struct Node
{
  char text;
  Node *left, *right;
};

Node *newNode(char text)
{
  Node *n = new Node();
  n->text = text;
  n->left = nullptr;
  n->right = nullptr;

  return n;
}

int findDepth(Node *root)
{
  if (!root)
  {
    return 0;
  }
  int depth = 0;
  depth = std::max(depth, findDepth(root->left));
  depth = std::max(depth, findDepth(root->right));

  return depth + 1;
}

void printText(Node *root)
{
  int depth = findDepth(root);
  int currentDepth = 0;

  std::queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    currentDepth++;

    int size = q.size();
    for (int i = 1; i <= size; i++)
    {
      Node *current = q.front();
      q.pop();

      std::cout << current->text;

      if (current->left == nullptr && current->right == nullptr && currentDepth + 1 >= depth)
      {
        continue;
      }

      Node *left = current->left;
      Node *right = current->right;

      if (current->left == nullptr)
      {
        left = newNode(' ');
      }
      if (current->right == nullptr)
      {
        right = newNode(' ');
      }

      q.push(left);
      q.push(right);
    }
    std::cout << '\n';
  }
}

int main()
{
  Node *root = newNode('I');
  root->left = newNode('a');
  root->left->right = newNode('o');
  root->left->right->right = newNode('s');
  root->left->right->right->right = newNode('o');
  root->left->right->right->left = newNode('r');

  root->left->left = newNode('g');
  root->left->left->right = newNode('t');
  root->left->left->right->right = newNode('p');

  root->left->left->left = newNode('a');
  root->left->left->left->right = newNode('g');
  root->left->left->left->right->right = newNode('!');
  root->left->left->left->left = newNode('n');
  root->left->left->left->left->left = newNode('s');

  root->right = newNode('m');
  root->right->right = newNode('d');
  root->right->right->right = newNode('i');
  root->right->right->left = newNode('v');

  root->right->left = newNode('o');
  root->right->left->left = newNode('o');
  root->right->left->left->left = newNode('b');
  root->right->left->left->right = newNode('l');

  root->right->left->right = newNode('l');
  root->right->left->right->right = newNode('m');
  root->right->left->right->left = newNode('e');

  printText(root);
}