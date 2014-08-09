# numeric
* iota
  store increasing sequence
* inner_product
* partial_sum
* accumulate
	* can be used to concatenate string 
*adjacent_difference 

# algortithm
* adjacent_find, searchs for two adjacent elements that are equal
* unique(beg, end, pred)
  the pred is a equal predicator, not less predicator!
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
* replace, seems better than std::string::replace when replacing one element

# initializer_list
* require same type
# list
* splice,  **move** element(s) from that to the front of some of this's iterator.
```
void list::splice(const_iterator pos, list& source) 
void list::splice(const_iterator pos, list&& source)
// the above two functions need to make sure source is not same as this
void list::splice(const_iterator pos, list& source, const_iterator sourcePos ) 
void list::splice(const_iterator pos, list& source, const_iterator sourceBeg, const_iterator sourceEnd)
//source can be same as this
mylist.splice(list.begin(), mylist, it);
```
* sort, unqiue, merge, remove, remove_if
  since list has no RandomAccessIterator, it provide these methods. Also, these
  methods are faster than *algorithm* because the manipulate only **internal
  pointers** rather than elements.

# forward_list

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
* make_unsigned
* is_array
* remove_const
```
typedef typename remove_const<_Tp>::type value_type;
```
# iterator_traits

```
template<typename IterT>
void doSomething(IterT iter) {
	typename std::iterator_trait<IterT>::value_type tmp(*iter);
}
```

# IO
## stream
* A `stream` is an abstraction that represents a device on which input and
  output operations are performed. A `stream` can basically be represented as a
  source or destination of **`character`** of infinite length.
## hierarchy
![iostream hierarchy](iostream.gif) 
### ios_base
### streambuf
### ios
### class templates
### global stream objects

## manipulator
* header "iomanip"
* manipulators are nothing more than functions passed to the I/O operators(<<,
  >>) as arguments;
* concurrent access to the same stream object may cause data race 
* endl, insert newline and flush
```
std::cout<<std::endl
// =>
operator<<(cout, endl)
// inside it, calls
endl(cout)
```
* boolalpha
```c++
std::cout << std::boolalpha << true << std::endl;
std::cout << std::noboolalpha << true << std::endl;  // unset
```
* ws reads and discards whitespaces
* skipws, noskipws
  leading whitespaces is skipped by default, set the flag `ios::skipws`; if you
  want to read a whitespace to `char`, use `get`, or use `std::noskipws`
* unitbuf, nounitbuf
  unitbuf flush the output buffer after each write operation. (cerr/wcerr, this
  flag is set initially)


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
* bind1st, bind2nd, these two are functions, their type is
```
std::binder1st<std::equal_to<int>> equal_to_10 = std::bind1st(std::equal_to<int>(), 10);
```
* not_equal_to, equal_to, less, greater, less_equal, greater_equal, these are `function objects`
```
std::find_if(vt.begin(), vt.end(), std::bind1st(std::not_equal_to<int>(), x));
```

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

# Exception
* length_error 
* runtime_error
* system_error
* invalid_argument
