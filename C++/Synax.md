


# auto & decltype
* use `auto` when we have a suitable initializer
* when we have a type **deduced** without defining an initialized type, use
  `decltype`
```
template<class T, class  U>
auto operator+(const Matrix<T>& a, const Matrix<U>& b) -> Matrix<decltype(T{}+U{})>;
```
# initialization
* initialization using `{}`, *list initialization*, does not alow **narrowing**
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

# constexpr
* The basic idea of constant expression is to allow certain computations to take
  place at compile time.
* A `constexpr` function can have only **a single line of executable code(single
  return statement)**, but it may contain `typedefes`, using declarations and
  directives and static_asserts.
* it can only call other `constexpr` functions
* it can reference only `constexpr` global variables
* constexpr function can be recursive, for example "factorial". inline function
  can't be recursive.

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
## template argument deduction
```
template<typename T>
void meow(T t) {
	std::cout << t << std::endl;
}
meow(123);  // argument deduction
meow<int>(123);  // no need to add <int>, don't try to help the compiler
const int n = 123;
meow(n); // meow still treate it as int, not const int!!!
// however, if the paramter is T&, passing const int argument  will be const T&
```
* 

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
* class member function will by default mark as inline function(?)
* inline is a request, not a command. The compiler may reject to inline the
  function.
* if there is a pointer to a inline function, in fact, the compiler will
  generate a "outline" function for the function pointer.

# pointer
```
Foo *array[10]; // array of 10 Foo pointers
Foo (*array)[10]; // pointer to array of 10 Foos
```

# explicit
* Use `explicit` to prevent implicit conversions.
  http://stackoverflow.com/a/121216/3117578

# enumeration
* the `class` after the `enum` specifies that an enumeration is **strongly typed**
and its enumerators are **scoped**.
* after remove `class`, this becomes a less strongly typed "plain" `enum`
```C++
enum class Color {RED, GREEN, YELLOW, BLUE};
int a = Color::RED; // Error: Color::RED is not an int
Color c = 2; // Error: 2 is not a Color
enum Color {RED, GREEN, YELLOW, BLUE};
enum {A, B, C, D};
int a = A;
int c = GREEEN;
```
* by default, an `enum class` has only assignment, initialization,  and comparisions
* sth, seems nice, but what's the usage?
```
enum : uint32_t
{
  max_uint32_t = static_cast<uint32_t>(-1)
};
```


# lvalue & rvalue, and reference, move
* **if it has a name(thus can take the address), it's lvalue(can be rvalue reference), otherwise it's
  rvalue**, for example, `x, *p, a[i]` and `1234, x+y` 
* **lvalue and rvalue is independent of its type!**
```
void f(A&& x) {
  // x is a lvalue but with type rvalue reference
  // x has a name, and can access its address!
  g(std::move(x))  // need to use move! Otherwise, it'll be copied to g
}
```
* An lvalue is an expression that refers to a memory location and allows us to
  take the address of that memory location via the `&` operator. An rvalue is an
  expression that is not an lvalue
* `lvalue` is an expression whose address can be taken, a locator value.You can
  make assignment to lvalue. You can also have lvalue that aren't variables.
```
int a;
a = 1;
int& getRef() {
  return a;
}
getRef() = 4;
```
* An expression is an `rvalue` if it results in a **temporary object**.
* `lvalue reference`, holding on to a ** const reference** to a temporary object
  ensures that the temporary object isn't immediately destructed. So, you cannot
  use a "mutable" reference because, if you did, you'd be able to modify some
  object that is about to disappear.
```
string getName();
const string& name = getName();
```
* `rvalue reference` will let you bind a mutable reference to an `rvalue`, not
  an `lvalue`. Also, you can use const rvalue reference, which is rarely.
* both `lvalue` and `rvalue` `reference` are **lvalue expressions**. The
  difference is that an lvalue reference must be const to hold a reference to an
  rvalue, whereas an rvalue reference can always hold a reference to an rvalue.
* lvalue reference can bind: lvalues & rvalues; while rvalue reference can only
  bind rvalues
* curx:
  * Rvalue reference => type&&
  * type && \=> Rvalue reference
## universal reference type&&
* if a variable or parameter has **declared type** `T&&` for some **deduced
  type** `T`, it's universial reference
* can bind lvalue, rvalue, const, non-const, volatiles, non-volatiles, etc., everything
* possible in four contexts
  * function template parameters
  ```
  template<typename T>
  void f(T&& param);            // URef
  template<typename T>
  void f(const T&& param);  // RRef
  template<typename T>
  void f(std::vector<T>&& param);  // RRef
  ```
  Not all `T&&` in templates are URefs when there is no **type reduction**!!!
  ```
  template<class T, class Allocator=allocator<T>>
  class vector {
  public:
  ...
    void push_back(T& x);    // LRef (copy lvalues)
    void push_back(T&& x);  // RRef! T comes from vector<T>, not arg passed to
  push_back
    template<class... Args>
	void emplace_back(Args&&... args);  // URef! Args deduced
  };
  ```
  * auto declarations
  ```auto&& var = ...
  std::vector<int> v;
  auto &&a = 10;  // 10 is temporary, so a is rvalue reference
  auto &&b = v[5];  // v[5] is int&, it's lvalue, so b is lvalue reference
  ```
  * typedef declarations
  * decltype expressions
	* still a type deduction
* universal reference is used in **perfect forwarding**
* universal reference is handling everything, so do not overload it
### reference collapsing rules
* A& & => A&
* A& && => A&
* A&& & => A&
* A&& && => A&&
```
// except template
Widget w;
typedef Widget&& RRtoW;
RRtoW& v1 = w;  // Widget&
const RRtoW& v2 = std::move(w); // const Widget&
RRtoW&& v3 = std::move(w); // Wideget&&
template<typename T>
void f(T&& param);
Widget w;
Widget& lrw = w;
Widget&& rrw = std::move(w);
f(lrw);  // f<Widget&>(Widget&)
f(rrw);  // f<Widget&>(Widget&)
f(std::move(rrw));  // f<Widge>(Widget&&)
// decltype works different
// decltype(expr) yields T& or T, and ref-collapsing applies!!!!!
// decltype(id) => id's declared type
// decltype(non-id lvalue expr) => expr's type; LRef(T&)
// decltype(non-id rvalue expr) => expr's type; non-ref(T)
// ======= still don't understand =========
Widget w;
decltype(w)&& r1 = std::move(w); // r1's type is Widget&&
decltype((w))&& r2 = std::move(w); // r2' type is Widget&
decltype(w)&& v = std::move(w);  // URef, not RRef, since there is a type reduction
```
* type deduction and reference collapsing applies to templates, auto, typedef,
  and decltype
* http://channel9.msdn.com/Shows/Going+Deep/Cpp-and-Beyond-2012-Scott-Meyers-Universal-References-in-Cpp11
	
## move
* **move does not move! It cast to rvalue**
* `move` do no more than exchange pointers and resource handles between two objects
* `move` does not, in and of itself, move anything; it just turns an `lvalue`
  into an `rvalue`, so that you can invoke the `move constructor`.
* `move` is just a `static_cast` to an `rvalue reference`
* in `move constructor`, remember to set the moved object's member pointer to
  `NULL`, since after temporary object goes out of scope, its desturctor will
  run, which will free the pointer.
* move doesn't change an object's `const`, don't declare obejcts `const` if you
  want to move from them.
```
void process(const string s) {
//...
global = std::move(s); // doesn't move, it's copied!
}
class string {
string& operator=(const string&)  // it calls this!
string& operator=(string&& )
}
```
* can move a `const` object, that compile. But if you move a const object to a
function, and the function modify it, you'll get compile error. In fact, if you
want to move something, you should not make it `const` since you really want to
modify it
## argument & return value
* if constructing a object from return value of a function, no new object will
be created, it'll reuse the temporary object! So if a function is to generate
object, no need to defined it as `rvalue reference`
* same as passing temporary object to function argument
```c++
T gao() {
  T a;
  std::cout << &a << std::endl;
  return a;
}
T a = gao();  // No object is copied/constructed
std::cout << &a << std::endl;
```
## reference
* http://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html
* http://thbecker.net/articles/rvalue_references/section_01.html
# forward
* The need for this function stems from the fact that **all named values** (such as
  function parameters) **always evaluate as lvalues** (even those declared as
  rvalue references), and this poses difficulties in preserving potential move
  semantics on template functions that forward arguments to other functions  
* `cast` param to `rvalue` iff `rvalue` was passed in, **a conditoinal cast to rvalue**
* **used in universal reference**, often in a template function

# cast
## const_cast 
## static_cast
* `static_cast` (and an `old style cast`) will perform the correct **address
  manipulation**; while `reinterpret_cast` will typically just pretend the base
  class pointer is a derived class pointer without changing its value.
## dynamic_cast
* a `dynamic_cast`is used typically to perform a **safe down cast** from a
  pointer/reference to base to derived class or sibling base class
* dynamic_cast a wrong reference will throw `bad_cast` exception while cast
  pointer won't have exception but return nullptr.
* `dynamic_case` used as a down cast may be performed only on `polymorphic` type
  (that's, the type of the expression being cast has to be a pointer to a class
  type with `virtual function`); and the cast actually performs a **runtime
  check** to see that the cast is correct.
* `static_cast` typically has no or minimal runtime cost whereas using
  `dynamic_cast` implies significant runtime overhead.
* If you want to perform a cast on a type where **inheritance** is not involved,
  you probably want a `static_cast`. To cast constness away, you always want a
  `const_cast`
## reinterpret_cast
* The most common use of reinterpret_cast is to cast between **function pointer
  types**
  
# noexcept
* allow compiler to do more optimizatoin options
  * `move_if_no_except`
  * when push_back to vector cause reallocating memory, need to assign elements
    to new memory. Use copy is safe, because even exception happens, the old
    memory is still valid. But when using move, if exception happens , there is no
    way to recover.
## conditionally nonexcept 


# Name Lookup
* look up a function (maybe) from
	* class member 
    * free function
    * namespace
    * argument dependent lookup 
* name lookup order is
  * template arg deduction
  * overload resolution
  * access control
  * virtual function (at runtime)

## argument dependent lookup (ADL)
* when you have a function without qualifier, like `operator <<`; so sometimes,
  you don't need to specify the qualifier.
  ```
  std::vector<int> vt;
  begin(vt);
  sort(vt.begin(), vt.end());
  ```
* need to be in same namespace

## others
* using-directive
  `using namespace std;`
* using-declaration
  `using std::vector;  // no need to add <T>, since it's just using the name,
  not the type`
  `using` function is also ok, while `typedef` can't


# mutable
* disables bitwise `const` checking for "hidden" data members
* common for caches
```c++
class Widget {
 public:
	int magicValue() const {  // note the const
	  if (cacheValid) return cachedValue;
	  else {
	    cachedValue = expensiveComputation(); // write data mem
		cacheValid = true;
		return cachedValue;
	  }
	}
 private:
  mutable int cacheValue;
  mutable bool cacheValid;
};
```
* has concurrency problem, **data race** since several threads may write the
  data simutanously
* add mutex
* or use atomic data, which is automatically synchronized


# using & typedef
* what's the difference? No?
```
template <typename T> using my_type = whatever<T>;
using Foo::Bar;
```



# operator
* prefix, postfix

# exception
```
try {}
catch(...) {current_exception()};
```

# Function Object & Function Pointers
## function object
* function object overload `function call operator`
* function object can have data members(to store states), virtual operator () to create a
 `function object hierarchy`
* STL funciton object (Not general function object) has no data members, no
  virtual functions, and no explicitly declared constructors or destructor, and
  the implementation of operator () is **inline**; while function pointer will
  not be inlined; STL function object avoid to have data members since STL
  implementation may make serveral copies of a function object and may assume
  that all the copies are identical.
* A `predicate` is an operation that asks a true/false question about a single
  object; A `comparator` can be viewed as a kind of binary predicate.
* When a function object is used as a callback, that's an instance of the
  Command pattern.
## function pointer
* it's legal to point to an **inline** function; however, calling an inline
  function through a function pointer will not result in an inline function
  call, because the compiler will not be able, in general, to determine at
  compile time precisely what function will be called; while function object works
  since its type is clear;
* one traditional use of function pointers is to implement `callbacks`
```
void (*fp)(int);  // ptr to function
fp = 0;  // Ok, set ot null
extern void f(int);
fp = f;
fp = &f;  // Ok, take addres explicitly
// the standard typename new_hanlder is a typedef:
typedef void (*new_handler)();
```

# new & delete
## new
|                         |Description|
|:------------|:-------------------------------------------------------------------------------------------|
| new operator    | create an obeject on the heap; both **allocate memory** and calls a **constructor** for the object                          |
| operator new    | like malloc but you can customise this function; the new operator will use your own version of operator new function, then all the new operator will call this operator new function.        |
| placement new | **special version of operator new**; construct an object in memory you've already got a pointer to. `new (buffer) YourClass();` |
## delete
* there are delete operator, operator delete doing the opposite things
## array
* new [], delete[] and their corresponding operator new[] and operator delete[] which can be overloaded
## other
* heap memory for STL containers is managed by the containers' allocation
  objects, not by *new* and *delete* directly.
* exception `bad_alloc` or based on it is thrown using `new` while null pointer
  is returned when using `malloc`
* in deed, exception is thrown when the **new-handler** is not installed; if the
  new-handler is installed, the `operator new` will call this handler repeatedly
  until it can find enough memory
  ```
  namespace std{
    typedef void (*new_handler)();
	new_handler set_new_handler(new_handler p) throw();
	// pass null pointer to deinstall the handler
  }
  ```
* operator new has a serveral overloaded versions; user can overload
  class-specific operator new.
  [operator new](http://en.cppreference.com/w/cpp/memory/new/operator_new)
