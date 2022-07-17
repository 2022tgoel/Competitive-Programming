cows = input()

open = 0
ans = 0
visited = [False]*26
for char in cows:
	if visited[ord(char)-ord('A')]:
		open-=1
		ans+=open
		print(char, open)
	else:
		visited[ord(char)-ord('A')] = True
		open+=1

print(ans)