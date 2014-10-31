# numeric
* iota
  store increasing sequence
* inner_product
* partial_sum
* accumulate
	* can be used to concatenate string 
* adjacent_difference

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
* min, max, min_element, max_element, minmax, minmax_element
```
// min/max has an overload version:
min(initializer_list)
// nice!
min({dp[i][j], dp[i][j-1]+1, dp[i-1][j]+1})
```
* generate, generate_n
* equal, mismtach, lexicographical_compare
* copy, copy_backward
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
  pointers** rather than elements. Note, merge will **move** elements!

# forward_list
* implemented as single-linked lists
* `forward_list` objects are thus more efficient than `list` objects, although
  they can only be **iterated forwards**.
  
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
# IO
## stream
* A `stream` is an abstraction that represents a device on which input and
  output operations are performed. A `stream` can basically be represented as a
  source or destination of **`character`** of infinite length.

## hierarchy
![iostream hierarchy](iostream.gif)

## ios_base
## streambuf
## ios
## class templates
## global stream objects
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
## overview
* four types: `iterator`, `const_iterator`, `reverse_iterator`, `const_reverse_iterator`
* `insert` and `erase` of container only support `iterator`
* `iterator` can be implicitly converted to `const_iterator` while the vice is
  not allowed; to get an `iterator` from `const_iterator`, use `advance` and
  `distance`
```
CIter ci;
Iter it = vt.begin();
std::advance(it, std::distance<CIter>(it, cit));  // here it is converted to CIter implicitly
```
* `reverse_iterator` has a `base` member function to get the `iterator`
  value. However, the `base()` is pointed to preceeding elements in revered
  order! So, `rbegin` points `end`, but `rbegin` gets value of `*(end-1)`
```
typedef std::deque<int>::iterator Iter; 
typedef std::deque<int>::reverse_iterator RIter;
RIter ri;
dq.insert(ri.base(), v );  // the insert is ok
dq.erase((++ri).base());  // but erase need to increase ri first!
// -- ri.base() maybe not compiled since the return value base() maybe a const pointer!
```
* another categories: `output iterator`, `input iterator`, `forward iterator`,
  `bidirectional iterator`, `random-access iterator`
** `random-access iterator` can use `vt.begin()[i]`
## auxiliary Iterator functions
* `advance`, `next`, `prev`, `distance`, `iter_swap`
* the reason why using `advance` & `distance` is that some iterators don't have
  `+=`, `+`, `-=`, `-`(such as `std::list`)
* due to the use of iterator traits, `advance` will use `pos += n` if it's an
  random-access iterator and call `++pos` n times for other iterators; for
  random-access iterators, `distance(pos1, pos2)` calles `pos2-pos1`, while
  increment pos1 till pos2 for other iterators. So make sure pos2 is >= pos1.
* `next`, `prev` return a temporary object instead of modifying the original
  iterator
* `iter_swap` is used to swap **value** which iterators refer; the iterator
  don't need to have the same type. It still works for pointer.
## iterator adapter
### reverse iterator
* it's possible to convert a `iterator` to `reverse_iterator`, but noted the
  iterator is moved (move one to left); if the iterator is `begin`, the
  reverse ierator will become `rbegin`
* to convert `reverse_iterator` to `iterator`, call `base`, but noted the
  iterator is moved (move one to right of the reversed iterator)
* `reverse_iterator` is always the **preceeding** of `iterator`
* in fact, `rbegin` refer to `end` and `rend` refer to `begin`; thus `rbegin()`
  is simply: `container::reverse_iterator(end())` and `rend()` is simply:
  `container::reverse_iterator(begin())`
### insert iterator
* operations of insert iterator

| Expression   |        Effect        |
|--------------|:--------------------:|
| \*iterator    | No-op (returns iter) |
| iter = value | inserts value        |
| ++iter       | No-op (returns iter) |
| iter++       | No-op (returns iter) |

* kinds of insert ierator

| Name             |         Class         | Called Function    | Creation             |
|------------------|:---------------------:|--------------------|----------------------|
| Back Inserter    | back_insert_iterator  | push_back(value)   | back_inserter(cont)  |
| Front Inserter   | front_insert_iterator | push_front(value)  | front_iterator(cont) |
| General Inserter | insert_iterator       | insert(pos, value) | inserter(cont, pos)  |

### stream iterator
* ostream_iterator

| Expression                          |                                           Effect                                          |
|-------------------------------------|:-----------------------------------------------------------------------------------------:|
| ostream_iterator<T>(ostream)        | Creates an ostream iterator for ostream                                                   |
| ostream_iterator<T>(ostream, delim) | Creates an ostream iterator for ostream with delim (note that delim has type const char*) |
| *iter                               | No-op (returns iter)                                                                      |
| iter = value                        | writes value to ostream: ostream << value (followed by delim, if set)                     |
| ++iter                              | No-op(returns iter)                                                                       |
| iter++                              | No-op(returns iter)                                                                       |

* istream_iterator

| Expression                   |                                       Effect                                      |
|------------------------------|:---------------------------------------------------------------------------------:|
| istream_iterator<T>()        | Creates an end-of-stream iterator                                                 |
| istream_iterator<T>(istream) | Creates an istream iterator for istream(and might read the first value)           |
| *iter                        | Returns the value, read before (reads first value if not done by the constructor) |
| iter->member                 | Returns a member, if any, of the actual value, read before                        |
| ++iter                       | Reads next value and returns its position                                         |
| iter++                       | Reads next value but returns an iterator for the previous value                   |
| iter1 == iter2               | Tests iter1 and iter2 for equality                                                |
| iter1 != iter2               | Tests iter1 and iter2 for inequality                                              |

** if a format error occurs, the stream is no longer in a good state; call
   `clear()` to make it available; the bad input is still there.

* istreambuf_iterator

## move iterator
* move_iterator<T>
* make_move_iterator()
```
std::list<std::string> s;
std::vector<std::string> v1(s.begin(), s.end());  // copy strings into v1 
std::vector<std::string> v1(std::make_move_iterator(s.begin()),
std::make_move_iterator(s.end()));  // move strings into v1, now s has same number of elements of empty string
```


## iterator_traits
```
template<typename IterT>
void doSomething(IterT iter) {
	typename std::iterator_trait<IterT>::value_type tmp(*iter);
}
```
## other
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
* `istreambuf_iterator` is much faster than `istream_iterator`

# functional
* hash
** There is no specialization for **C strings**. `std::hash<const char*>` produces a
   hash of the value of the pointer (the memory address), it does not examine the
   contents of any character array.
* bind1st, bind2nd, these two are functions, their type is
```
std::binder1st<std::equal_to<int>> equal_to_10 = std::bind1st(std::equal_to<int>(), 10);
```
* not_equal_to, equal_to, less, greater, less_equal, greater_equal, these are `function objects`
```
std::find_if(vt.begin(), vt.end(), std::bind1st(std::not_equal_to<int>(), x));
```
* note `greater` use `operator >`, so user-defined class need to define this as well!

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
# vector
* it's implemented with 3 pointers. One for beg, one for end, one for capacity
  end; the memory between end and capacity end are only `operator new`, not
  construct!
* there is a class template specialization for `vector<bool>`
# bitset
* any, all, none
* set, reset, flip
* bitset(string)
* count, size
* to_string, to_ulong, to_ullong
# cstdlib
* atexit
  `int atexit(void (*func)(void));` the function pointed by *func* is
  automatically called without arguments when the program terminates normally.
  


