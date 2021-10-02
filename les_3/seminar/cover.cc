#include <iostream>
#include <vector>
#include <algorithm>
using vec_t = std::vector<double>;

int main()
{
  size_t num = 0;
  std::cin >> num;
  vec_t vec(num);
  for (auto &&elem : vec)
    std::cin >> elem;
  std::sort(vec.begin(), vec.end());
  double s1 = 0, s2 = 0;
  for (auto el : vec)
    if (s1 < s2)
      s1 += el;
    else 
      s2 += el;
  
  return 0;
}
