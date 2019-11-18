# 05 STL BENCHMARKS

This is a starter project that should be used to realize the STL performance analysis assignment.

Below steps should guide you gently through whole project. 

Make sure that you understand given point before stepping to next one.

1. Implement missing operators and hash functions

    There are three types [Small](include/Small.h) (size 1B), [Medium](include/Medium.h) (size 1KB) and [Large](include/Large.h) (size 1MB). 

    All three types have some boilerplate code added but implementations of less-than operator, equality operator and hash function are missing.
    
    Your task is to add missing code.

    Report content hints:

    1. How to define correct less-than operator? What should it do for N-dimensional data such as our table?
    2. What is the optimal implementation for equality operator for continuous block of data?
    3. What is the purpose of hash function? What are its mathematical properties?
    4. Describe/justify your implementation.

2. Add unit test for operators and hash functions

    Tests should be added at the end of [SmallTest](test/src/SmallTest.cpp), [MediumTest](test/src/MediumTest.cpp) and [LargeTest](test/src/LargeTest.cpp). Existing test code should not be modified.

    Report content hints:
    
    1. How did you test correctness of operator <, == and hash function?
    2. Should we initialize tested objects (Small/Medium/Large) with random data? Or should we initialize them manually with known data?   
    
3. Create benchmarks for operators and hash functions

    Add your benchmarks inside [SmallBench](bench/src/SmallBench.cpp), 
    [MediumBench](bench/src/MediumBench.cpp) and [LargeBench](bench/src/LargeBench.cpp). 
    
    Those benchmark should measure how long it takes to perform single operation (e.g.: comparison _a < b_).
    This result will be very important in later steps while interpreting STL benchmarks results.

    Report content hints:
    
    1. Describe benchmark structure for simple call tests.
    2. Are there any consequences for sequential containers when our implementation is slow?
    3. What is the impact of slow operator less-than implementation on sorted associative containers? 
    4. What is the impact of slow equality operator / hash function on unordered associative containers?
    5. Describe your benchmark results.
    6. Should we initialize objects (Small/Medium/Large) with random data? Why? Why not?
    
4. Create benchmarks for assigned containers/methods using [Small](include/Small.h) type and _Debug_ build

    There will be three randomly assigned STL containers. 
    Each container has a list of methods that needs to be evaluated (list below).
    
    First step is to implement and run benchmarks in Debug mode. 
    This corresponds to _-O0_ flag set in compiler arguments list. 
    By doing this will simplify our task - there will be no cede mysteriously deleted by optimizer.

    Report content hints:
    
    1. Describe structure of benchmark that measures computational complexity (Big O)
    2. Plot benchmarks results on graphs with your complexity result
       
        X axis - initial number of elements in collection (N)
       
        Y axis - given operation time
       
    3. Did you get the same complexity as e.g. on [cppreference.com](http://en.cppreference.com/w/cpp/container). If not why are they different?
    4. How can we write benchmarks for methods that e.g.: add or remove elements from collection? Describe Pause/Resume timing method. 
       Describe baseline method. How did you implement those benchmarks?
       
5. Use appropriate escape functions to prevent optimization and run benchmarks in _Release_ build
    
    In this step you should rerun benchmarks in Release mode (_-O2_ or _-O3_ flag) after applying optimizer escape functions.
    You can use _DoNotOptimze(...)_ and _ClobberMemory()_ helpers provided by framework.

    Report content hints:
    
    1. Why does the compiler optimizer break our benchmark code?
    2. What do the _DoNotOptimze(...)_ and _ClobberMemory()_ helpers do?
    3. Plot benchmarks results for both Debug and Release mode? Did you see any changes in times/complexity?
    
6. Repeat steps 5 and 6 for [Medium](include/Medium.h) and [Large](include/Large.h) types

    This step should be quite straightforward because all benchmark code should be already created.
    We should only change the type and benchmark range (otherwise we might run out of memory). 

    Report content hints:
    
    1. Plot benchmarks results for all types Small/Medium/Large and Debug/Release mode on single graph (if possible, 6 lines).
       Did you see any changes in times/complexity?
    2. What is the impact of of bigger size on performance? Can it be explained by operators implementation overhead?  
    
7. Collect results and create a report

    Raw output from tests and benchmarks should be stored into [output](output/) directory.

    Report should be created as [readme](readme.md) file in [Markdown](https://en.wikipedia.org/wiki/Markdown) format.
    It should be placed alongside your project inside code repository. Other documents such as PDF/Word won't be accepted!
        
    Report should follow points 1 to 6 and describe in detail reasons behind selected implementation and obtained results (see each point for some hints).
    You should also describe hardware used to execute benchmarks and add some conclusions at the end.
    
8. Grading and deadline

    There are four points to get (added to activity points).
    
    You have two weeks to submit all changes to your repository.


# Container method list

std::vector
```
    at, operator[], front, back, data,
    empty, size, max_size, reserve, capacity, shrink_to_fit, 
    clear, insert, erase, push_back, pop_back, resize, swap
```
std::deque
```
    at, operator[], front, back,
    empty, size, max_size, shrink_to_fit,
    clear, insert, erase, push_back, pop_back, push_front, pop_front, resize, swap
```
std::list
```
    front, back, empty, size, max_size,
    clear, insert, erase, push_back, pop_back, push_front, pop_front, resize, swap,
    merge, splice, remove, remove_if, reverse, unique, sort
```
std::forward_list
```
    front, empty, max_size,
    clear, insert_after, erase_after, push_front, pop_front, resize, swap
    merge, splice_after, remove, remove_if, reverse, unique, sort
```
std::set
```    
    empty, size, max_size, 
    clear, insert, erase, swap,
    count, find, equal_range, lower_bound, upper_bound
```
std::map
```    
    at, operator[], empty, size, max_size, 
    clear, insert, erase, swap,
    count, find, equal_range, lower_bound, upper_bound
```
std::multiset
```
    empty, size, max_size, 
    clear, insert, erase, swap,
    count, find, equal_range, lower_bound, upper_bound
```    
std::multimap
```
    empty, size, max_size,
    clear, insert, erase, swap, 
    count, find, equal_range, lower_bound, upper_bound
```
std::unordered_set
```    
    empty, size, max_size, 
    clear, insert, erase, swap,
    count, find, equal_range,
    rehash, reserve
```
std::unordered_map
```    
    empty, size, max_size, 
    clear, insert, erase, swap,
    at, operator[], count, find, equal_range,
    rehash, reserve
```
std::unordered_multiset
```
    empty, size, max_size, 
    clear, insert, erase, swap,
    count, find, equal_range,
    rehash, reserve
```        
std::unordered_multimap
```
    empty, size, max_size,
    clear, insert, erase, swap, 
    count, find, equal_range,
    rehash, reserve
```

You can always test more methods if you find it important to prove some point.


# Compilation

## Manual compilation

```bash

mkdir build-debug && cd build-debug
cmake -DCMAKE_BUILD_TYPE=Debug ../
make -j4

mkdir build-release && cd build-release
cmake -DCMAKE_BUILD_TYPE=Release ../
make -j4

```

## Compilation from CLion

```bash
File -> Open... -> [Select directory with CMakeLists.txt]
```

Build profile for optimized build:

```bash
File -> Settings... -> Build, Execution, Deveopment -> CMake -> [Click '+' to add new 'Profile' with 'Build Type' 'Release']
```
