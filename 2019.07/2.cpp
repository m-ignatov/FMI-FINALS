#include <iostream>
#include <vector>

using namespace std;

class Vertex
{
public:
  Vertex(char symbol, int value) : symbol(symbol), value(value) {}

  char sym() const
  {
    return symbol;
  }

  int val() const
  {
    return value;
  }

  const vector<Vertex *> &getChildren() const
  {
    return children;
  }

  void addChild(Vertex *child)
  {
    children.push_back(child);
  }

private:
  int value;
  char symbol;
  vector<Vertex *> children;
};

void computePair(Vertex *v, int value, string word,
                 vector<pair<int, string> > &paths)
{
  vector<Vertex *> children = v->getChildren();
  if (children.empty())
  {
    paths.push_back(pair<int, string>(value, word));
    return;
  }

  for (size_t i = 0; i < children.size(); i++)
  {
    Vertex *child = children[i];
    computePair(child, value + child->val(), word + child->sym(), paths);
  }
}

int sumVal(Vertex *u, Vertex *v)
{
  vector<pair<int, string> > pathsU;
  vector<pair<int, string> > pathsV;

  computePair(u, u->val(), string(1, u->sym()), pathsU);
  computePair(v, v->val(), string(1, v->sym()), pathsV);

  for (size_t i = 0; i < pathsU.size(); i++)
    for (size_t j = 0; j < pathsV.size(); j++)
    {
      if (pathsU[i].second == pathsV[j].second)
      {
        return pathsU[i].first;
      }
    }
  return 0;
}

int main()
{
  Vertex *root = new Vertex('a', 1);
  Vertex *v1 = new Vertex('b', 0);
  Vertex *v2 = new Vertex('c', 3);

  Vertex *v3 = new Vertex('a', 1);
  Vertex *v4 = new Vertex('b', 1);
  Vertex *v5 = new Vertex('c', 2);

  root->addChild(v1);
  root->addChild(v3);

  v1->addChild(v2);
  v3->addChild(v4);
  v4->addChild(v5);

  std::cout << sumVal(root, v3) << '\n';
}
