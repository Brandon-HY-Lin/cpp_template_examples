#include <iostream>
/*
 *  Pass array by reference
 *  https://stackoverflow.com/questions/10007986/c-pass-an-array-by-reference
 */
 
 template <typename T, std::size_t N>
 void copy_array(T const (&source)[N], T(&dest)[N])
 {
   std::copy(std::begin(source), std::end(source), dest);
 }

int main () {
  int int_source[] = {1, 2, 3};
  int int_dest [] = {0, 0, 0};
  
  copy_array<int, 3>(int_source, int_dest);
  
  for (auto& i : int_dest) {
    std::cout << i << ", ";
  }
  
  std::cout << std::endl;
  
}