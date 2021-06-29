# Heap Trees

--------------------

This CPP file has both codes for min_heap and max_heap with members for creating, inserting and other basic operations that are done on heaps. The description of its members are shown below.

## Creating HEAP Objects

The below line creates 2 heap objects but it won't initialize a them(i.e Heap will have root value as NULL with no data in it).

Specify type of data in node with template parameter

Template parameter can be any datatypes that can be compared with <,> operators. Ex: int, float, long, short, char, float, double ...

For `int` datatype use

```cpp
max_heap<int> t1, t2; //creates 2 max-heaps t1,t2
min_heap<int> t3, t4; //creates 2 min-heaps t3,t4
```

## Initializing a HEAP

It will create a root node and with the data you passed in as function parameter. The below line will create a root node and initialize its value to 10. This function is same for min and max heaps.

```cpp
t1.create(10); //creates a max-heap with root node with value 10 in it
t3.create(10); //creates a min-heap with root node with value 10 in it
```

## Inserting Elements to HEAP

For inserting an element use.

```cpp
t1.insert(100); //inserts 100 to max-heap and heapifies it
t3.insert(100); //inserts 100 to min-heap and heapifies it
```

For inserting multiple elements we can pass a list to insert function. This will insert the elements in given order

```cpp
vector<int> k = {100,20,30,66,5,200};
t1.insert(k); //inserts elements from list into max-heap
t3.insert(k); //inserts elements from list into min-heap
```

## Deleting Elements from HEAP

For deleting single element use.

```cpp
t1.deleten(100); //deletes element 100 from max-heap
t3.deleten(100); //deletes element 100 from min-heap
```

For deleting multiple elements we can pass a list to deleten function. This will delete all the elements in given order

```cpp
vector<int> k = {100,20,30,66,5,200};
t1.deleten(k);
```

We can also pass iterators to this function by

```cpp
vector<int> k = {100,20,30,66,5,200};
t1.deleten(k.begin(), k.begin()+3);
```

## Getting min and max elements

For max-heap we have 2 functions get_min() or pop_max(). get_min() function returns the minimum element present in the tree. pop_max() returns maximum element present in the root and deletes that element from the root. They will throw the exception if tree is empty. So its better to surround them with try and catch blocks.

```cpp
try{
        cout<<t1.pop_max()<<" ";
        cout<<t1.get_min()<<" ";
    }
    catch(std::exception& e) {
      std::cout << e.what() << std::endl;
   }
```

For min-heap we have 2 functions get_max() or pop_min(). get_max() function returns the maximum element present in the tree. pop_min() returns minimum element present in the root and deletes that element from the root. They will throw the exception if tree is empty. So its better to surround them with try and catch blocks.

```cpp
try{
        cout<<t3.pop_min()<<" ";
        cout<<t3.get_max()<<" ";
    }
    catch(std::exception& e) {
      std::cout << e.what() << std::endl;
   }
```

## Searching an element

We can search for an element is present or not by using searchnode() method. It will return a pointer to the node if element is present in it. Or else it will throw an exception.

```cpp
try{
        auto t = bst1.searchnode(36);
        cout<<t->data<<" ";
    }
    catch(std::exception& e) {
      std::cout << e.what() << std::endl;
   }
```
