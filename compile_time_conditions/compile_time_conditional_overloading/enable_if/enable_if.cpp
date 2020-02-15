#include <iostream>

template <bool B, typename T>
struct enable_if;

template <typename T>
struct enable_if<true, T> {
  using type = T;
};

int main () {
  
  // declare variable
  enable_if<true, float>::type  data_float = 1.1;
  std::cout << data_float << std::endl;
}