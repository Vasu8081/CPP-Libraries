# Binary Search Tree

--------------------

This CPP file has class binary_search_tree with members for creating, inserting and other basic operations that are done on BST's. The description of its members are shown below.

## Creating BST Objects

The below line creates 2 tree objects but it won't initialize a tree.

Specify type of data in node with template parameter

Template parameter can be any datatypes that can be compared with <,> operators. Ex: int, float, long, short, char, float, double ...

For `int` datatype use

```cpp
binary_search_tree<int> t1, t2;
```

## Initializing BST

It will create a root node and with the data you passed in as function parameter. The below line will create a root node and initialize its value to 10.

```cpp
t1.create(10);
```

## Inserting Elements to BST

For inserting single element use.

```cpp
t1.insert(100);
```

For inserting multiple elements we can pass a list to insert function. This will insert the elements in given order

```cpp
vector<int> k = {100,20,30,66,5,200};
t1.insert(k);
```

## Deleting Elements from BST

For deleting single element use.

```cpp
t1.deleten(100);
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

## Traversals or Printing Elements

We can use inorder, preorder and postorder traversals. we have to pass a list to it. it will do traversal and pushes back the elements into that list. We can use that list to print elements.

```cpp
vector<int> li;
t1.inorder_traversal(t1.root,li);
for(auto it = li.begin();it!=li.end();it++){
cout<<*it<<" ";
}
```

```cpp
vector<int> li;
t1.preorder_traversal(t1.root,li);
for(auto it = li.begin();it!=li.end();it++){
cout<<*it<<" ";
}
```

```cpp
vector<int> li;
t1.postorder_traversal(t1.root,li);
for(auto it = li.begin();it!=li.end();it++){
cout<<*it<<" ";
}
```

## Searching Elements

To check if an element is present in binary tree or not we can use

```cpp
Node* t = t1.search(36);
if(t){
    //36 is present in the tree
}
else{
    //36 is not present in the tree
}
```

The above will check if 36 is present in tree and returns an pointer to that node if present else return a NULL pointer.

## Comparing two trees

Let bst1, bst2 be 2 trees then we can compare those 2 trees are same or not by

```cpp
if(bst1.compare(bst2)){
    //both the trees are same
}
else{
    //both trees are not same
}
```