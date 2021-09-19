#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

const size_t FACTS[] = {
  1,
  2,
  6,
  24,
  120,
  720,
  5040,
  40320,
  362880,
  3628800,
  39916800,
  479001600,
  6227020800,
  87178291200,
  1307674368000,
  20922789888000,
  355687428096000,
  6402373705728000,
  121645100408832000,
  2432902008176640000
};

size_t fact( size_t n )
{
  assert(n <= 20);
  if (n == 0) return 1;
  return FACTS[n - 1];
}

size_t get_unused_num( const std::vector<bool> &used, size_t block_num ) // 00, 1
{
  size_t number = 0, perm_pos = 0;
  for (; number < used.size(); ++number)
  {
    if (!used[number])
      ++perm_pos; // pp = 
    if (block_num == perm_pos) 
      break;
  }
  return number;
}

void perm_by_num( size_t n_elem, size_t n_perm )
{
  std::vector<bool> isused(n_elem, false);

  for (size_t i = 0; i < n_elem; ++i)
  {
    size_t block_num = (n_perm - 1) / fact(n_elem - i - 1) + 1;
    size_t new_num = get_unused_num(isused, block_num);
    std::cout << new_num + 1 << " ";
    isused[new_num] = true;
    n_perm = (n_perm - 1) % fact(n_elem - i - 1) + 1;
  }
}

int main( void )
{
  size_t num_am = 0, perm_num = 0;
  std::cin >> num_am >> perm_num;

  perm_by_num(num_am, perm_num);

  return 0;
}