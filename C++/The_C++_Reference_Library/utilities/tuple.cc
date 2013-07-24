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
}
