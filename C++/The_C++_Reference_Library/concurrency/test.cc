
#include "future"
#include "thread"
#include "chrono"
#include "random"
#include "iostream"
#include "exception"

int do_something(char c) {
  // random-number generator (use c as seed to get different sequences)
  std::default_random_engine dre(c);
  std::uniform_int_distribution<int> id(10, 1000);

  // loop to print character after a random period of time
  for (int i = 0; (c=='.') || i < 10; i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
    std::cout.put(c).flush();
  }
  return c;
}

int func1() {
  return do_something('.');
}

int func2() {
  return do_something('+');
}

std::future<int> result1(std::async(std::launch::async, func1));


int main() {
  std::cout << std::thread::hardware_concurrency() << std::endl;
  std::cout << "Starting func1() in background"
	    << " and func2() in foreground: " << std::endl;

  // start func1() asychronously (now or later or never)
  // use std::launch::async to start the thread immediately

  int result2 = func2();  // call func2() synchronously (here and now)

  // print result (wait for func1() to finish and add its result to result2
  int result = result2;
  
  std::cout << "\n result of func1() + func2(): " << result
	    << std::endl;
}
