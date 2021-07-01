#include <iostream>

const char TARGET = '4';

const int M = 4;
const int N = 6;

bool used[M][N];

int floodFill(char a[M][N], const char target, int row, int col)
{
  if (row < 0 || col < 0 || row >= M || col >= N ||
      used[row][col] || a[row][col] != target)
  {
    return 0;
  }

  used[row][col] = true;
  int result = 1 + floodFill(a, target, row + 1, col) +
               floodFill(a, target, row - 1, col) +
               floodFill(a, target, row, col + 1) +
               floodFill(a, target, row, col - 1);
  used[row][col] = false;

  return result;
}

int maxArea(char a[M][N], const char target)
{
  int maxArea = 0;

  for (size_t i = 0; i < M; i++)
    for (size_t j = 0; j < N; j++)
    {
      if (a[i][j] == target)
      {
        maxArea = std::max(maxArea, floodFill(a, target, i, j));
      }
    }
  return maxArea;
}

int main()
{
  char a[][N] = {
      {'R', 'R', '1', '1', '2', '4'},
      {'1', 'R', 'R', '4', '4', '4'},
      {'S', '4', 'R', 'R', '2', '3'},
      {'4', '4', 'S', 'S', 'R', 'R'},
  };

  std::cout << maxArea(a, TARGET);
}
