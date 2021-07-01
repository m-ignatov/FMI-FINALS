#include <iostream>

const int M = 3;
const int N = 3;
const int SIZE = 100;

const char a[M][N][SIZE] = {
    {"Algebra", "Analitichna geometriya", "Matematika"},
    {"Uvod v programiraneto", "OOP", "SDA"},
    {"AI", "Data bases", "FP"},
};

void computePassword(const char a[][SIZE])
{
  int midBookIndex = (N % 2) ? (N / 2) : ((N / 2) + 1);
  int counter = 0;

  for (size_t i = 0; a[midBookIndex][i] != '\0'; i++)
  {
    if (a[midBookIndex][i] == ' ')
    {
      std::cout << counter << ' ';
      counter = 0;
      continue;
    }
    counter++;
  }
  std::cout << counter << ' ';
}

void revealPassword(int m, int n, const char a[][N][SIZE])
{
  for (size_t i = 0; i < m; i++)
  {
    bool isSorted = true;
    
    for (size_t j = 0; j < N - 1; j++)
    {
      if (strcmp(a[i][j], a[i][j + 1]) > 0)
      {
        isSorted = false;
        break;
      }
    }
    if (isSorted)
    {
      computePassword(a[i]);
    }
  }
}

int main()
{
  revealPassword(M, N, a);
}
