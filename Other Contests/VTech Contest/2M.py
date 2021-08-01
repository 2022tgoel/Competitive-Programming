points = {}
ppl, minpoints, count = [int(x) for x in raw_input().split(" ")]
ppl = int(ppl)
winners = []
minpoints = int(minpoints)
count = int(count)
winnerCount = 0
for x in range(ppl):
   points[raw_input()] = 0
for x in range(count):
   inp = raw_input()
   #print(inp)
   name, pts = inp.split(" ")
   pts = int(pts)
   points[name] += pts
   if (name not in winners and points[name] >= minpoints):
      winners += [name]
      winnerCount += 1
      print(name + " wins!")
if (winnerCount == 0):
   print "No winner!"