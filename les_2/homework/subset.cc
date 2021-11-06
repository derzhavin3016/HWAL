#include <iostream>
#include <string>
#include <algorithm>

using std::string;
using std::cout;
using std::cin;
using std::endl;


void print_set( const string &input, size_t idx, string s )
{
  if (idx == input.size())
  {
    cout << s << endl;
    return;
  } 
  print_set(input, idx + 1, s);
  s += input[idx];
  print_set(input, idx + 1, s);
}

int main( void )
{
  string input{};
  cin >> input;
  // Here goes answer
  print_set(input, 0, "");
  return 0;
}