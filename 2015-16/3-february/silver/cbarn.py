fin = open('cbarn.in', 'r')
fout = open('cbarn.out', 'w')
n = int(fin.readline().strip())
barn = list(map(int,fin.read().split()))
current = []
drops = []
for i in range(n):
    for _ in range(barn[i]):
        current.insert(0,0)
    if len(current) > 0:
        drops.append(current.pop())
    else:
        drops.append(-1)
    current = [x+1 for x in current]
i = 0
while len(current)>0:
    if(drops[i]!=-1):
        current.insert(0,drops[i])
    drops[i] = current.pop()
    current = [x+1 for x in current]
    i+=1
fout.write(str(sum([x*x for x in drops]))+"\n")
        