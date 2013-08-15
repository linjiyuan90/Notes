#include "mutex"
#include "iostream"
#include "string"
#include "thread"

class X {
 private:
  mutable std::once_flag init_data_flag;
  void init_data() const {
    std::cout << "init ... " << std::endl;
  }
 public:
  void gao() const {
    std::call_once(init_data_flag, &X::init_data, this);
    std::cout << "gao ... " << std::endl;
  }
};

int main() {

  X x;
  std::thread t1(&X::gao, &x);
  std::thread t2(&X::gao, &x);
  t1.join();
  t2.join();
  return 0;
}
