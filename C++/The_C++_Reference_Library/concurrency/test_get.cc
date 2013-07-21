#include "chrono"
#include "iostream"
#include "future"
#include "thread"

int gao() {
  
}

int main() {
  std::future<int> f = std::async([]{
      std::this_thread::sleep_for(std::chrono::seconds(2));
      return 1;
    });
  if (f.wait_for(std::chrono::seconds(1)) != std::future_status::ready) {
    std::cout << "after waiting for 1s, it's still not ready" << std::endl;
  }
  std::cout << f.get() << std::endl;
  std::cout << f.get() << std::endl;
  std::cout << "end" << std::endl;
  return 0;
}
