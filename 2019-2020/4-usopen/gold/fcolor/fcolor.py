fin = open("fcolor.in", 'r')
fout = open("fcolor.out",'w')

N,M = map(int,fin.readline().strip().split())
edges = [ [] for _ in range(N)]
for _ in range(M):
    a,b = map(int,fin.readline().strip().split())
    edges[a-1].append(b-1)
val = [i for i in range(N)]
for s in edges:
    x = min(s)
    for c in s:
        val[c] = min(x,val[c]) 
for s in edges:
    for i in range(len(s)):
        s[i] = val[s[i]]
    s = list(set(s))
    x = min(s)
    for c in s:
        val[c] = min(x,val[c])
print(edges)
        