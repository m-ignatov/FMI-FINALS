#include <iostream>

const int MAX_N = 50;

void swap(int &a, int &b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

int toCharArray(int digit, char arr[], int index)
{
  if (digit == 0)
  {
    return index;
  }
  int size = toCharArray(digit / 10, arr, index + 1);
  arr[size - 1 - index] = (digit % 10) + '0';
  return size;
}

bool lessLex(int a, int b)
{
  char arrA[MAX_N];
  char arrB[MAX_N];

  int sizeA = toCharArray(a, arrA, 0);
  int sizeB = toCharArray(b, arrB, 0);

  arrA[sizeA] = '\0';
  arrB[sizeB] = '\0';

  for (int i = 0;; i++)
  {
    if (arrA[i] < arrB[i])
    {
      return true;
    }
    if (arrA[i] > arrB[i])
    {
      return false;
    }
  }
  return false;
}

void sortLex(int a[], int n)
{
  for (size_t i = n - 1; i > 0; i--)
    for (size_t j = 0; j < i; j++)
    {
      if (!lessLex(a[j], a[j + 1]))
      {
        swap(a[j], a[j + 1]);
      }
    }
}

void printArray(int a[], int n)
{
  for (size_t i = 0; i < n; i++)
  {
    std::cout << a[i] << ' ';
  }
  std::cout << '\n';
}

int main()
{
  int a[] = {13, 14, 7, 2018, 9, 99, 0};
  int n = 6;

  printArray(a, n);
  sortLex(a, n);
  printArray(a, n);
}
