# sizeof
* returns size in bytes of the object representation of type.
* depending on the computer architecture, a *byte* may consist of 8 or more bits, **CHAR_BIT**
* sizeof(char), sizeof(signed cahr), sizeof(unsigend char) always return 1
* when applied to a class type, the result is the size of an object of that class plus any additional padding
* when applied to an empty class type, always returns 1


* sizeof(int) depends on compiler, not on machine WORD_BIT(Generally, compiler will consider WORD_BIT)
* sizeof(int *) depends on pointer size
* sizeof("ab")  returns the length of the const string + 1, that's 3 in this case
* sizeof(int[10]) returns 


# for
* use `const auto&` for `for-each` and `auto &` for `transform`
```
for (const auto& e : r) f(e);
for (auot &e : r) e = f(e);
```

# lambda
* use lambdas for predicates, comparisons, and projections, buk keep them short
* use function objects with template member function to simulate polymorphic lambda

# Some
* COW is illegal in C++11


# Prefer auto to Explicit Type Declaritions
* avoid accidental temporary creation
```
std::map<std::string, int> m;  // holds objects of type std::pari<const std::string, int>
...
for (const std::pair<std::string, int>& p : m) ...
// creates temp on each iteration => std::string is copied
for (const auto& p : m)  // no temps created, but how?
```
* most efficient way to store `function obejcts`, since by using `auto`, closure
  **not** on heap, closure call typically **inlined**
	  * applies also to function objects from `std::bind`
## problems 
* auto + {expr} => std::initializer_list
```
auto a (5); // int
auto b {5};  // std::initializer_list<int>
auto x = { expr };  // '=' is optional
decltype(x) != decltype(expr)
decltype(x) ≈ sd::initialier_list<decltype(expr)>
```
* hidden proxy types "invisibly" act like other types
```
std::vector<bool> vb;
bool b1 = vb[5];  // b1 is bool 
auto b2 = vb[5];  // b2 is std::vector<bool>::reference!
assert(&b1 != &b2);  // error! can't compare bool* and std::vector<bool>::reference*
```
```
```
## guidelines
* auto a tool, not an obligation
* if explicit types clear, use it
# access control
* avoid copying
```
LookupKey(const LookupKey&);
void operator=(const LookupKey&);  // void return type is ok
```
