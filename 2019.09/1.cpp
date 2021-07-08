#include <iostream>

// B.
template <typename ReturnType, typename InputType, typename OpType>
ReturnType fold_left(InputType *arr, size_t size, OpType op, ReturnType nil)
{
  ReturnType result = nil;
  for (size_t i = 0; i < size; ++i)
    result = op(result, arr[i]);
  return result;
}

int op(char Digit, int Result) { return (Result * 10) + (Digit - '0'); }

int str_to_int(const char *str) { return (str == nullptr) ? 0 : fold_left(str, strlen(str), op, 0); }

// A.
bool find(int value, int *arr, size_t size)
{
  if (size == 0)
    return false;

  size_t mid = size / 2;

  if (value == arr[mid])
    return true;

  if (value < arr[mid])
    return find(value, arr, mid);

  return find(value, arr + mid + 1, mid);
}

int main()
{
  int arr[] = {1, 2, 5, 10, 12, 13};
  int size = sizeof(arr) / sizeof(int);

  std::cout << find(1, arr, size) << '\n';
  std::cout << find(2, arr, size) << '\n';
  std::cout << find(5, arr, size) << '\n';
  std::cout << find(10, arr, size) << '\n';
  std::cout << find(12, arr, size) << '\n';
  std::cout << find(13, arr, size) << '\n';
  std::cout << find(0, arr, size) << '\n';

  std::cout << str_to_int("0");
}
