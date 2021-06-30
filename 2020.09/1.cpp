#include <iostream>

const char *find_manager(const char *employee, const char *leaders[][2], const size_t n)
{
  for (int i = 0; i < n; i++)
  {
    if (strcmp(employee, leaders[i][0]) == 0)
    {
      return leaders[i][1];
    }
  }
  return 0;
}

bool is_subordinate(const char *employee,
                    const char *manager,
                    const char *leaders[][2],
                    size_t n)
{
  const char *direct_manager = find_manager(employee, leaders, n);
  if (!direct_manager)
  {
    return false;
  }
  if (strcmp(direct_manager, manager) == 0)
  {
    return true;
  }
  return is_subordinate(employee, direct_manager, leaders, n);
}

const char *the_big_boss(const char *leaders[][2], size_t n)
{
  for (int i = 0; i < n; i++)
  {
    if (!find_manager(leaders[i][1], leaders, n))
    {
      return leaders[i][1];
    }
  }
  return 0;
}

int main()
{
  const size_t COMPANY_SIZE = 3;
  const char *manager_of[COMPANY_SIZE][2] =
      {
          {"Ivan", "Maria"},
          {"Maria", "Dragan"},
          {"Dragan", "Stoyan"}};

  std::cout << is_subordinate("Ivan", "Maria", manager_of, COMPANY_SIZE) << "\n";
  std::cout << is_subordinate("Maria", "Dragan", manager_of, COMPANY_SIZE) << "\n";
  std::cout << is_subordinate("Maria", "Stoyan", manager_of, COMPANY_SIZE) << "\n";
  std::cout << is_subordinate("Stoyan", "Maria", manager_of, COMPANY_SIZE) << "\n";

  std::cout << the_big_boss(manager_of, COMPANY_SIZE) << "\n";
}