"""
Technicians store:
Which one they're working on, what time they started
"""
storesum = 0
storecount = 0
remotesum = 0
remotecount = 0
class Technician:
   def __init__(self):
      self.time = 0
   def nextTask(self, storetasks, remotetasks):
      timeIn, inStore, length = getNextTask(storetasks, remotetasks, self.time)
      #print(timeIn, inStore, length)
      self.time = max(self.time, timeIn)
      global storesum, storecount, remotesum, remotecount
      if inStore:
         storesum += self.time + length - timeIn
         storecount += 1
         storetasks.remove((timeIn, inStore, length))
         self.time = self.time + length
      else:
         remotesum += self.time + length - timeIn
         remotecount += 1
         remotetasks.remove((timeIn, inStore, length))
         self.time = self.time + length
      
def getNextTask(storetasks, remotetasks, time):####################################################################### <--- SAVE HERE >:( O(n2)
   inStore = []
   if len(storetasks) == 0:
      return best(remotetasks)
   elif len(remotetasks) == 0:
      return best(storetasks)
   if storetasks[0][0] > time and remotetasks[0][0] > storetasks[0][0]:
      return best(storetasks)
   if remotetasks[0][0] <= time and storetasks[0][0] > time:
      return best(remotetasks)
   if remotetasks[0][0] > time and storetasks[0][0] > remotetasks[0][0]:
      return best(remotetasks)
   if (compare(best(storetasks), best(remotetasks)) == 1):
      return best(storetasks)
   else:
      return best(remotetasks)
def best(tasks):
   best = tasks[0]
   for task in tasks:
      if task[0] > best[0]:
         break
      if task[2] < best[2]:
         best = task
   return best
      
def compare(task1, task2):
   if task1[1] > task2[1]:
      return 1
   elif task1[1] < task2[1]:
      return -1
   else:
      if task1[0] < task2[0]:
         return 1
      elif task1[0] > task2[0]:
         return -1
      else:
         if task1[2] < task2[2]:
            return 1
         elif task1[2] > task2[2]:
            return -1
         else:
            return 0
timer = 0
stack = []
presc, techn = [int(x) for x in raw_input().split(" ")]
storetasks = []
remotetasks = []
for x in range(presc):
   timeIn, inStore, length = raw_input().split(" ")
   timeIn = int(timeIn)
   inStore = 1 if inStore == 'S' else 0
   length = int(length)
   if inStore == 1:
      storetasks.append((timeIn, inStore, length))
   elif inStore == 0:
      remotetasks.append((timeIn, inStore, length))
blags = [Technician() for x in range(techn)]
while (len(storetasks) + len(remotetasks)) > 0:#print(tasks)
   mintech = blags[0]
   for tech in blags:
      if tech.time < mintech.time:
         mintech = tech
   mintech.nextTask(storetasks, remotetasks)
storea = 0
remotea = 0
if storecount > 0:
   storea = float(storesum) / storecount
if remotecount > 0:
   remotea = float(remotesum) / remotecount;
print(str(storea) + " " + str(remotea))