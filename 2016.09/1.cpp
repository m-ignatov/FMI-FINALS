#include <iostream>

using namespace std;

int size(const char *word)
{
  const char *iter = word;
  while (*iter != '\0')
  {
    iter++;
  }
  return iter - word;
}

pair<int, int> maxDistance(const char *word)
{
  pair<int, int> maxPair = pair<int, int>(0, 0);

  int sizeWord = size(word);
  for (size_t i = 0; i < sizeWord / 2; i++)
    for (size_t j = sizeWord - 1; j >= sizeWord / 2 && (j - i) > (maxPair.second - maxPair.first); j--)
    {
      if (word[i] == word[j])
      {
        maxPair.first = i;
        maxPair.second = j;
        break;
      }
    }
  return maxPair;
}

int main()
{
  const char *word = "this is just a simple example";
  pair<int, int> distance = maxDistance(word);

  std::cout << distance.first << ' ' << distance.second << '\n';
}
