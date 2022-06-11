# Comparison-between-Different-ADTs
This code does a comparative analysis of several ADTs. It calculates the average time taken by CRUD operations of ADTs and saves it in seperate CSV files.

This code empirically evaluates the performance of different ADTs which I have implemented during
the Data Structures course. You will use the following 11 ADTs.
  1. Linked list (unsorted)
  2. Linked list (sorted)
  3. List (list) in STL
  4. Binary Search Tree
  5. Binary Search Tree/Red-Black-Tree (map) in STL
  6. Hash table with chaining and multiplication method
  7. Hash table with chaining and division method
  8. Hash table with open addressing and linear probing
  9. Hash table with open addressing and quadratic probing
  10. Hash table with open addressing and double hashing probing
  11. Hash table (unordered_map) in STL


std::shuffle function (http://www.cplusplus.com/reference/algorithm/shuffle/).

chrono: (http://www.cplusplus.com/reference/chrono/steady_clock/ ) for measuring the execution time.
Same numbers are used for all the ADTs:
  1. Insert
  2. Delete (random 10,000 elements which exist in the array)
  3. Search (random 10,000 elements which do not existing in the array).
  4. Search (random 10,000 elements which exist in the array)
