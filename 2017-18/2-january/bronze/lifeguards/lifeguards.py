def time(l):
    l.sort()
    work = [0 for _ in range(1000)]
    for interval in l:
        for i in range(interval[0],interval[1]):
            work[i] = 1
    return sum(work)
fin = open('lifeguards.in','r')
fout = open('lifeguards.out','w')
l = [list(map(int,fin.readline().strip().split())) for _ in range(int(fin.readline().strip()))]
maxm = 0
for i in range(len(l)):
    x = l.pop(i)
    maxm = max(time(list(l)),maxm)
    l.insert(i,x)
fout.write(str(maxm) + "\n")