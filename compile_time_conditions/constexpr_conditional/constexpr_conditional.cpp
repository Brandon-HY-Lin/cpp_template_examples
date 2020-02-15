#include <iostream>
#include <cstring>

template <typename T, std::size_t N>
void copy_array(const T (&source)[N], T (&dest)[N])
{
    if constexpr (std::is_trivially_copyable_v<T>) {
      std::cout << "Copy using std::memcpy" << std::endl;
      std::memcpy(dest, source, N * sizeof(T));
    } else {
        std::cout << "Copy using std::copy" << std::endl;
        std::copy(std::begin(source), std::end(source), dest);
    }
}

struct Data {
  float x, y;
  
  Data() {}
  
  Data(float x, float y) : x(x), y(y) {}
  
  Data(Data const & d) : x(d.x), y(d.y) {}
};

std::ostream& operator<<(std::ostream& stream, const Data d)
{
  stream << d.x << ", " << d.y;
  return stream;
}

int main () {
  
  int int_source[] = {1, 2, 3};
  int int_dest[3];
  std::cout << "Before copying int" << std::endl;
  copy_array<int, 3>(int_source, int_dest);
  
  std::cout << "\n\n";
  
  Data data_source[] = {{4, 5}, {6, 7}, {8, 9}};
  Data data_dest[3];
  std::cout << "Before copying data" << std::endl;
  copy_array<Data, 3>(data_source, data_dest);
}