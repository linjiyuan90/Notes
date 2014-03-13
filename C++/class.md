* delegation
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
* assigment
	```C++
		vt.back() = 0; // the back() is assignable, it returns reference?
	```