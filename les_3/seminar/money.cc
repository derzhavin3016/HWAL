#include <iostream>


int main()
{
  size_t coins_num = 0, sum = 0;
  std::cin >> coins_num;
  for (size_t i = 0; i < coins_num; ++i)
  {
    size_t coin = 0;
    std::cin >> coin;
    if (coin > sum + 1)
      break;
    sum += coin;
  }
  std::cout << sum + 1 << std::endl;
  return 0;
}
