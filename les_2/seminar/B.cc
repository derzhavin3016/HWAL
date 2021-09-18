#include <iostream>
#include <string>

char get_sym( size_t str_num, size_t pos ) // 2, 2
{
  if (pos == 0) return 'a' + str_num;

  size_t str_len = 1ull << str_num; // 2^1 == 2

  if (pos < str_len) // 2 < 2 ? - no
    return get_sym(str_num - 1, pos - 1);
  return get_sym(str_num - 1, pos - str_len); // str_num = 1, pos = 0 => a
}

int main( void )
{
  size_t str_num = 0, start = 0, end = 0;
  std::cin >> str_num >> start >> end;
  std::string res{};
  res.reserve(end - start + 1);
  --str_num, --start, --end;
  // 2 1 3
  for (size_t i = start; i <= end; ++i)
    res.push_back(get_sym(str_num, i));
  
  std::cout << res;
  return 0;
}