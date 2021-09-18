#include <iostream>
#include <cmath>
#include <array>

constexpr size_t MAX_STONES = 23;

int main( void )
{
  size_t stone_amount{0};
  std::array<ssize_t, MAX_STONES> stones;
  std::cin >> stone_amount;
  ssize_t sum = 0;
  for (size_t i = 0; i < stone_amount; ++i)
  {
    std::cin >> stones[i];
    sum += stones[i];
  }

  size_t min_diff = 1ull << 63;
  for (size_t heap_mask = 0, end = 1u << stone_amount; heap_mask < end; ++heap_mask)
  {
    ssize_t heap_sum = 0;
    for (size_t i = 0, shifted = heap_mask; i < stone_amount; ++i, shifted >>= 1)
      heap_sum += (shifted & 1) * stones[i];

    size_t diff = std::abs(sum - heap_sum - heap_sum);
    min_diff = std::min(diff, min_diff);
  }
  std::cout << min_diff << std::endl;
  return 0;
}