#include "thread"
#include "future"
#include "iostream"
#include "string"
#include "exception"
#include "stdexcept"
#include "functional"
#include "utility"

void do_something(std::promise<std::string> &p) {
  try {
    // read character and throw exception if 'x'
    std::cout << "read char ('x' for exception): ";
    char c = std::cin.get();
    if (c == 'x') {x
      throw std::runtime_error(std::string("char ") + c + " read");
    }
    std::string s = std::string("char ") + c + " processed";
    p.set_value(std::move(s));  // store result
    // p.set_value_at_thread_exit(std::move(s));
  } catch (...) {
    p.set_exception(std::current_exception());  // store exception
    // p.set_exception_at_thread_exit(std::current_exception());
  }
  std::this_thread::sleep_for(std::chrono::seconds(5));
  std::cout << "thread end" << std::endl;
}

int main() {
  try {
    // start thread using a promise to store the outcome
    std::promise<std::string> p;
    // promise only support reference
    std::thread t(do_something, std::ref(p));
    t.detach();

    // create a future to process the outcome
    std::future<std::string> f(p.get_future());
    // process the outcome
    std::cout << "result: " << f.get() << std::endl;
  } catch(const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  } catch(...) {
    std::cerr << "Exception " << std::endl;
  }
  return 0;
  // pthread_exit(NULL);
}
