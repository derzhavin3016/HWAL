#include <iostream>
#include <string>
#include <cassert>

size_t str_length(size_t str_num)
{
  // for prev
  if (str_num < 9)
    return (1ull << str_num) - 1;
  return (1ull << str_num) + (1ull << (str_num - 9)) - 2;
}
/*

  1  1 -> 1
  2  211 -> 3
  3  3211112 -> 7
  4  432111122111123 -> 15
  5  5432111122111123321111221111234

*/
char get_sym(size_t str_num, size_t pos) // 2, 2
{
  if (pos == 0)
  {
    size_t div = (str_num + 1) / 10;
    return '0' + (div ? div : (str_num + 1) % 10);
  }
  if (str_num >= 9)
  {
    if (pos == 1)
      return '0' + (str_num + 1) % 10;
    --pos;
  }

  size_t prev_str_len = str_length(str_num); // 2^1 == 2

  if (pos <= prev_str_len) // 2 < 2 ? - no
    return get_sym(str_num - 1, pos - 1);
  return get_sym(str_num - 1, prev_str_len + prev_str_len - pos); // str_num = 1, pos = 0 => a
}

int main(void)
{
  size_t str_num = 0, to_find = 0;
  std::cin >> str_num >> to_find;
  --str_num;

  for (size_t i = 0; i < to_find; ++i)
  {
    size_t pos = 0;
    std::cin >> pos;
    std::cout << get_sym(str_num, --pos);
  }
  std::cout << std::endl;
  return 0;
}