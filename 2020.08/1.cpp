#include <iostream>

const char *findNextWord(const char *current, const char *end)
{
  while (!(current[0] <= 32 && (current + 1)[0] > 32) && (current + 1) != end)
  {
    current++;
  }
  return current + 1;
}

void print_backwards(const char *begin, const char *end)
{
  if (begin == end)
  {
    return;
  }

  const char *nextWord = findNextWord(begin, end);
  print_backwards(nextWord, end);

  while (begin[0] > 32)
  {
    std::cout << begin[0];
    begin++;

    if (begin[0] <= 32)
    {
      std::cout << ' ';
    }
  }
}

void print_backwards(const char *string)
{
  int size = 0;
  while ((string + size)[0] != '\0')
  {
    size++;
  }

  const char *begin = string;
  const char *end = string + size;

  print_backwards(begin, end);
}

int main()
{
  print_backwards("\tI\tneed a break!");
}
