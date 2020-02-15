#include <iostream>

template <typename T>
struct is_int
{
  static bool const value{false};
};

template <>
struct is_int<int>
{
  static bool const value{true};
};

int main () {
  std::cout << "float : " << is_int<float>::value << std::endl;
  
  std::cout << "int : " << is_int<int>::value << std::endl;
}