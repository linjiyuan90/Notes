#include "future"
#include "iostream"
#include "string"
#include "chrono"

int do_something() {
  std::cout << "sleeping  ... " << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(2));
  std::cout << "wake up" << std::endl;
  return -1;
}

int main() {
  // something like std:bind(), store the function rather than call it
  std::packaged_task<int()> pt(do_something);
  std::future<int> f = pt.get_future();
  std::cout << "before call pt() " << std::endl;
  pt();  // should be invoke before f.get()
  std::cout << "after call pt() " << std::endl;
  std::cout << "out: " << f.get() << std::endl;
  return 0;
}
