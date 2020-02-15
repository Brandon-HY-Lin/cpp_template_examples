#include <iostream>
#include <cstdio>

/*
 * Check type equality
 */
template <typename T, typename U>
struct is_same {
  static const bool value{false};
  };
  
  template <typename T>
  struct is_same<T, T> {
    static const bool value{true};
    };
  
template <typename T, typename U>
constexpr bool is_same_v{is_same<T, U>::value};


/*
 *   Remove const 
 */ 
 template <typename T>
 struct remove_const {
    using type = T;
 };
 
 template <typename T>
 struct remove_const <T const> {
   using type = T;
 };
 
 template <typename T>
using remove_const_t = typename remove_const<T>::type;

int main () {
  // Test flaot, int
  printf("%-60s", "Compare 'float' and 'int':");
  std::cout << is_same_v<float, int> << std::endl;
  
  // Test int, int
  printf("%-60s", "Compare 'int' and 'int' : ");
  std::cout << is_same_v<int, int> << std::endl;
  
  // Test int, int const
  printf("%-60s", "Compare 'int' and 'int const' : ");
  std::cout << is_same_v<int, int const> << std::endl;
  
  // Test int, int const using remove_const_t
  printf("%-60s","Compare 'int ' and 'remove_const_t(int const)' : ");
  std::cout << is_same_v<int, remove_const_t<int const>> << std::endl;

  // Test int const, int const after applying the latter with remove_const_t
  printf("%-60s", "Compare 'int const' and 'remove_const_t(int const)' : ");
  std::cout << is_same_v<int const, remove_const_t<int const>> << std::endl;
}