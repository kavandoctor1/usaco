import sys
fin = open("milkvisits.in", 'r')
fout = open("milkvisits.out", 'w')
n, m = map(int,fin.readline().strip().split())
gh = list(fin.readline().strip())
sys.setrecursionlimit(pow(10,9))
parent = [-1 for _ in range(n)]
depth = [-1 for _ in range(n)]
def dep(n):
    global parent,depth
    if(depth[n] > -1):
        return depth[n]
    if(parent[n] == -1):
        return 0
    depth[n] = 1 + dep(parent[n])
    return depth[n]
for _ in range(n-1):
    a,b = map(int,fin.readline().strip().split())
    a-=1;
    b-=1;
    if(parent[a] > -1):
        parent[b] = a
    else:
        parent[a] = b
depth = [dep(i) for i in range(n)]
ans = ""
for _  in range(m):
    x,y,breed = fin.readline().strip().split()
    works = False
    x= int(x)
    y = int(y)
    x -=1
    y-=1
    dx = depth[x]
    dy = depth[y]
    if(dx < dy):
        for _ in range(dy-dx):
            if(gh[y] == breed):
                works = True
                break
            y = parent[y]
    elif(dx > dy):
        for _ in range(dx-dy):
            if(gh[x] == breed):
                works = True
                break
            x = parent[x]
    if(gh[x] == breed or gh[y] == breed):
            works = True
    while(not works and x != y):
        x= parent[x]
        y = parent[y]
        if(gh[x] == breed or gh[y] == breed):
            works = True
    
    if(works): ans += "1"
    else: ans += "0"
fout.write(ans+"\n") 
    
    