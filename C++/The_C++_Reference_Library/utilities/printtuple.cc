#include "tuple"
#include "iostream"
#include "string"

// helper: print element with index IDX of tuple with MAX elements
template<int IDX, int MAX, typename... Args>
struct PRINT_TUPLE {
  static void print(std::ostream &strm, const std::tuple<Args...>& t) {
    strm << std::get<IDX>(t) << (IDX+1 == MAX ? "" : ",");
    PRINT_TUPLE<IDX+1, MAX, Args...>::print(strm, t);
  }
};

// partial specialization to end the recursion
template <int MAX, typename... Args>
struct PRINT_TUPLE<MAX, MAX, Args...> {
  static void print(std::ostream& strm, const std::tuple<Args...>& t) {
  }
};

// output operator for tuples
template <typename... Args>
std::ostream& operator <<  (std::ostream &strm,
			    const std::tuple<Args...>& t) {
  strm << "[";
  PRINT_TUPLE<0, sizeof...(Args), Args...>::print(strm, t);
  return strm <<"]";
}

int main() {
  std::tuple<int, float, std::string> t(77, 1.1, "more light");
  std::cout << "io: " << t << std::endl;
  return 0;
}
