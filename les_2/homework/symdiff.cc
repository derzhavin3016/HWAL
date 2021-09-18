#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>

constexpr size_t MAXNUM = 20000;
class set
{
private:
  using T = uint32_t;
  enum
  {
    CH_SIZE = 8 * sizeof(T)
  };

  std::vector<T> chunks;

public:
  set(size_t size) : chunks(size)
  {
  }

  void insert(size_t num)
  {
    --num;
    size_t ch_num = num / CH_SIZE,
           ch_pos = num % CH_SIZE;
    std::cout << ch_num << " " << ch_pos << std::endl;
    chunks[ch_num] |= (1u << ch_pos);
    std::cout << std::bitset<CH_SIZE>(chunks[ch_num]) << std::endl;
  }

  bool in(size_t num) const
  {
    --num;
    size_t ch_num = num / CH_SIZE,
           ch_pos = num % CH_SIZE;

    return (chunks[ch_num] >> ch_pos) & 1u;
  }

  void symd(const set &that)
  {
    size_t min_sz = std::min(that.chunks.size(), chunks.size());
    for (size_t i = 0; i < min_sz; ++i)
      chunks[i] ^= that.chunks[i];
  }

  std::ostream &out(std::ostream &ost) const
  {
    for (size_t i = 1; i <= MAXNUM; ++i)
      if (in(i))
        ost << i << (i == MAXNUM ? "" : " ");
    ost << std::endl;

    return ost;
  }

  ~set()
  {
  }
};

std::ostream &operator<<(std::ostream &ost, const set &s)
{
  return s.out(ost);
}

set operator^(const set &lhs, const set &rhs)
{
  set tmp{lhs};
  tmp.symd(rhs);

  return tmp;
}

constexpr size_t set_sz = 625;

void set_inp(std::istream &ist, set &s)
{
  while (1)
  {
    size_t num = 0;
    ist >> num;
    if (num == 0)
      break;
    s.insert(num);
  }
}

int main()
{
  set A{set_sz}, B{set_sz};

  set_inp(std::cin, A);
  set_inp(std::cin, B);

  std::cout << (A ^ B);

  return 0;
}
