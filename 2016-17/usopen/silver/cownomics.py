fin = open("cownomics.in", 'r')
fout = open("cownomics.out", 'w')
n,m = map(int, fin.readline().strip().split())
spotty = [fin.readline().strip() for _ in range(n)]
plain = [fin.readline().strip() for _ in range(n)]
ans = 0
for i in range(m):
    for j in range(i+1,m):
        for k in range(j+1,m):
            s = {a[i]+a[j]+a[k] for a in spotty}
            p = {a[i]+a[j]+a[k] for a in plain}
            if(len(s.intersection(p)) == 0):
                ans += 1
fout.write(str(ans)+"\n")