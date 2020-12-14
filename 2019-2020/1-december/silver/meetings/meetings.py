fin = open("meetings.in", 'r')
fout = open("meetings.out", 'w')
n,l = map(int, fin.readline().strip().split())
poscows = []
negcows = []
dist = []
totw = 0
for _ in range(n):
    w, x, d = map(int, fin.readline().strip().split())
    totw += w
    if(d == 1):
        poscows.append(x)
        dist.append([l-x,w])
    else:
        dist.append([x,w])
        negcows.append(x)
dist.sort()
t = 0
i = 0
weight = 0
while weight*2 < totw:
    weight += dist[i][1]
    t = dist[i][0]
    i += 1

meets = 0
for cow in poscows:
    for ncow in negcows:
        if(ncow >= cow and ncow <= cow+2*t):
            meets+=1
fout.write(str(meets)+"\n")
