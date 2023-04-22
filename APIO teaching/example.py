# n = 10 # int variable 

# print(type(n))

# def square(n):
#     return n*n

# s = "jfoeifr"
# print(type(s))

# print(type(square))

# def increment(): # doesn't return anything 
#     global i
#     i+=1 # consider this to be a 'void' return type in c++

# i = 1
# while i < 10:
#     print(square(i))
#     increment()

# print(square(4.5))

# n+=1
# n=n+1

# import os 

# from os import * 

# print(listdir())

# def listdir():
#     return "hi"

# print(listdir())

# two functions with the same name
# module.function to specify which version of the function we are actually using 

s = "hello"
s = ['h', 'e', 'l', 'l', 'o']
'''
h
he
hel
hell
hello
'''

i = 1
while i <= len(s):
    print(s[0:i])
    i+=1


# import os
# import sys
# import 
# import 
# import ...

# 1+2+3+4+...n

sum = 0
for i in range(10):
    sum+=i

def recursive_sum(n):
    # sum of the numbers 1..n is the sum of the numbers 1..n-1 + n 
    if (n == 0):
        return 0
    return recursive_sum(n-1) + n 

# s is rcursive_sum
# s(5) = 10 + 5
# s(4) = 6 + 4 = 10
# s(3) = 3 + 3 = 6
# s(2) = 1 + 2 = 3
# s(1) = 0 + 1 = 1

print(recursive_sum(4))

# 1, 1, 2, 3, 5, 8, 13, 21, 34, 55...

# a(n) = a(n-1) + a(n-2)

def a(n):
    if (n == 1 or n==2):
        return 1
    return a(n-1) + a(n-2)

print(a(6))
print(a(10))

b = True

def f(n):
    if (n == 1):
        return 1
    return n*g(n-1)

def g(n):
    if (n == 1):
        return 2
    return n*f(n-1)

print(f(4))

arr = [1, 3, 5, 7]
arr.append(5)