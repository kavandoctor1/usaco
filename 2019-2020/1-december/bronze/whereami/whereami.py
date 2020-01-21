fin = open("whereami.in", 'r')
fout = open("whereami.out", 'w')
n = int(fin.readline().strip())
s = fin.readline().strip()
ways = [[s[i:i+k] for i in range(n-k+1)]for k in range(1,n)]
ans = 0
for l in ways:
    if(len(set(l)) == len(l)):
        ans = len(l[0])
        break
fout.write(str(ans) + "\n")