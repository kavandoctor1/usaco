fin = open("bcount.in" , 'r')
fout = open("bcount.out", 'w')
n,q = map(int,fin.readline().strip().split())
cows = [[0] for _ in range(3)]
for _ in range(n):
    x = int(fin.readline().strip())
    for i in range(3): cows[i].append(cows[i][-1])
    cows[x-1][-1] += 1
print(cows)
for _ in range(q):
    a,b = map(int,fin.readline().strip().split())
    fout.write(str(cows[0][b]-cows[0][a-1]))
    for ar in cows[1:]:
        fout.write(" " + str(ar[b]-ar[a-1]))
    fout.write("\n")