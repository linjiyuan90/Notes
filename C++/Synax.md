
* dereferencing

* copy constructor, copy assignment
	* if a `new` object is being defined, `copy constructor` is called, otherwise `copy assignment` is called.
		
	```C++
		Test a;
		Test b = a;	// copy constructor!!
		void gao(Test a);
		gao(a);  // copy constructor!!
	```
	
* const
	* if `const` appears to the left of asterisk, what's pointed is const
	* if `const` appears to the right of asterisk, the pointer itself is const
	
	```C++
	const char *p = sth;  // const data
	char const *p = sth;  // note, still const data
	char * const p = sth; // const pointer
	const char * const p = sth; // const data, const pointer
	```
	* declaring an `iterator` *const* is like declaring a pointer const (eg, T * const ptr); Use `const_iterator` if you don't want the data to be modified