# intro
* `visitable` hierarchy & `visitor` hierarchy
* for virtual funciton selection?
* `v.accept(*this)  // *this will get the type`
* The classic implementation of the Visitor pattern have a major drawback
  because the **type** of visitor methods has to be known in advance.
* visitor can maintain states & context during traversal

# Acylic Visitor v.s. Plain Visitor

# other
* When the standard implementation of visitor pattern is used the method to
  invoke is determined at runtime. `Reflection` is the mechanism used to determine
  the method to be called at compile-time.
* The separation of visitors and visitable is only in one sense: **visitors depend
  of visitable objects while visitable are not dependent of visitors**.
* Part of the dependency problems can be solved by using **reflection** with a
  performance cost. How?


# Visitor & Iterator
* The iterator pattern and visitor pattern has the same benefit, they are used
  to traverse object structures. The main difference is that the iterator is
  intended to be used on collections. Usually collections contain objects of the
  **same type**. The visitor pattern can be used on complex structure such as
  **hierarchical structures or composite structures**. In this case the accept
  method of a complex object should call the accept method of all the child
  objects.
* Another difference is operation performed on the objects: In one case the
  visitor defines the operations that should be performed, while the iterator is
  used by the client to iterate through the objects form a collection and the
  operations are defined by the client itself.
# Application
* reporting module to make statistics

# Reference
[1] http://www.oodesign.com/visitor-pattern.html
