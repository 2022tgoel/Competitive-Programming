a, b = raw_input().split(" ")
a = int(a)
b = int(b)
bits = a ^ b
print(bin(bits).count("1"))