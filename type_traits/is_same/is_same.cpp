#include <iostream>


template <typename T, typename U>
struct is_same{
    static const bool value{false};
  };
  
template <typename T>
struct is_same<T, T>{
  static const bool value{true};
};

template <typename T, typename U>
constexpr bool is_same_v{is_same<T, U>::value};

int main () {
  std::cout << "same : " << is_same_v<float, int> << std::endl;
  std::cout << "same : " << is_same_v<int, int> << std::endl;
}