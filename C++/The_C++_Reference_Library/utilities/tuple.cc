#include "tuple"
#include "complex"
#include "iostream"
#include "string"
#include "algorithm"

int main() {
  std::tuple<std::string, int, int, std::complex<double>> t;
  std::get<2>(t) = 2;
  std::cout << std::get<2>(t) << std::endl;
  // std::cout << t << std::endl;
  
  std::string s = "abc";
  // std::tuple<std::string &> tt(s);
  // auto tt = std::make_tuple(std::ref(s));
  
  auto tt = std::tie(s);
  std::get<0>(tt) = "efg";
  std::cout << s << std::endl;

  typedef std::tuple<std::string, int> tuple_type;
  std::cout << std::tuple_size<tuple_type>::value << std::endl;
  std::tuple_element<1, tuple_type>::type x = 1;

  auto tt2 = std::tuple_cat(std::make_tuple(1), std::make_tuple(2), std::make_tuple(3));
  std::cout << std::get<2>(tt2) << std::endl;
}
