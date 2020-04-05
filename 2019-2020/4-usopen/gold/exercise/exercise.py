def gcd(x, y): 
  
   while(y): 
       x, y = y, x % y 
  
   return x 
import math
fin = open("exercise.in", 'r')
fout = open("exercise.out",'w')

part = []
def partition(n):
    if(n == 1):
        return [1]
    ans = [n]
    for i in range(max(n//2,n-int(3*math.sqrt(n))), n):
        x = part[i-1]
        for c in x:
            ans.append(c*(n-i)//gcd(c,n-i))
    return list(set(ans))
    
N,M = map(int,fin.readline().strip().split())
for i in range(1,N):
    x = partition(i)
    part.append(x)

fout.write(str(sum(partition(N))%M) + "\n")
    