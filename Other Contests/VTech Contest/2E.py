count = int(raw_input())
tb = 0
lr = 0
for x in range(count):
   s = raw_input()
   tb += s[:2].count("0")
   lr += s[2:].count("0")
total = min(tb, lr)/2
tbleft = tb - total * 2
lrleft = lr - total * 2
print str(total) + " " + str(tbleft) + " " + str(lrleft)