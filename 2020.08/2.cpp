#include <iostream>
#include <algorithm>

class Interval
{
public:
  Interval(int a, int k)
  {
    this->a = a;
    this->k = k;
    this->current = a;
  }

  long long operator*() const
  {
    return current;
  }

  long long max() const
  {
    return a + k;
  }

  long long operator++()
  {
    if (last())
    {
      return this->current;
    }
    return ++this->current;
  }

  long long operator++(int)
  {
    if (last())
    {
      return this->current;
    }
    return this->current++;
  }

  void reset()
  {
    this->current = a;
  }

  bool last() const
  {
    return this->current == max();
  }

private:
  int a;
  int k;
  long long current;
};

class SquaredInterval : public Interval
{
public:
  SquaredInterval(int a, int k) : Interval(a, k) {}

  long long operator*() const
  {
    return Interval::operator*() * Interval::operator*();
  }

  bool operator<(const SquaredInterval &rhs) const
  {
    return this->max() < rhs.max();
  }
};

void a()
{
  Interval i(0, 10);

  do
  {
    ++i;
    std::cout << *i << ' ';
  } while (!i.last());

  std::cout << '\n';
}

void b()
{
  SquaredInterval si(5, 10);

  std::cout << *si << ' ';
  std::cout << ++si << ' ';
  std::cout << *si << '\n';
}

void c()
{
  SquaredInterval sis[] = {
      SquaredInterval(2, 30),
      SquaredInterval(4, 10),
      SquaredInterval(1, 2),
  };

  int size = sizeof(sis) / sizeof(SquaredInterval);

  for (int i = 0; i < size; i++)
  {
    std::cout << *sis[i] << ' ';
  }
  std::cout << '\n';

  std::sort(sis, sis + size);

  for (int i = 0; i < 3; i++)
  {
    std::cout << *sis[i] << ' ';
  }
  std::cout << '\n';
}

int main()
{
  a();
  b();
  c();
}
