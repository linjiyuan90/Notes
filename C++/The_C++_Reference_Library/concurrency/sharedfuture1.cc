#include "future"
#include "thread"
#include "iostream"
#include "exception"
#include "stdexcept"

int query_number() {
  // read number
  std::cout << "read number: ";
  int num;
  std::cin >> num;

  // throw exception if none
  if (!std::cin) {
    throw std::runtime_error("no numebr read");
  }

  return num;
}

// const shared_future<int> &f
// may be danger
void do_something(char c, std::shared_future<int> f) {
  try {
    // wait for numebr of characters to print
    int num = f.get();  // get result of query_number()

    for (int i = 0; i < num; i++) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      std::cout.put(c).flush();
    }
  } catch (const std::exception &e) {
    std::cerr << "Exception in thread " << std::this_thread::get_id()
	      << " : " << e.what() << std::endl;
  }
}

int main() {
  try {
    // start one thread to query a number
    std::shared_future<int> f = std::async(query_number);

    // start three threads each processing this number in a loop
    auto f1 = std::async(std::launch::async, do_something, '.', f);
    auto f2 = std::async(std::launch::async, do_something, '+', f);
    auto f3 = std::async(std::launch::async, do_something, '*', f);

    // wait for all loops to be finished
    f1.get();
    f2.get();
    f3.get();
  } catch(const std::exception &e) {
    std::cout << "\nException: " << e.what() << std::endl;
  }
  std::cout << "\ndone" << std::endl;
}
