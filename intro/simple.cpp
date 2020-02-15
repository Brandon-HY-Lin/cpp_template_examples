#include <iostream>

template <typename  T, typename U>
auto add(T &a, U &b) -> decltype(a+b)
{
  return  a + b;
}

int main () {
  int a=1;
  int b=2;
  // Test integers addition
  std::cout << add(a, b) <<std::endl;
  
  float af = 1.1;
  float bf = 2.1;
  // Test floats addition
  std::cout << add(af, bf) << std::endl;
  
  // Test mix integer and float addition
  std::cout << add(a, bf) << std::endl;
  
}


