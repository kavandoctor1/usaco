def moo(r):
    ret = r//3 + r//5 - r//15
    return ret
fin = open("moobuzz.in", 'r')
fout = open("moobuzz.out", 'w')
n = int(fin.readline().strip())
previous = 0
current = int(n)
while(current - moo(current) != n):
    x = current + moo(current) - moo(previous)
    previous = int(current)
    current = int(x)
fout.write(str(current)+"\n")