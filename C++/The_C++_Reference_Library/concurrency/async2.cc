#include "future"
#include "list"
#include "iostream"
#include "exception"

void task1() {
  // endless insertion and memory allocation
  // - will sooner or later raise an exception
  // - BEWARE: this is bad practice
  std::list<int> v;
  while (true) {
    for (int i = 0; i < 1000000; ++i) {
      v.push_back(i);
    }
    std::cout.put('.').flush();
  }
}

int main() {
  std::cout << "starting 2 tasks" << std::endl;
  std::cout << "- task1: process endless loop of memory comsumption"
	    << std::endl;
  std::cout << "- task2: wait for <return> and then for task1" << std::endl;
  
  // start task1() asynchronously (now or later or never)
  auto f1 = std::async(task1);
  

  std::cin.get();  // read a character (like getchar())
  std::cout << "\n wait for the end of task1: " << std::endl;
  try {
    // This exception will terminate the thread because it isn't caught.
    // The future object will keep this state utill get() is called.
    // With get(), the exception gets further propagated inside main()
    f1.get();  // wait for task1() to finish (raises exception if any)
  } catch(const std::exception& e) {
    // probably bad_alloc exception
    std::cerr << "EXCEPTION: " << e.what() << std::endl;
  }
}
