from itertools import permutations
fin = open("lineup.in", 'r')
fout = open("lineup.out", 'w')
n = int(fin.readline().strip())
cows = ['Beatrice', 'Belinda', 'Bella', 'Bessie', 'Betsy', 'Blue', 'Buttercup', 'Sue']
pairs = []
for _ in range(n):
    word = fin.readline().strip().split()
    a = word[0]
    b = word[-1]
    if(a > b):
        a,b=b,a
    pairs.append([a,b])
for p in permutations(cows):
    works = True
    for pair in pairs:
        if(abs(p.index(pair[0]) - p.index(pair[1])) > 1):
            works = False
            break
    if(works):
        for cow in p:
            fout.write(cow+"\n")
        break
            
# ans = []
# i = 0
# while len(left) > 0:
#     l = beside[i]
#     if(not cows[i] in left):
#         i += 1
#         continue
#     left.remove(cows[i])
#     for it in l:
#         left.remove(it)
#     if(len(l) == 0):
#         ans.append([cows[i]])
#     elif(len(l) == 1):
#         ans.append([cows[i],l[0]])
#     else:
#         ans.append([min(l[0],l[1]),cows[i],max(l[0],l[1])])
#     i+=1
# ans.sort()
# for c in ans:
#     for cow in c:
#         fout.write(cow+"\n")

        