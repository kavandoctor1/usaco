def dfs(b1, b2, k,states,x,y, m):
    if k > m:
        return
    if [b1,b2] in states:
        return
    states.append([b1,b2])
    dfs(0,b2,k+1,states,x,y, m)
    dfs(b1,0,k+1,states,x,y, m)
    dfs(x,b2,k+1,states,x,y, m)
    dfs(b1,y, k+1,states,x,y, m)
    if b2 > (x-b1):
        dfs(x, b2+b1-x, k+1,states,x,y, m)
    else:
        dfs(b1+b2,0,k+1,states,x,y, m)
    if b1 > (y-b2):
        dfs(b1+b2-y, y, k+1,states,x,y, m)
    else:
        dfs(0,b1+b2,k+1,states,x,y, m)

fin = open ('pails.in', 'r')
fout = open ('pails.out', 'w')
x,y,k,m = map(int,fin.readline().strip().split())
states = []
dfs(0,0, 0, states,x,y,k)
arr = list(set([a[0]+a[1] for a in states]))
minm = abs(m-arr[0])
for it in arr:
    minm = min(minm, abs(m-it))
fout.write(str(minm) + "\n")


