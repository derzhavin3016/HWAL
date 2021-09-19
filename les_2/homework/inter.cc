#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

template<class Cont>
void input_vec( std::istream &ist, Cont &cont )
{
  for (auto &&elem : cont)
    ist >> elem;
}

template <class Cont>
void intersect_n_print( const Cont &lhs, const Cont &rhs )
{
  auto it_l = lhs.begin(), it_r = rhs.begin();
  while (it_l != lhs.end() && it_r != rhs.end())
  {
    auto &l_val = *it_l;
    auto &r_val = *it_r;
    if (l_val == r_val)
    {
      std::cout << l_val << " ";
      ++it_l, ++it_r;
      continue;
    }
    if (l_val < r_val)
      ++it_l;
    else 
      ++it_r;
  }
  std::cout << std::endl;
}

int main()
{
  size_t A_sz = 0, B_sz = 0;
  std::cin >> A_sz >> B_sz;
  std::vector<int32_t> A(A_sz), B(B_sz);
  
  input_vec(std::cin, A);
  input_vec(std::cin, B);
  
  intersect_n_print(A, B);
  return 0;
}
