fin = open('reduce.in', 'r')
fout = open('reduce.out', 'w')
n = int(fin.readline().strip())
x = []
y = []
for _ in range(n):
    x1,y1 = map(int,fin.readline().strip().split())
    x.append(x1)
    y.append(y1)
x1,x2,x3,x4=list(x),list(x),list(x),list(x)
y1,y2,y3,y4=list(y),list(y),list(y),list(y)
minm = pow(10,100)
#1
i = x1.index(max(x1))
x1.pop(i)
y1.pop(i)
minm = min(minm,(max(x1)-min(x1))*(max(y1)-min(y1)))
#2
i = x2.index(min(x2))
x2.pop(i)
y2.pop(i)
minm = min(minm,(max(x2)-min(x2))*(max(y2)-min(y2)))
#3
i = y3.index(max(y3))
x3.pop(i)
y3.pop(i)
minm = min(minm,(max(x3)-min(x3))*(max(y3)-min(y3)))
#4
i = y4.index(min(y4))
x4.pop(i)
y4.pop(i)
minm = min(minm,(max(x4)-min(x4))*(max(y4)-min(y4)))
fout.write(str(minm)+"\n")