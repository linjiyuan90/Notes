#include "iostream"
#include "mutex"
#include "future"
#include "condition_variable"

bool ready_flag;
std::mutex ready_mutex;
std::condition_variable ready_condvar;

void thread1() {
  // do something thread2 needs as preparation
  std::cout << "<return>" << std::endl;
  std::cin.get();

  // signal that thread1 has prepared a condition
  {
    std::lock_guard<std::mutex> lg(ready_mutex);
    ready_flag = true;
  } // release lock
  ready_condvar.notify_one();
}

void thread2() {
  // wait until thread1 is ready (ready_flag is true)
  {
    std::unique_lock<std::mutex> ul(ready_mutex);
    ready_condvar.wait(ul, [] {return ready_flag;});
  }  // release lock

  // do whatever shall hadppen after thread1 has prepared things
  std::cout << "done" << std::endl;
}

int main() {
  auto f1 = std::async(std::launch::async, thread1);
  auto f2 = std::async(std::launch::async, thread2);
}
