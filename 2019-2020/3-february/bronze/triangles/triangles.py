fin = open("triangles.in",'r')
fout = open("triangles.out",'w')
n = int(fin.readline().strip())
points = [list(map(int,fin.readline().strip().split())) for _ in range(n)]
ans = 0

for i in range(n):
    for j in range(i+1,n):
        for k in range(j+1,n):
            x = list(set([points[i][0], points[j][0], points[k][0]]))
            y = list(set([points[i][1], points[j][1], points[k][1]]))
            if(len(x) != 2 or len(y)!= 2):
                continue
            ans = max(ans, abs((x[0]-x[1])*(y[0]-y[1])))
fout.write(str(ans)+"\n")