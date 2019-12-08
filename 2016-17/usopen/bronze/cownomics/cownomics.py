fin = open("cownomics.in", "r")
fout = open("cownomics.out","w")
n,m = map(int,fin.readline().strip().split())
ans = 0
spot = []
none = []
for _ in range(n):
    spot.append(fin.readline().strip())
for _ in range(n):
    none.append(fin.readline().strip())
for i in range(m):
    a = set([x[i] for x in spot])
    b = set([x[i] for x in none])
    add = True
    for c in a:
        if c in b:
            add = False
    if add:
        ans+=1
fout.write(str(ans)+"\n")