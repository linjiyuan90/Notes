
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
* reference to invalid location
```c++
int *ptr;
int &ref = *ptr;
int &fun() {
	int a = 10;
	// once fun returns, the space allocated to it on stack frame
	// will be taken back, so the reference will not be valid
	return a;
}
```

# emplace
what's emplace? in-place?

# template
## typename

# Name Lookup
## Argument Dependent Lookup (ADL)

# Virtual Function
C++ is **static binding**, the method is resolved at compile-time. Specifies
that a non-static member function is *virtual* and supports **dynamic binding**.
The virtual fuction naturally introduces the concept of "virtual destructor".
When virtual function is defined, virtual destructor need to be added, to avoid
calling the wrong destructor.
```c++
class Person {
public:
  virtual void aboutMe() {
    std::cout << "I'm a person" << std::endl;
  }

  virtual ~Person() {
    std::cout << "Deleting person" << std::endl;
  }
};
class Student: public Person {
public:
  void aboutMe() override { // override is optional, virtual is also optional
    std::cout << "I'm a student" << std::endl;
  }
  ~Student() {
    std::cout << "Deleting student" << std::endl;
  }
};
int main() {
  Person *p = new Student();
  p->aboutMe();
  delete p;
  Student *s = new Student();
  s->Person::aboutMe();  //suppressed dynamic binding using qulified name lookup
  delete s;
}
// I'm a student
// Deleting student
// Deleting person
// I'm a person
// Deleting student
// Deleting person
```

The base class's virtual function in derived class is also virtual.
*Final overrider* is the actual executed function when a virtual function call
 is made.

# inline
* recursive function can't be marked as inline since the recursive level is not
  known (?)
* class member function will be dealt as inline function(?)


# pointer
```
Foo *array[10]; // array of 10 Foo pointers
Foo (*array)[10]; // pointer to array of 10 Foos
```

# TODO
* what's lvalue, rvalue
* explicit
  Use explicit to prevent implicit conversions.
  http://stackoverflow.com/a/121216/3117578

