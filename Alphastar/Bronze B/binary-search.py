''' Problem statement 
Binary Search
=============

Implement a binary search algorithm that returns the index of the
first occurrence of a number K, or -1 if it could not be found. You
will be supplied with a (sorted) list of N numbers (0 <= N <= 100,000).

For example, suppose you were given the following (sorted) array as
input.

2 3 4 4 9 11 12

Searching for 4 should return 2, searching for 9 should return 4, and
searching for 10 should return -1.

You will be asked to answer Q queries (1 <= Q <= 100,000), each of which
is a single number and should be answered as stated above.

PROBLEM NAME: binarysearch

INPUT FORMAT:

* Line 1: Two integers, N and Q.

* Line 2: N sorted integers. 

* Lines 3..Q+2: A single integer K on each line, representing a query.

SAMPLE INPUT:

7 2
2 3 4 4 9 11 12
9
10

7 3
2 5 7 9 9 9 10
6
9
6

OUTPUT FORMAT:

* Lines 1..Q: The index of the first occurrence of K in the supplied array,
        or -1 if not found.

SAMPLE OUTPUT:

4
-1

OUTPUT DETAILS:

The index of 9 is 4, and 10 is not in the array so the function returns -1.
'''

# method 1 - using [0, N) as your range
'''
N, Q = [int(x) for x in input().split()]

arr = [int(x) for x in input().split()]

for i in range(Q):
        num = int(input())
        lo = 0
        hi = N # [0, N)
        while (lo < hi-1):
                mid = int((lo+hi-1)/2)
                if (arr[mid] < num):
                        lo = mid+1
                else:
                        hi = mid+1
        # arr[lo] is the largest number less that or equal to num
        if (arr[lo] == num):
                print(lo)
        else:
                print(-1)
'''

# method 2 lower bound does not work - can you debug this? 
'''
N, Q = [int(x) for x in input().split()]

arr = [int(x) for x in input().split()]

for i in range(Q):
        num = int(input())
        lo = 0
        hi = N-1 # [0, N-1]
        while (lo < hi):
                mid = int((lo+hi)/2)
                if (arr[mid] <= num):
                        lo = mid
                else:
                        hi = mid 
        # arr[lo] is the largest number less that or equal to num
        if (arr[lo] == num):
                print(lo)
        else:
                print(-1)
'''

# method 2 lower bound
'''
N, Q = [int(x) for x in input().split()]

arr = [int(x) for x in input().split()]

for i in range(Q):
        num = int(input())
        lo = 0
        hi = N-1 # [0, N-1]
        while (lo < hi):
                mid = int((lo+hi)/2)
                if (arr[mid] < num):
                        lo = mid+1 
                else:
                        hi = mid 
        # arr[lo] is the largest number less that or equal to num
        if (arr[lo] == num):
                print(lo)
        else:
                print(-1)
'''

# method 3 upper bound
N, Q = [int(x) for x in input().split()]

arr = [int(x) for x in input().split()]

for i in range(Q):
        num = int(input())
        lo = 0
        hi = N-1 # [0, N-1]
        while (lo < hi):
                mid = int((lo+hi)/2)
                if (arr[mid] <= num):
                        lo = mid+1 
                else:
                        hi = mid 
        # arr[lo] is the smallest number greater than num
        if (arr[lo-1] == num):
                print(lo-1)
        else:
                print(-1)