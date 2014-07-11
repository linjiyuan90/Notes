# smart pointer
Three type of memory: static, stack, dynamic memory.
* regular pointer use `new`, `delete`
* smart pointer automatically deletes the object to which it points(`memory`
  header). The new library defines two kinds of smart pointers `shared_ptr`,
  `unique_ptr` and a companion class named `weak_ptr`
  * smart pointer are `templates`, by default holds `nullptr`
  * `if(p)` to test whether it points to an object
  * 
  
## unique_ptr
`std::unique_str` is a smart pointer that retains sole ownership of an object
through a pointer and *destroys* that object when the unique_ptr goes out of
scope. No two unique_ptr instances can manage the same object.
* Use `std::move` if you want to pass the object. Only `non-const` unique_str can
transfer the ownship of the managed object to another unique_ptr.
```c++
std::unique_ptr<Foo> p1(new Foo);
p1 = std::unique_ptr<Foo>(new Foo);  // the above Foo will be released since
it's a smart
std::unique_ptr<Foo> p2(std::move(p1));  // now p2 owns Foo
p1 = std::move(p2);  // ownership returns to p1
```
* `std::unique_str` can holds no object

## shared_ptr
`std::shared_ptr` is also a smart pointer but retains shared ownership of an
object. Several `shared_ptr` objects may own the same object.
`std::make_shared`
* two ptr are same if they contain same object! Not same content
* pass *sink* arguments by value and move into place
```
std::make_shared<T>(std::move(t));
```

## auto_ptr
This is **[deprecated][]** for its risk:
> `auto_ptr` transfers ownership when it's assigned.
```
auto_ptr<int > ap1(new int);
auto_ptr<int> ap2 = ap1; // OK, albeit unsafe
unique_ptr<int> up1(new int);
unique_ptr<int> up2 = up1; // compilation error: private copy ctor in accessible
unique_ptr<int> up2 = std::move(up1); // ok, explicit move
```

[deprecated]: http://www.informit.com/guides/content.aspx?g=cplusplus&seqNum=400  "why auto_ptr had to be deprecated"
