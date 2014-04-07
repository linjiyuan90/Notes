
## vector
* assign
* emplace_back, emplace
```c++
std::vector<std::pair<int, int>> vt;
vt.emplace_back(1, 2); // no need to make_pair, nice!
```
## algorithm
* move

## string conversion
* std::stoi, std::stod, std::stol
* std::to_string

## compare
* greater
```c++
// min_heap
std::priority_queue<T, std::vector<T>, std::greater<T>> pq;
std::sort(a.begin(), a.end(), std::greater<int>());
```
* less
* minmax

## numeric
* std::numeric_limits<double>::epsilon()


## io
* seekg
* std::ios::beg
