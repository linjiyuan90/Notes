#include "cassert"

#include "thread"
#include "random"
#include "chrono"
#include "iostream"
#include "exception"
#include "thread"

#include "pthread.h"

void do_something(int num, char c) {
  try {
    // random-number generator (use c as seed to get different sequences
    std::default_random_engine dre(42*c);
    std::uniform_int_distribution<int> id(10, 1000);
    for (int i = 0; i < num; ++i) {
      std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
      std::cout.put(c).flush();
    }
  }
  // make sure no exception leaves the thread and terminate the program
  catch(std::exception &e) {
    std::cerr << "THREAD_EXCEPTION (thread "
	      << std::this_thread::get_id() << "): " << e.what() << std::endl;
  }
  catch(...) {
    std::cerr << "THREAD_EXCEPTION (thread "
	      << std::this_thread::get_id() << ")" << std::endl;
  }
}

int main() {
  try {
    std::thread t1(do_something, 5, '.');  // print five dots in separate thread
    std::cout << "- start fg thread " << t1.get_id() << std::endl;

    // print other characters in other background threads
    for (int i = 0; i < 5; ++i) {
      std::thread t(do_something, 10, 'a'+i);  // print 10 chars in separate thread
      std::cout << "- detach started bg thread " << t.get_id() << std::endl;
      t.detach();  // detach thread into the background
    }
    
    std::cin.get();  // wait for any input (return)
    std::cout << "- join fg thread " << t1.get_id() << std::endl;
    t1.join();
  } catch(const std::exception &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  pthread_exit(NULL);
  // return 0;
}
