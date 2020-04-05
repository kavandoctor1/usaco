fin = open("swap.in",'r')
fout = open("swap.out",'w')
n,k = map(int,fin.readline().strip().split())
a1,a2 = map(int,fin.readline().strip().split())
b1,b2 = map(int,fin.readline().strip().split())
if(a2 < b1):
    if(k%2==0):
        ans = range(1,n+1)
        
        
        