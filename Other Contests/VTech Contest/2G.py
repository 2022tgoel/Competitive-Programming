count = int(raw_input())
yards = 20
plays = map(int, raw_input().split(" "))
lastdownturn = 0
lastdownyards= 20
for n in range(count):
   yards += plays[n]
   if (yards >= lastdownyards + 10):
      lastdownturn = n
      lastdownyards = yards
   elif (n >= lastdownturn + 4):
      print("Nothing")
      exit()
   if (yards >= 100):
      print("Touchdown")
      exit()
   elif (yards <= 0):
      print("Safety")
      exit()
print("Nothing")