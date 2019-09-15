import math

fin = open("lostcow.in", 'r')
fout = open("lostcow.out",'w')
x,y=map(int,fin.readline().strip().split())
y -= x
a = int(math.log(abs(y),2))
if y < 0:
    a += (a%2-1)
else:
    a -=(a%2)
ans = 2*(pow(2,a+2)-1)+abs(y)
fout.write(str(ans)+"\n")
