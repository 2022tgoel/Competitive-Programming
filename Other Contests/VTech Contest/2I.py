count = int(raw_input())
for x in range(count):
   blag = ""
   madeit = True
   for y in raw_input():
      if y == '$':
         blag = "$" + blag
      elif y == '|':
         blag = "|" + blag
      elif y == '*':
         blag = '*' + blag
      if y == 't':
         if len(blag) > 0 and blag[0] == '|':
            blag = blag[1:]
         else:
            print("NO")
            madeit = False
            break
      elif y == 'j':
         if len(blag) > 0 and blag[0] == '*':
            blag = blag[1:]

         else:
            print("NO")
            madeit = False
            break
      elif y == 'b':
         if len(blag) > 0 and blag[0] == '$':
            blag = blag[1:]
         else:
            print("NO")
            madeit = False
            break
   if(madeit):
      if len(blag) == 0:
         print("YES")
      else:
         print("NO")