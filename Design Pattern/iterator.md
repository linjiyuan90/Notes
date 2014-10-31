# intro
## hints
* add a classIter, and in the origin class, make this class **friend**.

# examples
* `std::iterator` defines a iterator with several members:
```
template<class Category, class T, class Distance = ptrdiff_t,
         class Pointer = T*, class Reference = T&>
struct iterator
{
    typedef T         value_type;
    typedef Distance  difference_type;
    typedef Pointer   pointer;
    typedef Reference reference;
    typedef Category  iterator_category;
};
```
** iterator_category is not a value, is a type. Some class write like:
```typedef bidirectional_iterator_tag       iterator_category;``
** five types of iterator category, `input_iterator_tag`, `output_iterator_tag`,
`forward_iterator_tag`, `bidirectional_iterator_tag`, `random_access_iterator_tag`

** iterator_traits
* inherite `std::iterator` to get information for free.

## detail
* begin, end
** end return NULL or pointer


# multithread problem
* one thread is traversing while the other is modifying the collection
