import math
fin = open("race.in" , 'r')
fout = open("race.out" , 'w')
K, N = map(int,fin.readline().strip().split())
for _ in range(N):
    x = int(fin.readline().strip())
    k = int(K)
    if(x*(x+1)//2 >= k):
        ans = (-1 + math.sqrt(1+8*k))//2
        fout.write(str(int(ans)) + "\n")
        continue
    cur = int(x)
    t = 0
    while True:
        print(k, cur, t)
        if(cur*(cur-1)//2 >= k):
            ans = t + cur-1
            fout.write(str(ans)+"\n")
            break
        t+=1
        k -= cur
        cur += 1
    
            