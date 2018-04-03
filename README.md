Max Heap
========

Max sort implementation in C++.

How it works
------------

Data is held in an array where the indexes are mapped to other indexes to form a binary tree. 

```
   ...................................
   | 89 | 45 | 33 | 14 | 21 | 8 | 10 |
   '''''''''''''''''''''''''''''''''''
     |        / \ right      / \ left 
     |         |              |
     \......../               |
     2 * 0 + 2 |              |
         |      \............/
   index of 18     2 * 2 + 1
                       |
                   index of 33
                  
```
index of left child = 2 * (index of parent) + 1  
index of right child = 2 * (index of parent) + 2

Visually (in node form) it looks a bit like this:
```
               89
             /    \
           45      33
          /  \    /  \
         14  21  8   10
```
