#include <iostream>

int main()
{
  size_t purch_amount = 0;
  std::cin >> purch_amount;
  ssize_t fives_needed = 0, fives_saved = 0;

  for (size_t i = 0; i < purch_amount; ++i)
  {
    size_t purchase = 0;
    std::cin >> purchase;
    if (purchase == 5) 
      ++fives_saved;
    else
    {
      fives_needed += (purchase - 5) / 5 - fives_saved;
      fives_saved = 0;
    }
  }

  std::cout << (fives_needed > 0 ? fives_needed : 0) << std::endl;
  return 0;
}