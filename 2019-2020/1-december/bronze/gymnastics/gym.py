fin = open("gymnastics.in",'r')
fout = open("gymnastics.out", 'w')
k, n = map(int,fin.readline().strip().split())
rounds = []
for _ in range(k):
    rounds.append(list(map(int,fin.readline().strip().split())))
print(rounds)
pairs =0 
for i in range(1,n+1):
    for j in range(1,n+1):
        if i==j: continue
        works = True
        for r in rounds:
            if(r.index(i) < r.index(j)):
                works = False
                break
        if(works): pairs += 1
fout.write(str(pairs) + "\n")