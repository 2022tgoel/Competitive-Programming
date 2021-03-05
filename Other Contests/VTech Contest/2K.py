def offsetStr(s, o):
   ret = ""
   for c in s:
      c = chr((ord(c)-97 + o) % 26 + 97)
      ret += c
   return ret
offset = int(raw_input())
s = raw_input()
nsteps = int(raw_input())
goodsteps = 0
badsteps = 0
for x in range(nsteps):
   s = offsetStr(s, offset)
   vowels = s.count("a") + s.count("e") + s.count("i") + s.count("o") + s.count("u") + s.count("y")
   if vowels >= 0.5 * (len(s) - vowels):
      badsteps += 1
   else:
      goodsteps += 1
print(["Colleague", "Boris"][goodsteps > badsteps])