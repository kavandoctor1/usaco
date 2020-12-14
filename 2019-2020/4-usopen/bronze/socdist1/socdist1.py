fin = open("socdist1.in", 'r')
fout = open("socdist1.out", 'w')
N = int(fin.readline().strip())
s = fin.readline().strip().split("1")
a,b = len(s.pop()),len(s.pop(0))
l = [len(st) for st in s]
l.sort()
x = l.pop()
if(a > x):
    l.append(x)
    x = int(a)
    a = 0
if(b > x):
    l.append(x)
    x = int(b)
    b = 0
if(x%2):
    l.append((x-1)//2)
    l.append((x-1)//2)
else:
    l.append((x-1)//2)
    l.append((x-1)//2 + 1)
l.sort()
x = l.pop()
if(a > x):
    l.append(x)
    x = int(a)
    a = 0
if(b > x):
    l.append(x)
    x = int(b)
    b = 0
if(x%2):
    l.append((x-1)//2)
    l.append((x-1)//2)
else:
    l.append((x-1)//2)
    l.append((x-1)//2 + 1)
fout.write(str(min(l) +1) + "\n")