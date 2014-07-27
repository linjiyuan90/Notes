
# delegation
  to overload constructor
	```C++
	class Foo {
	public:
	  Foo(): Foo(0) {}
	  Foo(int x): x(x) {}
	private:
	  int x;
	};
	```
# assigment
	```C++
		vt.back() = 0; // the back() is assignable, it returns reference?
	```

# copy-control
## copy constructor, copy-assignment operator, desctructor
* if there is not explicit such method, the compiler will synthesize them as
  `inline functions`; Specifying them with `= default` if we don't won't them to be
  an inline function , `= delete` if you don't won't these functions;
  ```C++
  class Test {
  public:
	  Test() = default;
	  Test(const Test &that) = default;  // copy constructor
	  Test& operator=(const Test &that) = delete // copy-assignment operator
	  ~Test() = default;
  };
  ```
* Once a class needs  a destructor, it almost surely needs a copy constructor
and copy-assignment operator; 
## move constructor, move-assignment operator
* consider move to itself

## copy assignment
* this can be implement by move assignment, nice
```
class object_t {
 public:
  object_t& operator = (const object_t& that) {
    object_t tmp(that);
	*this = std::move(that);
	return *this;
  }
  object_t& operator = (object&&) noexcept = default;
};
```

# virtual function
* virtual function allows the programmer to declare functions in a base class
  that can be redefined in each derieved class. The compiler and linker will
  guarantee the correct correspondence between objects and the functions applied
  to them.
* if a function is not marked `virtual`, the actual function called is not
  related to the actual object.
* a virtual function **must be defined** for the class in which it's first
  declared(unless it's declared to be a pure virtual fucntion)
* it's possible to override a `virtual function` from a base with a more derived
  `return type`(like return Derived* rather than Base*, this relaxation applies
  only to return types that are **pointers or references**, and not to "smart
  pointers"); But funciton name and set of argument types, and `const` qualifier
  must be same
* a constructor cannot be `virtual`; create a `virtual Base* clone()` function
  to fulfill the task of "virtual constructors". A member function that provides
  the ability to clone an object is traditionally called a "**virtual constructor**"
  in C++.
* An `abstract class` (class which has pure virtual function) doesn't need a
  constructor
* calling a function using the scope resolution operator, `::`, ensures that the
  `virtual` mechanism is not used.
* A class with a virtual function should have a `virtual destructor`!
* **virtual base classes**, used in **virtual inheritance**, is a way of
  **preventing multiple "instances"** of a given claass apperaing in an
  inheritance hierarchy when using multiple inheritance.
```
class A {}; class
B : public virtual A {public: void Foo() {}};
class C : public virtual A {};
class D : public B, public C {};
D d;
d.Foo(); // no longer ambiguous
```
  
## virtual function table (vtbl)
* each class with virtual functions has its own vtbl identifying its virtual
  functions
* the functions in the vtbl allow the object to be used correctly even when the
  **size of the object** and layout of its data are unknown to the caller.

# static
*  static members are only declared in class declaration, not defined. They must
   be explicitly defined outside the class using scope resolution operator.
   

# const member function
* make it thread safe by:

# inheritance
*  using a class as a base class is equivalent to `defining` an (unnamed) object
   of that class. Consequently, a class must be `defined` in order to be used as a
   `base`
*  it's better to **inherit constructors** by `using Base::Base`
## access specifier
* access specifier **limits** the most accessible level for the members inherited
  from the base class: The members with a more accessible level are inherited
  with this level instead, while members with an equal or more restricted access
  level keep their restrictive level in the derived class.
* `private` and `protected` inheritance do not imply the same kind of reuse as
  `public` inheritance. With `private` and `proteceted`, we cannot say that the
  derived class is a "kind of" the base class, since the interface the base
  class guarantees (i.e., its `public` parts) becomes `private` or `protected`,
  respectively. Thus, `private` and `protected` inheritance respresent a
  different way of `reusing` a class.
* if the access specifier for a base class is left out, the base defaults to a
  private base for a class and a public base for a struct
* `friend` class/function can access `private`, `protected` members as well
* `protected` can be used to provide functions designed to be used in derived
  class but not by the general user(like uncheck access function); A derived
  class can access a base class's protected members only for objects of its own
  type, not other object with same base class. Declaring **data members**
  `protected` is usally a design error. 

## polymorphism
* we can often write better code using `polymorphism`, i.e., using `public
  inheritance`, `base class pointers(or reference)`, and `virtual` functions.
* polymorphism implemented by `virutal` is `runtime/dynamic polymorphism`; which
  using `template` is call `compile-time/static polymorphsim`

## cast
