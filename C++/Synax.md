
# dereferencing

# copy constructor, copy assignment
* if a `new` object is being defined, `copy constructor` is called, otherwise `copy assignment` is called.
```C++
Test a;
Test b = a;	// copy constructor!!
void gao(Test a);
gao(a);  // copy constructor!!
```

# const
* if `const` appears to the left of asterisk, what's pointed is const
* if `const` appears to the right of asterisk, the pointer itself is const

```C++
const char *p = sth;  // const data
char const *p = sth;  // note, still const data
char * const p = sth; // const pointer
const char * const p = sth; // const data, const pointer
```
* declaring an `iterator` *const* is like declaring a pointer const (eg, T *
  onst ptr); Use `const_iterator` if you don't want the data to be modified

# reference
* Args&&

# emplace
what's emplace? in-place?

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

## auto_ptr

# template
## typename
