card = raw_input()
hand = raw_input().split(" ")

for c in hand:
   if c[0] == card[0] or c[1] == card[1]:
      print "YES"
      exit()
      
print "NO"