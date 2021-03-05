import copy
count = int(raw_input())
rooms = {}
inp = map(int, raw_input().split(" "))
for x in range(len(inp)):
   rooms[x] = inp[x]

toTestCount = raw_input()
toTestPipes = [int(x) for x in raw_input().split(" ")]
pipes = copy.deepcopy(rooms)
for n in rooms:
   if rooms[n] in pipes: 
      del pipes[rooms[n]]
pipelength = {}
coinrooms = []
bestPepe = {} # [coinroom -> optimal pipe]
coinroomsFromPipes = {}
for node in pipes:
   origNode = node
   pipelength[origNode] = 0
   while rooms[node] != -1:
      node = rooms[node]
      pipelength[origNode] += 1
   if node not in bestPepe:
      bestPepe[node] = origNode
   elif pipelength[origNode] < pipelength[bestPepe[node]]:
      bestPepe[node] = origNode
   coinroomsFromPipes[origNode] = node
for p in toTestPipes:
   c = coinroomsFromPipes[p]
   coinrooms.append(c)
"""print(pipelength)
print(coinrooms)
#print(pipesToCoinrooms)
print(coinroomsFromPipes)"""
for room in coinrooms:
   print(bestPepe[room])