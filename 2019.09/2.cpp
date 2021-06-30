#include <iostream>
#include <vector>

using namespace std;

struct Edge
{
  int to;
  int value;
  char label;

  Edge(int to, char label, int value) : to(to), label(label), value(value) {}
};

void computePaths(const vector<vector<Edge> > &tree, int vertex, long long value,
                  string word, vector<pair<string, long long> > &path)
{
  vector<Edge> edges = tree[vertex];
  if (edges.empty())
  {
    path.push_back(pair<string, long long>(word, value));
    return;
  }

  for (size_t i = 0; i < edges.size(); i++)
  {
    Edge neighbourEdge = edges[i];
    computePaths(tree, neighbourEdge.to,
                 value + neighbourEdge.value,
                 word + neighbourEdge.label, path);
  }
}

void CommonBranches(const vector<vector<Edge> > &tree, int u, int v, int k)
{
  vector<pair<string, long long> > pathsU;
  vector<pair<string, long long> > pathsV;

  computePaths(tree, u, 0, "", pathsU);
  computePaths(tree, v, 0, "", pathsV);

  for (size_t i = 0; i < pathsU.size(); i++)
    for (size_t j = 0; j < pathsV.size(); j++)
    {
      if (pathsU[i].first == pathsV[j].first &&
          pathsU[i].second + pathsV[j].second == k)
      {
        cout << pathsU[i].first << '\n';
      }
    }
}

int main()
{
  vector<vector<Edge> > tree(9);

  tree[0].push_back(Edge(1, 'a', 1));
  tree[0].push_back(Edge(5, 'a', 1));

  tree[1].push_back(Edge(2, 'c', 1));
  tree[2].push_back(Edge(3, 'a', 2));
  tree[3].push_back(Edge(4, 'r', 3));

  tree[5].push_back(Edge(6, 'c', 3));
  tree[6].push_back(Edge(7, 'a', 2));
  tree[7].push_back(Edge(8, 'r', 1));

  CommonBranches(tree, 1, 5, 12);
}
