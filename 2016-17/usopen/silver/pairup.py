fin = open("pairup.in", 'r')
fout = open("pairup.out",'w')
cows = []
n = int(fin.readline().strip())
for _ in range(n):
    a,b = map(int,fin.readline().strip().split())
    cows.append([b,a])
cows.sort()
maxm = 0
while len(cows) > 0:
    maxm = max(maxm, cows[0][0] + cows[-1][0])
    if(cows[0][1] > cows[-1][1]):
        cows[0][1] -= cows[-1][1]
        cows.pop()
    elif(cows[0][1] < cows[-1][1]):
        cows[-1][1] -= cows[0][1]
        cows.pop(0)
    else:
        cows.pop(0)
        if(len(cows) > 0):
            cows.pop()
fout.write(str(maxm)+"\n")
    