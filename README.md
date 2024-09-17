<<<<<<< HEAD
Mode    | Size       | Elapsed Time 
--------|------------|--------------
STL     | 10         | 0.00s
STL     | 100        | 0.00s
STL     | 1000       | 0.00s
STL     | 10000      | 0.01s
STL     | 100000     | 0.06s
STL     | 1000000    | 0.94s
STL     | 10000000   | 11.92s
QSORT   | 10         | 0.00s
QSORT   | 100        | 0.00s
QSORT   | 1000       | 0.00s
QSORT   | 10000      | 0.01s
QSORT   | 100000     | 0.07s
QSORT   | 1000000    | 0.76s
QSORT   | 10000000   | 7.96s
MERGE   | 10         | 0.00s
MERGE   | 100        | 0.00s
MERGE   | 1000       | 0.00s
MERGE   | 10000      | 0.01s
MERGE   | 100000     | 0.08s
MERGE   | 1000000    | 0.76s
MERGE   | 10000000   | 9.55s
QUICK   | 10         | 0.00s
QUICK   | 100        | 0.00s
QUICK   | 1000       | 0.00s
QUICK   | 10000      | 0.01s
QUICK   | 100000     | 0.47s
QUICK   | 1000000    | 69.33s
QUICK   | 10000000   | 897.34s
=======
Mode | Size | Elapsed Time 
--- | --- | ---
STL | 10 | 0.00s
STL | 100 | 0.00s 
STL | 1000 | 0.00s
STL | 10000 | 0.01s 
STL | 100000 | 0.06s
STL | 1000000 | 0.94s
STL | 10000000 | 11.92s 
QSORT | 10 | 0.00s 
QSORT | 100 | 0.00s
QSORT | 1000 | 0.00s 
QSORT | 10000 | 0.01s
QSORT | 100000 | 0.07s
QSORT | 1000000 | 0.76s 
QSORT | 10000000 | 7.96s
MERGE | 10 | 0.00s
MERGE | 100 | 0.00s
MERGE | 1000 | 0.00s
MERGE | 10000 | 0.01s
MERGE | 100000 | 0.08s
MERGE | 1000000 | 0.76s
MERGE | 10000000 | 9.55s 
QUICK | 10 | 0.00s
QUICK | 100 | 0.00s
QUICK | 1000 | 0.00s
QUICK | 10000 | 0.01s
QUICK | 100000 | 0.47s
QUICK | 1000000 | 69.33s
QUICK | 10000000 | 897.34s
>>>>>>> dfb1202403a2b9c8fa1185ca4d5d4ea8d9f85e70




# Performance
STL sort shows good performance with little time up to around 100k size, but then slows down. For very large inputs it
is relatively slow compared to some other methods. Like STL sort, Qsort performs well with small inputs, but as size increases it still slightly outperforms STL in terms of the time it takes for large inputs such as 1 million. Merge sort maintains consistent performance but then lags when it hits the 10 million mark, but is comparable
in time to Qsort. While Quick Sort performs well for small sizes, it is incredibly slow for large input sizes, taking minutes at the 10 million element mark.

# Theoretical Complexity 
STL - O(nlogn), maintains good performance eve with large inputs
Qsort - O(nlogn), results show that it maintains efficiency across sizes, similar to STL but has an edge when it comes to large inputs
Merge - O(nlogn), maintains good performance across input sizes and can handle large sets without risk of poor performance seen in Quick Sort's worst case
Quick - Usually has O(nlogn) but can be O(n^2) in worst case, which happened for the larger inputs, making it super slow
# Which is best
Qsort, seemed to consistently outperform or match all other methods besidesone instance of STL (most likely a fluke) regardless of size

# Contributions
Eric worked on a portion of merge.cpp and completed stl.cpp. Ethan completed qsort.cpp. Alex finished remaining portion of merge.cpp and completed the 3 questions relating to performance. William did quick.cpp and recorded all the times for each sorting method.
## GITHUB link 
[Project-2 Link](https://github.com/ericcht/Project-2)

# Contributers

## Eric Chtilianov

## Ethan Dietrich

## Alex Chen

## William Armentrout

