# intro
## scenario
* log system

## basic
* make constructor, assignment, destructor private or protected if need to be
  inherited. a static 'instance' variable of the class type initially set to
  null (lazy instantiation) or to a new instance of the class (eager
  instantiation). If using eager instantiation, the variable should be marked
  "final" to enforce its immutability. In lazy instantiation, use **double
  check**.
* a static getter method.
* what about destructor? when to destruct?
** the simplest way is to use *local static variable*:
```
Singleton& Singleton::Instance() {
  static Singleton obj;
  return obj;
}
```
*** but this will have dead reference problem in some situation since the object
    is destroyed automatically but it's still needed.
## summary
* managing a singleton's **lifetime** causes the most implementation headaches.

## notes
* static initalization & dynamic initalization (which the order is not defined!)
* not matter function-static variable or class-static variable, it's initialized
  if it's a compile-time constant at compile-time, or it's initialized at
  runtime (during the first time pass through its definition) if it's an object
  with a constructor. **this local static variable initialization is
  thread-safe**
# singleton template


