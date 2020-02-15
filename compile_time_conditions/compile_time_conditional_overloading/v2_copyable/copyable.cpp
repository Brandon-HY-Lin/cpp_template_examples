#include <iostream>
#include <vector>
#include <cstring>

/* use if not memcpy safe
 * Equals: void copy_array(Data const (&source)[N], Data (&dest)[N]);
 * 
 * Note: typename std::enable_if_t<not std::is_trivially_copyable_v<T>, void>
 *            will becomes 'void'
 */
template <typename T, std::size_t N>
typename std::enable_if_t<not std::is_trivially_copyable_v<T>, void>
copy_array(T const (&source)[N], T (&dest)[N])
{
  std::cout << "Copy using iterator" << std::endl;
  std::copy(std::begin(source), std::end(source), dest);
}

/* use if memcpy safe
  * Equals: void copy_array(T const (&source)[N], T (&dest)[N]);
  * 
 * Note: typename std::enable_if_t<std::is_trivially_copyable_v<T>, void>
 *            will becomes 'void'
 */
template <typename T, std::size_t N>
typename std::enable_if_t<std::is_trivially_copyable_v<T>, void>
copy_array(T const (&source)[N], T (&dest)[N])
{
  std::cout << "Copy using memcpy" << std::endl;
  std::memcpy(dest, source, N * sizeof(T));
}

// Define Data that is different than integer.
struct Data {
  float x, y;
  
  Data() {
  
  }
  
  Data(float x, float y) : x(x), y(y) {
//    std::cout << "default constructor" << std::endl;
  }
  
  Data(const Data& d) : x(d.x), y(d.y) {
//    std::cout << "copy constructor" << std::endl;
  }
};

  std::ostream& operator<<(std::ostream& stream, const Data& d)
  {
    stream  << d.x << ", " << d.y;
    return stream;
  }

int main () {
  
  int int_source[] = {1, 2, 3};
  int int_dest[3];
  
  std::cout << "Before copying int_source" << std::endl;
  copy_array<int, 3>(int_source, int_dest);
  
//  std::cout << "Print int_dest" << std::endl;
//  for (const auto& i : int_dest) {
//    std::cout << i << ", ";
//  }
//  
  std::cout << "\n\n";

  Data data_source[3] = {{1, 2}, {3, 4}, {5, 6}};
  Data data_dest[3];
  
  std::cout << "Before copying data_source" << std::endl;
  copy_array<Data, 3>(data_source, data_dest);
  
//  std::cout << "Print copying data_dest" << std::endl;
//  for (const auto& d : data_dest) {
//    std::cout << "(" << d << "), ";
//  }
  
  std::cout << std::endl;
}