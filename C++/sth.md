# inline function
* inline function are a lot like a **placeholder**. The compiler will insert the complete body of hte function in every place the function is called
* inline expansion eliminate the time overhead (excess time) when a function is called. Typically used for functions that execute frequently.

# Friend

# Overloaded Operator
* IO Operator must be **nonmember functions**; If they were, then the left-hand operand would have to be an object of cass type; IO operators usually need to read or write the **nonpublic** data members, as a sequence, IO operators usually must be declared as **friends**; input operator must deal with the possibility that tht input might fail.
```C++
std::istream operator>>(std::istream &is, Sales_data &item) {
  double price;
  is >> item.bookNo >> item.units_sole >> price;
  if (is) { // check that the inputs succeeded
    item.revenue = item.units_sold * price;
  } else {
    item = Sales_data();
  }
  return is;
}
```
* if a class has a **subscript operator**, it usually should define two versions: 
	* one that returns a plain reference
	* the other is a *const* member and returns a reference to *const*
```C++
class StrVec{
public:
  std::string &operator[] (std::size_t n) {
    return elements[n];
  }
  const std::string &operator[] (std::size_t n)  const {
    return elements[n];
  }
private:
	std::string *elements;
};
const StrVec cvec = svec;
cvec[0] = "zip"; // error
```

# Optimization
* Accesing dp[mask][k] is much faster dp[k][mask] when iterating mask, then k
  due to cache (I guess).  So remember, define the multidimensional array with
  same order as for.
* local variable is faster than accessing array elements


# lvalue & rvalue, lvalue reference & rvalue reference
* rvalue is temporary object


# copy-on-write
* clang seems don't have COW on string

# Resource
* many(most?) use local pointers are not exception safe
* RAII(Resource Aquisition is Initialization), release resource in destructor
* std::unique_ptr zero cost (time and space)
* but they are still pointers, "any pointer is a potential race condition - even
  in a single threaded program"

# Memory
* memory access is relative slow
* unpredictable memory access gives many more `cache misses`
* don't store data unnecessarily
* access memory in a predictable manner
* keep data compact


# something
* zero-overhead abstraction
