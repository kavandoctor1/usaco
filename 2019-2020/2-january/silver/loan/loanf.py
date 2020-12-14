import math
fin = open('loan.in', 'r')
fout = open('loan.out', 'w')
N,K,M = map(int, fin.readline().strip().split())
left = 1
right = int(K)
while right - left > 0:
    x = math.ceil((left+right)/2)
    k = math.ceil(math.log(M*x/N) / math.log((x-1)/x))
    if pow(x-1,k)* math.ceil(N/pow(x, k)) -M*(K-k) <= 0 :
        left = x
    else:
        right = x-1
fout.write(str(left) + "\n")