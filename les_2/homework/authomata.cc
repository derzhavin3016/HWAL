#include <iostream>

int main()
{
  size_t purch_amount = 0;
  std::cin >> purch_amount;
  size_t fives_needed = 0, fives_saved = 0;

  for (size_t i = 0; i < purch_amount; ++i)
  {
    ssize_t purchase = 0;
    std::cin >> purchase;
    if (purchase == 5) 
      ++fives_saved;
    else
    {
      ssize_t diff = (purchase - 5) / 5 - (ssize_t)fives_saved;
      if (diff < 0)
        fives_saved = -diff;
      else
      {
        fives_needed += diff;
        fives_saved = 0;
      }
    }
  }

  std::cout << fives_needed << std::endl;
  return 0;
}