count = int(raw_input())
bowlsizes = map(int, raw_input().split(" "))
bowlsizes.sort()
mn = 1000000
counts = [int(raw_input()) for x in range(count)]
counts.sort()
for x in range(count):
   mn = min(mn, bowlsizes[x] / float(counts[x]))
print(mn)