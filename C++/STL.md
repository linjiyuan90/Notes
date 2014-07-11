# numeric
* iota
  store increasing sequence
* inner_product
* partial_sum
* accumulate
	* can be used to concatenate string 
*adjacent_difference 

# algortithm
* rotate
* stable_partition
* all_if, any_of, none_of
* find_if, find_if_not
* begin, end
* ref_ptr?
* lower_bound, upper_bound, range, binary_search
* remove, remove_if
   it just `squeeze` and return the new `end`, the tail elements are
   **undefined**. This won't change the size of container.
```
vt.erase(remove_if(vt.begin(), vt.end(), [](int e){ return e % 2 == 0; }, vt.end());
```
* equal(first1, last1, first2[, pred])
* set_union, set_intersection, set_difference, set_symmetric_difference
* merge, inplace_merge

# list
* splice

# type_traits
```c++
template<typename T>
void meow(T t) {
  // need typename since it's a dependent type
  typedef typename std::make_unsigned<T>::type U;
  U u = static_cast<U>(t);
  std::cout << u << std::endl;
}
// but this won't compile since template argument deduction won't work for
double colons
void meow(typename make_unsigned<T>::type t)
void meow(T t, std::function<void(T)> f);
meow(123, [](int x) {});  // this won't work
std::function<void(int)> fxn = [](int x) {};
meow(123, fxn);  // this works
```
* maybe type_traits implementation
```
template<typename T>
struct Identity {
	typedef T type;
};
template<typename T>
void func(T a, typename Identity<T>::type b) {
}
```
* iterator_traits
* make_unsigned
* is_array

# IO
* `std::cout << std::boolalpha;`
* endl, **manipulator**, insert newline and flush
	* manipulators are nothing more than functions passed to the I/O operators
	as arguments 
```
std::cout<<std::endl
// =>
operator<<(cout, endl)
// inside it, calls
endl(cout)
```
  
# string
* to_string
*  stoi, stol, stoll, stoul, stoull, stof, stod, stold


# iterator
* back_inserter
```std::copy(bar.begin(), bar.end(), std::back_inserter(foo));```
	* requires `push_back`, don't work for `set`, but `inserter` works 
* ostream_iterator
```std::copy(vt.begin(), vt.end(), std::ostream_iterator<int>(std::cout, ", "))```
* inserter, insert_iterator
```
std::copy(src.begin(), src.end(), std::inserter(vt, vt.end()));
std::insert_iterator<std::set<int>>(vt, vt.end());
```


# functional
* hash


# typeinfo
* `typeid` return `type_info` class, which can be used to detect runtime type of
  pointer/reference point to.
```
Father a = Father(), b = Son();  // not works!
assert(typeid(a).name() == typeid(b).name());
const Father& a = Father(), & b = Son();
assert(typeid(a).name() != typeid(b).name());
// pointer also works
```
