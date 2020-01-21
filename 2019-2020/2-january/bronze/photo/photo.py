fin = open("photo.in", 'r')
fout = open("photo.out" , 'w')
N = int(fin.readline().strip())
b = list(map(int,fin.readline().strip().split()))
for first in range(1,N+1):
    a = [first]
    works = True
    for x in b:
        nxt = x-a[-1]
        a.append(nxt)
        if(nxt < 1):
            works = False
            break
    if(works):
        if(len(set(a)) == len(a)):
            fout.write(" ".join(map(str,a)))
            break
